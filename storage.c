#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int storage_create(const char* name, int size){
    int rc = 0, fd = open(name, O_RDWR | O_CREAT | O_EXCL | O_CLOEXEC, S_IRUSR | S_IWUSR);
    if(fd < 0){
        fprintf(stderr, "open: %s\n", strerror(errno));
        return -1;
    }

    if(ftruncate(fd, size) != 0){
        fprintf(stderr, "ftruncate: %s\n", strerror(errno));
        rc = -1;
    }

    if(close(fd) != 0){
        fprintf(stderr, "close: %s\n", strerror(errno));
        rc = -1;
    }

    return rc;
}

int storage_delete(const char* name){
    int rc = unlink(name);
    if(rc != 0) fprintf(stderr, "close: %s\n", strerror(errno));
    return rc;
}

int storage_open(const char* name, void* address, int size){
    int fd = open(name, O_RDWR | O_CLOEXEC);
    if(fd < 0){
        fprintf(stderr, "open: %s\n", strerror(errno));
        return -1;
    }

    return 0;
}

/*int storage_close(const char* name, void* address, int size){
    return 0;
}*/
