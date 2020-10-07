#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

#define memory 10 * 1024 * 1024

int main(){

    for (int i = 0; i < 10; ++i) {
        void *scope = malloc(memory); //allocate memory
        memset(scope, 0, memory); // fill with zeros

        sleep(1);
    }

    return 0;
}

/* after running (./ex2 & vmstat 1)
 * we see that si & so are equal to 0, which means that swap is not using =>
 * => we still have enough memory
 * if we'll be running out of memory, system will start using swap
 *
 * procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 1  0      0 12771068  11232  98536    0    0     5   236    9   22  0  0 100  0  0
 0  0      0 12761860  11232  98536    0    0     0     0    3   32  0  0 100  0  0
 0  0      0 12751652  11232  98536    0    0     0     0    2   24  0  0 100  0  0
 0  0      0 12741444  11232  98536    0    0     0     0    2   24  0  0 100  0  0
 0  0      0 12731236  11232  98536    0    0     0     0    3   24  0  0 100  0  0
 0  0      0 12721028  11232  98536    0    0     0     0    2   26  0  0 100  0  0
 0  0      0 12710556  11240  98528    0    0     0    28   42  127  0  0 100  0  0
 0  0      0 12699844  11240  98528    0    0     0     0    3   26  0  0 100  0  0
 0  0      0 12689636  11240  98540    0    0     0     0   95  243  0  0 100  0  0
 0  0      0 12679176  11240  98540    0    0     0     0    2   25  0  0 100  0  0*/


/*
 * after running (./ex2 & top -d 1 -u forne) >> ex3.txt
 * we see that virtual mem used by our program is increasing each second*/