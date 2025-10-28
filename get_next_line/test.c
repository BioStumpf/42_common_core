//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	char	*res;
	char	*res2;

	int fd = open("testfile", O_RDONLY);	
	int fd2 = open("testfile2", O_RDONLY);
	res = get_next_line(fd);
	printf("1%s", res);
	free(res);
	printf("\n");
	res2 = get_next_line(fd2);
	printf("2%s", res2);
	free(res2);
	while ((res = get_next_line(fd)))
	{
		printf("1%s", res);
		free(res);
	}
	while ((res2 = get_next_line(fd2)))
	{
		printf("2%s", res2);
		free(res2);
	}
	close(fd);
	close(fd2);
}
