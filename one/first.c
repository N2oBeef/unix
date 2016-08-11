#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("connot seek");
	else
		printf("seek ok\n");
	
	exit(0);
}
