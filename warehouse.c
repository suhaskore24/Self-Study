#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item{
		int id;
		char name[20];
		int quan;
		float price;
}item_t;

void display(item_t arr[],int size)
{
		for(int i=0;i<size;i++)
		{
				printf("%d\n%s\n%d\n%.2f",arr[i].id,arr[i].name,arr[i].quan,arr[i].price);
		}
}

void update_using_id(item_t arr[],int size,int id)
{
		for(int i=0;i<size;i++)
		{
				if(id


			
int main()
{
		int choice;
		int n;
		printf("Enter the total no of items you want to store");
		scanf("%d",&n);
		int count=0;

		item_t *arr=malloc(sizeof(item_t)*n);
		do{
				printf("Enter your choice\n");
				printf("0.Exit\n1.Add item\n2.delete item\n3.display all items\n4.Upade stock using id\n5.Update stock using name\n6.calculate value\n");
				scanf("%d",&choice);
				if(choice==0)
				{
						break;
				}

				switch(choice)
				{
						case 1: printf("Enter below information\n");
								printf("Enter the ID of the product");
								scanf("%d",&arr[count].id);
								printf("Enter name of product\n");
								scanf("%s",arr[count].name);
								printf("Enter the total quantity\n");
								scanf("%d",&arr[count].quan);
								printf("Enter the price of product\n");
								scanf("%f",&arr[count].price);
								count++;
								break;

						case 2: printf("Enter the ID of the item you want to delete\n");
								int ID;
								scanf("%d",&ID);
								for(int i=0;i<count;i++)
								{
										if(arr[i].id==ID)
										{
												for(int j=i;j<count;j++)
												{
														arr[j]=arr[j+1];
												}
										}
								}
								break;

						case 3:display(arr,count);

					    case 4:update_using_id(arr,count,2)
				}
		}while(choice!=0);

		FILE *fp=fopen("product.txt","w");
		fwrite(arr,sizeof(arr),1,fp);
		fclose(fp);

}

								
