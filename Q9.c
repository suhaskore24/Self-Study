#include<stdio.h>


int main(void)
{
	int var = 0x41424344;

	char *ptr = (char *)&var;

	if(*ptr == 0x44)
		printf("Little endian\n");
	else
		printf("Big endian\n");

	return 0;
}
