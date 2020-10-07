#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <sys/resource.h>

#define memory 10 * 1024 * 1024

int main(){
    struct rusage usage;

    for (int i = 0; i < 10; ++i) {
        void *scope = malloc(memory); //allocate memory
        memset(scope, 0, memory); // fill with zeros

        getrusage(RUSAGE_SELF, &usage);
        printf("Usage: %ld\n", usage.ru_maxrss);

        sleep(1);
    }

    return 0;
}