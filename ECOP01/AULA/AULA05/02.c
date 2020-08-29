#include <stdio.h>

int main(int argc, char *argv[])
{
	int total, pri, seg, ter;

	total = 780000;
	pri = total * 0.46;
	seg = total * 0.32;
	ter = total - (pri + seg);

	printf("\n");
	printf("Primeiro %d\n ", pri);
	printf("Segundo %d\n ", seg);
	printf("Terceiro %d\n ", ter);

	return 0;
}
