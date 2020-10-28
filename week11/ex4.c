#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {

    int in = open("ex1.txt", O_RDWR);
    if (in == -1){
        printf("Cannot open file in\n");
        return 0;
    }

    int out = open("ex1.memcpy.txt", O_CREAT|O_RDWR|O_APPEND, S_IRUSR | S_IWUSR);
    if (out == -1){
        printf("Cannot open file out\n");
        return 0;
    }

    struct stat props;

    void *srcMap = mmap(NULL, props.st_size,
                        PROT_READ, MAP_SHARED,
                        in, 0);

    ftruncate(out, props.st_size);

    void *dstMap = mmap(NULL, props.st_size,
                        PROT_READ | PROT_WRITE, MAP_SHARED,
                        out, 0);


    memcpy(dstMap, srcMap, props.st_size);


    munmap(srcMap, props.st_size);
    munmap(dstMap, props.st_size);

    close(in);
    close(out);

    return 0;
}