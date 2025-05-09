#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	unsigned long num_blocks;

	fd = open("/dev/sda2", O_RDONLY);
	perror("fd");

	//0x00001260   BLKGETSIZE            unsigned long *
	ioctl(fd, 0x00001260,	&num_blocks);
	perror("ioctl");
	printf("Number of blocks: %lu, this makes %.3f GB\n",
	 num_blocks,
	 (double)num_blocks * 512.0 / (1024 * 1024 * 1024));
	close(fd);
	return 0;

	// df -h to check
}
