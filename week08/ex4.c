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

/* we see that mem usage increases every second by 10MB
 * Usage: 11360
Usage: 21948
Usage: 31972
Usage: 42260
Usage: 52548
Usage: 62836
Usage: 73124
Usage: 83412
Usage: 93436
Usage: 103724
*/