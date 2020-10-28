#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int main(){
    int file = open("ex1.txt", O_RDWR);


    ftruncate(file, sizeof("This is a nice day"));

    void* map = mmap(0, sizeof("This is a nice day"),
                     PROT_WRITE, MAP_SHARED,
                     file, 0);

    strcpy(map, "This is a nice day");

    munmap(map, sizeof("This is a nice day"));

    close(file);

    return 0;
}
