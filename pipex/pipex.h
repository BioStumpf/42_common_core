#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/wait.h>

# define RDEND data.pipe_fd[0] 
# define WREND data.pipe_fd[1]
# define STDIN 0
# define STDOUT 1
# define INPUT av[1]
# define OUTPUT av[ac - 1]

struct s_dat
{
	int		pipe_fd[2];
	int		pid;
	char	**path_split;
	char	**program_av;
	char	*program_path;
};

#endif
