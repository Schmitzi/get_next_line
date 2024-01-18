<p align="center">
    <img src="img/get_next_linee.png"/>
</p>

<h1 align="center">
   get_net_line
</h1>

<p align="center">
    <img src="https://img.shields.io/badge/language-%20C-blue" />
    <img src="https://img.shields.io/badge/100%2F100-green" />
</p>
## Description
`get_next_line` is a function in C designed to read a line from a file descriptor. It is part of the curriculum at 42, providing a fundamental understanding of file descriptors and dynamic memory allocation.

## Features
- Reads a line from a file descriptor.
- Handles multiple file descriptors simultaneously.
- Manages dynamic memory allocation to handle lines of arbitrary length.

## Usage
### Compilation
To compile the `get_next_line` function, you can use the provided Makefile. Simply run:

```bash
make
```

This will generate the get_next_line.a library.
Integration

To use get_next_line in your project, include the header file in your source code:

```c
#include "get_next_line.h"
```

Link your project with the compiled library:

```bash
gcc -o your_program your_source.c -L. -lget_next_line
```

Example

```c
#include "get_next_line.h"

int main() {
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);

    return 0;
}
```

## Return Values

The function returns 1 when a line has been read.
The function returns 0 when the end of the file has been reached.
The function returns -1 on error.

## Important Notes

The user is responsible for freeing the memory allocated for the line.
The function supports reading from multiple file descriptors simultaneously.
