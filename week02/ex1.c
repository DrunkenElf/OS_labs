#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    int i;
    float f;
    double d;

    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;

    printf("int_max = %d\t s = %lu\n", i, sizeof(i));
    printf("float_max = %g\t s = %lu\n", f, sizeof(f));
    printf("double_max = %g\t s = %lu\n", d, sizeof(d));
    return 0;
}