#include<stdio.h>
#include<string.h>

struct customer{
		char name[20];
		char vehical[20];
		int ID;
};

struct service{
		char vehical[20];
		int price;
		int lacharge;
};

struct oil{
		char name[20];
        int price;
};

int main()
{
		int choice;
		struct customer c1;
		struct service s1;
		struct oil o1;
          
			
		do{
				printf("Enter the below details\n");
				printf("Select Service\n1.Maintenance\n2.Oil change\n3.Exit");
				scanf("%d",&choice);
				if(choice==3)
				{
						break;
				}
	        	printf("Enter your name\n");
				scanf("%s",c1.name);
				printf("Enter your vehical number/n");
				scanf("%s",c1.vehical);
				printf("Enter your ID");
				scanf("%d",&c1.ID);
                printf("\n \n");
				

				switch(choice)
				{
						case 1:
								
								printf("Enter part to be replace");
								scanf("%s",s1.vehical);
								printf("Enter the price ");
								scanf("%d",&s1.price);
								printf("Enter the labour charges");
								scanf("%d",&s1.lacharge);
								printf("your details:\n%s\n %s\n %i:",c1.name,c1.vehical,c1.ID);

								int per=(s1.price+s1.lacharge)*(5/100);
								int total=(s1.price+s1.lacharge)+per;
								printf("your bill:%d\n",total);
								break;

						case 2: 
								printf("Enter oil name");
								scanf("%s",o1.name);
								printf("Enter the price");
								scanf("%d",&o1.price);
								printf("your details:\n%s\n%s\n%d",c1.name,c1.vehical,c1.ID);
								int total1=(o1.price)+(o1.price*12/100);
								printf("Your bill:%d\n",total1);
								break;

						default:
								printf("Wrong choice");
								break;

				}
		}while(choice!=3);


}






