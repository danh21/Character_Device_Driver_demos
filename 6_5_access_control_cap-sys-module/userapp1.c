/*
    $ sudo setcap cap_sys_module+ep ./userapp1
    $ ./userapp1 hello.ko
        -> init kernel module
*/

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define init_module(module_image, len, param_values) syscall(__NR_init_module, module_image, len, param_values)

int main(int argc, char **argv) {
    const char *params = "";
    int fd, use_finit;
    size_t image_size;
    struct stat st;
    void *image;

    fd = open(argv[1], O_RDONLY);
    fstat(fd, &st);
    image_size = st.st_size;
    image = malloc(image_size);
    read(fd, image, image_size);
    close(fd);
    if (init_module(image, image_size, params) != 0) {
	    perror("init_module");
	    return EXIT_FAILURE;
    }
    free(image);
    return EXIT_SUCCESS;
}
