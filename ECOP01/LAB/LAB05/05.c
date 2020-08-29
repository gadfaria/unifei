#include <stdio.h>
#include <float.h>

int main(int argc, char *argv[])
{

    printf("double: %ld bytes (%lf a %lf) \n",
           sizeof(double), DBL_MIN, DBL_MAX);

    printf("float: %ld bytes (%f a %f)",
           sizeof(float), FLT_MIN, FLT_MAX);

    return 0;
}
