#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *out;

    switch (argc) {
        case 2:
            out = fopen(argv[1], "w");

            break;
        case 3:
            out = fopen(argv[2], "a");

            break;
        default:
            return -1;
    }
    char c;
    while (scanf("%c", &c) == 1){
        fprintf(out, "%c", c);
    }

    return 0;
}