#include "pipex.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac < 5)
	{
		write(2, "Invalid number of arguments\n", 29);
		return (1);
	}
} 
