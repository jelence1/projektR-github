//reading 32-bit from bin file
int read_word(int fd);

//reading 16-bit from bin file
short read_half(int fd);

//writing 32-bit to bin file
void write_word(int fd, int word);

//writing 16-bit to bin file
void write_half(int fd, short word);