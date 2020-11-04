#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    FILE *random = fopen("/dev/random", "r");
    FILE *out = fopen("./ex1.txt", "w");

    char str[20];

    fgets(str, 20, random);
    fprintf(out, "%s", str);
    printf("%s", str);

    return 0;
}