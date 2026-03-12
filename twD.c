#include<stdio.h>
int main()
{
//		int arr[3][3];
 int row=3;
 int col=3;
 int **ptr=(int *)malloc(sizeof(int*)*row);
for(int i=0;i<row;i++)
{
		ptr[i]=(int*)malloc(sizeof(int)*col);
}
		for(int i=0;i<3;i++)
		{
				for(int j=0;j<3;j++)
				{
						scanf("%d",(*(arr+i)+j));
				}

		}

		for(int i=0;i<3;i++)
		{
				for(int j=0;j<3;j++)
				{
						printf("%d",arr[i][j]);
				}
				printf("\n");
		}
}

