#include<stdio.h>
int main()
{
		FILE *fp;
		fp=fopen ("file.txt","w");

		if(fp==NULL)
		{
				printf("file not opened");
				return 0;
		}

		char str[]="Ind defended the world cup";
		for(int i=0;str[i]!='\0';i++)
		{
				putc(fp)
