#include <unistd.h>
#include <stdlib.h>

//reading 32-bit from bin file
int read_word(int fd) {
    int *file_contents = malloc(sizeof(int));
    int read_bytes = read(fd, file_contents, sizeof(int));
    return *file_contents;
}

//reading 16-bit from bin file
short read_half(int fd) {
    short *file_contents = malloc(sizeof(short));
    int read_bytes = read(fd, file_contents, sizeof(short));
    return *file_contents; //
}

//writing 32-bit to bin file
void write_word(int fd, int word) {
    int *buffer = &word;
    int written = write(fd, buffer, sizeof(int));
}

//writing 16-bit to bin file
void write_half(int fd, short word) {
    short *buffer = &word;
    int written = write(fd, buffer, sizeof(short));
}