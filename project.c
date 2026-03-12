#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct book{
		int id;
		char name[20];
		char author[20];
		int price;
		int year;
};

void display(struct book arr[],int size)
{
		for(int i=0;i<size;i++)
		{
				printf("%d\n%s\n%s\n%d\n%d\n",arr[i].id,arr[i].name,arr[i].author,arr[i].price,arr[i].year);
				//printf("\n");

		}
}

void author_pr(struct book arr[],int size,char au[])
{
		for(int i=0;i<size;i++)
		{
				if(!(strcmp(arr[i].author,au)))
				{
						
				printf("%d\n%s\n%s\n%d\n%d\n",arr[i].id,arr[i].name,arr[i].author,arr[i].price,arr[i].year);
				printf("\n");
				}
		}
}

void id_pr(struct book arr[],int size,int id)
{
		for(int i=0;i<size;i++)
		{
				if(arr[i].id==id)
				{

				printf("%d\n%s\n%s\n%d\n%d\n",arr[i].id,arr[i].name,arr[i].author,arr[i].price,arr[i].year);
				printf("\n");
				}
		}
}

void yer_pr(struct book arr[],int size,int year)
{
		
		for(int i=0;i<size;i++)
		{
				if(arr[i].year==year)
				{

				printf("%d\n%s\n%s\n%d\n%d\n",arr[i].id,arr[i].name,arr[i].author,arr[i].price,arr[i].year);
				printf("\n");
				}
		}

}

int main()
{
		int N;//Total no of books
		printf("Enter total no of books");
		scanf("%d",&N);
		int count=0;
		int id;
		int choice;

		struct book *arr=(struct book*)malloc(sizeof(struct book)*N);

		do{
				printf("Enter you choice\n");
				printf("1.Add Bokk\n2.Delete book\n3.Display all books\n4.Display books by author\n5.Display books by year\n6.Find avg price\n7.Exit\n");
				scanf("%d",&choice);
				if(choice==7)
				{
						break;
				}

				switch(choice)
				{
						case 1: printf("Give the book ID,name,author,price,year");
								scanf("%d %s %s %d %d",&arr[count].id,arr[count].name,arr[count].author,&arr[count].price,&arr[count].year);
								count++;
//								display(arr,N);
								break;

						case 2:printf("Enter the id of book you want to delete");
							   scanf("%d",&id);
							   for(int i=0;i<count;i++)
							   {
									   if(arr[i].id==id)
									   {
											   for(int j=i;j<count-1;j++)
											   {
													   arr[j-1]=arr[j];
											   }
											   count--;
									   }
							   }
							   break;
                        case 3: display(arr,count);
                                 break;
						case 4: id_pr(arr,count,10);
								break;

						case 5: yer_pr(arr,count,2002);
								break;
				}


		/*		FILE *fp=fopen("data.txt","wb");
				fwrite(arr,sizeof(struct book),count,fp);
                fclose(fp);
*/

		}while(choice!=7);
		FILE *fp=fopen("data.txt","wb");
		fwrite(arr,sizeof(struct book),count,fp);
        fclose(fp);

}

