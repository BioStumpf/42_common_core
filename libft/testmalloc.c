#include <stdlib.h>
#include <stdio.h>

void *test_malloc(size_t size)
{
    static int count = 0;
    count++;

    if (count == 3)
    {
        printf("Simulated malloc failure!\n");
        return NULL;
    }
    return malloc(size);
}
