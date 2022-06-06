#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    int fd = STDIN_FILENO;
    char* line = NULL;
	int ret = 0;

    if (argc >= 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            printf("Failed to open input file \"%s\"\n", argv[1]);
            return 1;
        }
    }

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }

    if (ret == -1)
    {
        printf("Error in get_next_line()\n");
        return 1;
    }

    return 0;
}