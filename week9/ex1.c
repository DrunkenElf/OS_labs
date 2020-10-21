#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct mFrame {
    int num;
    unsigned  char age;
}*mFrames ;

int num_frames = 10;

void alloc_fr(){
    mFrames = malloc(num_frames * sizeof(struct mFrame));

    for (int i = 0; i < num_frames; ++i){
        mFrames[i].num = -1;
        mFrames[i].age = 0;
    }

}

int main() {

    //use aging algoritm

    alloc_fr();

    int miss = 0;
    int hit = 0;

    FILE* input  = fopen("Lab 09 input.txt", "r");

    int curr_num;

    while (fscanf(input, "%d", &curr_num) != EOF){
        int min = 0;
        //refresh ages
        for (i = 0; i< num_frames; ++i){
            if (mFrames[i].age < mFrames[min].age)
                min = i;
            mFrames[i].age = mFrames[i].age >> 1;
        }

        //check for hit | miss
        for (int i = 0; i < num_frames; ++i) {
            if (mFrames[i].page_number == curr_num) { //when hit
                mFrames[i].age = mFrames[i].age | (1 << 7);
                ++hit;
                return;
            }
        }

        //if hit not found)
        ++miss;
        mFrames[min].age = 1 << 7;
        mFrames[min].num = curr_num;
    }
    double  ratio = hit / miss;
    printf("Hits %d",hit);
    printf("Misses %d", miss);
    printf("Hit/Miss ratio %f", ratio);

}