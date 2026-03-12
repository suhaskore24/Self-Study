#include<stdio.h>
#include<string.h>

struct date{
		int dd;
		int mm;
		int yy;
};
typedef struct bank{
		int account;
		char name[20];
		char type[20];
		int balance;
		struct date open;
}bank_t;

void accept(bank_t *b1)
{
		printf("Enter account number\n");
		scanf("%d",&b1->account);
		printf("Enter the name\n");
		scanf("%s",b1->name);
		printf("Enter account type\n");
		scanf("%s",b1->type);
		printf("Enter balance\n");
		scanf("%d",&b1->balance);
		printf("Account opening date\n");
		scanf("%d %d %d",&b1->open.dd,&b1->open.mm,&b1->open.yy);
}

void create(bank_t *b1)
{
		FILE *fp=fopen("bank.txt","ab");
		if(fp==NULL)
		{
				printf("File not created");
		}
		fwrite(b1,sizeof(bank_t),1,fp);
        fclose(fp);
}
void print(bank_t b1)
{
		printf("%d\n%s\n%s\n%d\n%d%d%d\n",b1.account,b1.name,b1.type,b1.balance,b1.open.dd,b1.open.mm,b1.open.yy);
}

void display(void)
{
		bank_t b1;
		FILE *fp=fopen("bank.txt","rb");
		while(fread(&b1,sizeof(bank_t),1,fp)!=0)
		{
				print(b1);
		}
		fclose(fp);
}

void search_account_by_num(int acnum)
{
	  bank_t b1;
	  FILE *fp=fopen("bank.txt","rb");
	  while(fread(&b1,sizeof(b1),1,fp)!=0)
	  {
			  if(b1.account==acnum)
			  {
					  printf("Bank account found\n");
					  print(b1);
			  }
	  }
	  fclose(fp);
}

void search_account_by_name(char *str)
{
		bank_t b1;
		FILE *fp=fopen("bank.txt","rb");
		while(fread(&b1,sizeof(b1),1,fp)!=0)
		{
				if(strcmp(str,b1.name)==0)
				{
						printf("Account found");
						print(b1);
				}
		}
		fclose(fp);
}

void update_using_account(int acc)
{
		bank_t b1;
		FILE *fp=fopen("bank.txt","rb+");
		while(fread(&b1,sizeof(b1),1,fp)!=0)
		{
				if(acc==b1.account)
				{
						printf("Account found\n");
						print(b1);
						int new_bal;
						printf("Enter new acc balance\n");
						scanf("%d",&new_bal);
						b1.balance=new_bal;
						fseek(fp,-1*sizeof(b1),SEEK_CUR);
						fwrite(&b1,sizeof(b1),1,fp);
						printf("Updated successfully");
					
				}
		}
		fclose(fp);
}

void delete_account(int acc)
{
		bank_t b1;
		FILE *fp=fopen("bank.txt","rb+");
		while(fread(&b1,sizeof(b1),1,fp)!=0)
		{
				if(b1.account==acc)
				{
						while(fread(&b1,sizeof(b1),1,fp)!=0)
						{
								fseek(fp,-2*sizeof(b1),SEEK_CUR);
								fwrite(&b1,sizeof(b1),1,fp);
								fseek(fp,1*sizeof(b1),SEEK_CUR);
						}
						break;
				}
				
		}
		fseek(fp,-1*sizeof(b1),SEEK_CUR);
		int pos=ftell(fp);
		fclose(fp);
//		truncate("bank.txt",pos);
}

int main()
{
		int choice;
		bank_t b1;
		do{
				printf("Enter your choice\n");
			//	scanf("%d",&choice);
				printf("0.Exit\n1.Create account\n2.Display all account\n3.search accont by account number\n4.search account by customer name\n5.update balance using account number\n6.Delete account\n7.total account");
				
			
				scanf("%d",&choice);

				if(choice==0)
				{
						break;
				}
                switch(choice)
				{

				case 1: accept(&b1);
						create(&b1);
						 break;
				
				case 2: display();
						break;

				case 3:search_account_by_num(10);
					   break;

				case 4:search_account_by_name("suhas");
					   break;

				case 5:update_using_account(10);
					   break;
				case 6:delete_account(10);
					   break;
				}
		}while(choice!=0);
}
