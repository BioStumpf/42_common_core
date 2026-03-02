#include "pipex.h"

	//open input file
	//create a first pipe (parent -> child)
	//create a second pipe (child -> parent)
	//write the fd contents into the first pipe (use fd_list[1])
	//loop throught ac - 3 (-1 for each ./pipex; file1; file2 in between are the commands)
		//create child with fork()
		//dup2 to relink the stdin to the pipes read end of first pipe(this fd change wont be wiped by execv, process fd table remains)
		//dup2 to relink the stdout to the pipes write end of second pipe (to make the process write to the child->parent communication pipe)
		//execve to initiate programm that should run inside child (add avs from behind argument, need parsing string)
		//make parent process wait for child to finish
		//if child done, in main process copy content from second pipe into first pipe (which should be empty)
	//after loop, copy everything from child->parent pipe into output file
//
static void cleanup(int *fd_in, int *fd_out, int pipe_fd[2])
{
	if (*fd_in != -1)
		close(*fd_int);
	if (*fd_out != -1)
		close(*fd_out);
	if (*pipe_fd[0] != -1)
	{
		close(*pipe_fd[0]);
		close(pipe_fd[1]);
	}
	exit(1);
}

static int	open_files(int *fd_in, int *fd_out)
{
	*fd_in = open(av[1], O_RDONLY);
	*fd_out = open(av[ac - 1], O_WRONLY | O_CREAT);
	if (*fd_in == -1 || *fd_out == -1)
		return (-1);
	return (0);
}

static int	copy(int fd_in, int fd_out)
{
	int		bytes_read;
	char	buff[BUFF_S];

	while (true)
	{
		bytes_read = read(fd_in, buff, BUFF_S);
		if (bytes_read == 0)
			return (0);
		if (bytes_read == -1)
			return (-1);
		if (write(fd_out, buff, BUFF_S) == -1)
			return (-1);
	}
}

int main(int ac, char **av)
{
	int	fd_in;
	int	fd_out;
	int	pipe_fd[2];

	if (ac < 5)
	{
		write(2, "Invalid number of arguments\n", 29);
		return (1);
	}
	if (open_files(&fd_in, &fd_out) == -1)
		cleanup(fd_in, fd_out, pipe_fd);
	pipe_fd[0] = -1;
	if (pipe(pipefd) == -1)
		cleanup(fd_in, fd_out, pipe_fd);
	if (copy(fd_in, pipe_fd[1]) == -1)
		cleanup(fd_in, fd_out, pipe_fd);
} 
