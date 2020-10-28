#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    char buffer[511];
    setvbuf(stdout, buffer, _IOLBF, 511); //set virtual line buffer

    char* hello = "Hello";
    for (int i = 0; i < 5; ++i) {
        printf("%c", hello[i]);
        sleep(1);
    }

    return 0;
}