#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

static void	cleanup(struct s_dat *data, int status)
{
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
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

static void	check_args_init_inpt(struct s_dat *data, int ac, char **av)
{
	if (ac < 5)
	{
		write(2, "Invalid number of arguments\n", 29);
		exit(1);
	}
	data->fd_in = open(av[1], O_RDONLY);
	if (data->fd_in == -1)
		cleanup(data, 1);
	data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == -1)
		cleanup(data, 1);
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
	data->fd_in = -1;
	data->fd_out = -1;
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
	close(data->pipe_fd[0]);
	data->pipe_fd[0] = -1;
	close(data->pipe_fd[1]);
	data->pipe_fd[1] = -1;
	free(data->program_path);
	data->program_path = NULL;
	free_split(data->program_av);
	data->program_av = NULL;
}

static void	get_program_av(struct s_dat *data, char *arg)
{
	data->program_av = ft_split(arg, ' ');
	if (!data->program_av)
		cleanup(data, 1);
}

int main(int ac, char **av, char **envp)
{
	struct s_dat	data;
	int				i;

	init_dat(&data);
	check_args_init_inpt(&data, ac, av);
	split_path(&data, envp);
	if (dup2(data.fd_in, STDIN) == -1)
		cleanup(&data, 1);
	i = 1;
	while (++i < ac - 1)
	{
		get_program_av(&data, av[i]);
		//int j = 0;
		//while (data.program_av[j])
		//	ft_printf("%s; ", data.program_av[j++]);
		get_program_path(&data, data.program_av[0]);
		//ft_printf("\n%s\n", data.program_path);
		pipe(data.pipe_fd); 
		data.pid = fork(); 
		if (data.pid == 0)
		{
			if (i == ac - 1)
				dup2(data.fd_out, STDOUT);
			else
				dup2(WREND, STDOUT); 
			close(RDEND);
			close(WREND);
			execve(data.program_path, data.program_av, envp); 
			cleanup(&data, 1);
		}
		dup2(RDEND, STDIN); 
		clean_process(&data);
	}
	waitpid(data.pid, NULL, 0); 
	cleanup(&data, 0);
} 
