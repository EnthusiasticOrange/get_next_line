# Get Next Line

## Description
The aim of this project is to code a function that returns a line ending with a newline, read from a file descriptor.

For more detais about this project refer to [**`the subject`**](en.subject.pdf).

## Usage
To use `gnl` simply include project header and call the `get_next_line()` function in a loop as shown below:

```C
#include "get_next_line.h"

...
while (get_next_line(fd, &line) > 0)
{
    ...
    free(line);
}

...
```

During compilation you have to provide `BUFFER_SIZE` flag to set the size of internal buffer.

There is also a simple example [**`main.c`**](srcs/main.c) file, which demonstrates `gnl` usage. You can compile it with the following commands:
```shell
$ cd srcs/
$ gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=10
```
This example tries to open and read from a file, which name is provided as first argument, or can read from `STDIN` if no arguments were provided.
