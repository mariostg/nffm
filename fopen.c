#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char filename[]="text.txt";
    fd=open(filename, O_RDWR);
    if(fd==-1)
        fd=open(filename, O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    else
        puts("File exists??");
    if (fd)
        close(fd);
    else
        puts("did not work");
    return 0;
}
