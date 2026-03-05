#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

static void	cleanup(struct s_dat *data, int status)
{
	if (data->pipe_fd[0] != -1)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] != -1)
		close(data->pipe_fd[1]);
	if (data->path_split)
		free_split(data->path_split);
	if (data->program_path)
		free(data->program_path);
	if (data->program_av)
		free_split(data->program_av);
	exit (status);
}

static void	check_args(int ac)
{
	if (ac < 5)
	{
		write(2, "Invalid number of arguments\n", 29);
		exit(1);
	}
}

static char	*find_path(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

static void	split_path(struct s_dat *data, char **envp)
{
	char *path;

	path = find_path(envp);
	data->path_split = ft_split(path, ':');
	if (!data->path_split)
		cleanup(data, 1);
}

static void	init_dat(struct s_dat *data)
{
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->path_split = NULL;
	data->program_av = NULL;
	data->program_path = NULL;
}

static void	get_program_path(struct s_dat *data, char *program)
{
	size_t	i;

	i = 0;
	while (data->path_split[i])
	{
		data->program_path = ft_pathjoin(data->path_split[i], program);
		if (!data->program_path)
			cleanup(data, 1);
		if (access(data->program_path, X_OK) == 0)
			return ;
		free(data->program_path);
		data->program_path = NULL;
		i++;
	}
	cleanup(data, 1);
}

static void	clean_process(struct s_dat *data)
{
	free(data->program_path);
	data->program_path = NULL;
	free_split(data->program_av);
	data->program_av = NULL;
}

static void	close_pipe(struct s_dat *data)
{
	if (data->pipe_fd[0] != -1)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] != -1)
		close(data->pipe_fd[1]);
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
}

static void	get_program_av(struct s_dat *data, char *arg)
{
	data->program_av = ft_split(arg, ' ');
	if (!data->program_av)
		cleanup(data, 1);
}

static void	open_file(struct s_dat *data, int *fd, char *file, int flags)
{
	if (flags & O_WRONLY)
		*fd = open(file, flags, 0644);
	else
		*fd = open(file, flags);
	if (*fd == -1)
		cleanup(data, 1);
}

//#include <signal.h>
int main(int ac, char **av, char **envp)
{
	struct s_dat	data;
	int				i;

	init_dat(&data);
	check_args(ac);
	split_path(&data, envp);
	open_file(&data, &RDEND, INPUT, O_RDONLY);
	i = 1;
	while (++i <= ac - 2)
	{
		get_program_av(&data, av[i]);
		get_program_path(&data, data.program_av[0]);
		if (dup2(RDEND, STDIN) == -1)
			cleanup(&data, 1);
		close_pipe(&data);
		if (i == ac - 2)
			open_file(&data, &WREND, OUTPUT, O_WRONLY | O_CREAT | O_TRUNC);
		else
			pipe(data.pipe_fd); 
		data.pid = fork(); 
		if (data.pid == -1)
			cleanup(&data, 1);
		if (data.pid == 0)
		{
		//	raise(SIGSTOP);
			if (dup2(WREND, STDOUT) == -1) 
				cleanup(&data, 1);
			close_pipe(&data);
			execve(data.program_path, data.program_av, envp); 
			cleanup(&data, 1);
		}
		clean_process(&data);
	}
	waitpid(data.pid, NULL, 0); 
	cleanup(&data, 0);
} 
