#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	char	*res;

//	int fd = open("testfile", O_RDONLY);	
	while ((res = get_next_line(100)))
	{
		printf(": %s", res);
		free(res);
	}
//	close(fd);
}
