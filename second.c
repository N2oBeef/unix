#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

#define MODE 0700

int main()
{
	int fd;

	if ((fd = creat("file.hole", MODE)) < 0)
		printf("creat error");

	if (write(fd, buf1, 10) != 0)
		printf("buf1 write error");

	if (lseek(fd, 16348, SEEK_SET) == -1)
		printf("lseek error");

	if (write(fd, buf2, 10) != 10)
		printf("buf2 write error");
	
	exit(0);
	return 0;
}
