#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	char	*res;
	size_t	counter = 0;

	int fd = open("testfile", O_RDONLY);	
	while (counter < 15)
	{
		res = get_next_line(fd);
		printf("%s", res);
		counter++;
	}
	close(fd);
}
