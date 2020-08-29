#include <stdio.h>

int main(int argc, char *argv[])
{
    int count;
    char uni[7] = "Unifei";

    for (count = 0; count < 7; count++)
        printf("Dec=%d Hexa=%x\n", uni[count], uni[count]);

    return 0;
}
