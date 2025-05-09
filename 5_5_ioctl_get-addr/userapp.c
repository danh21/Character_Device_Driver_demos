#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "ioctl_cmd.h"

int main(int argc, char *argv[])
{
	char buffer[1024];	
	int fd;
	unsigned int length;
	unsigned char ch = 'A';
	unsigned int in;
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}

	// get 1 byte
	ioctl(fd, MSG_GET_ADDRESS, &ch);
	perror("ioctl");
	getchar();
	printf("%x\n", ch);

	// get 4 bytes
	ioctl(fd, MSG_GET_ADDRESS, &in);
	perror("ioctl");
	getchar();
	printf("%x\n", in);

	close(fd);
}
