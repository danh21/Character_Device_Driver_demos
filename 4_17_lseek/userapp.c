#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    	char buffer[50];	
	int fd;
	int length;
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}
	
	printf("write : %d\n", write(fd, "hello world", sizeof("hello world")));
	lseek(fd, sizeof("hello world")-1, SEEK_SET);	
	printf("write : %d\n", write(fd, " bye world", sizeof(" bye world")));	
	
	lseek(fd, 0, SEEK_SET);	//set the file position to 0
	perror("lseek");
	memset(buffer, 0, sizeof(buffer));
	length = read(fd, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read:%s\t length:%d\n", buffer, length);
	for (i = 0 ; i < length; i++)
		printf("buffer[%d]:\t%c\n", i, buffer[i]);
		
	/* forget to set file pos */
	memset(buffer, 0, sizeof(buffer));
	length = read(fd, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read:%s\tlength:%d\n", buffer, length);
	
	close(fd);
}
