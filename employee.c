#include<stdio.h>
#include<string.h>

struct date{
		int dd;
		int mm;
		int yy;
};

typedef struct emp
{
		int id;
		char name[20];
		char dep[20];
		float  salary;
		struct date dob;

}emp_t;

void accept(emp_t *e1)
{
		printf("Enter id\n");
		scanf("%d",&e1->id);
		printf("Enter name\n");
		scanf("%s",e1->name);
		printf("Enter Department\n");
		scanf("%s",e1->dep);
		printf("Enter salary\n");
		scanf("%f",&e1->salary);
		printf("Enter Date of birth\n");
		scanf("%d %d %d",&e1->dob.dd,&e1->dob.mm,&e1->dob.yy);
}

void add_emp(emp_t *e1)
{
		FILE *fp=fopen("Emp.txt","ab");
		fwrite(e1,sizeof(emp_t),1,fp);
		fclose(fp);
}

void print(emp_t e1)
{
		printf("Employee ID:%d\nEmployee Name:%s\nEmployee depart:%s\nEmployee sal:%.2f\nEmployee DOB:%d-%d-%d\n",e1.id,e1.name,e1.dep,e1.salary,e1.dob.dd,e1.dob.mm,e1.dob.yy);
}

void display(void)
{
		emp_t e1;
		FILE *fp=fopen("Emp.txt","rb");
		while(fread(&e1,sizeof(e1),1,fp)!=0)

		{
				print(e1);
		}
}

void search_by_ID(int id)
{
		emp_t e1;

		FILE *fp=fopen("Emp.txt","rb");
		while(fread(&e1,sizeof(emp_t),1,fp)!=0)

		{
				if(e1.id==id)
				{
						printf("Employee found\n");
						print(e1);
						return;
				}
				
		}
		printf("Sorry not found\n");
		fclose(fp);
}

void search_by_name(char *str)
{
		emp_t e1;

		FILE *fp=fopen("Emp.txt","rb");
		while(fread(&e1,sizeof(emp_t),1,fp)!=0)
		{
				if(strcmp(e1.name,str)==0)
				{
						printf("Employee found\n");
						print(e1);
				}
				return;
				
		}
		printf("Sorry employee not found\n");
		fclose(fp);
}


void update_employee_using_id(int id)
{
		emp_t e1;
		FILE *fp=fopen("Emp.txt","rb");
		while(fread(&e1,sizeof(emp_t),1,fp)!=0)
		{
				if(e1.id==id)
				{
						printf("Employee found : \n");
						print(e1);
						float sal;
						printf("Enter new sal : ");
						scanf("%f",&sal);
						e1.salary=sal;
						fseek(fp,-1*sizeof(e1),SEEK_CUR);
						fwrite(&e1,sizeof(e1),1,fp);
						printf("Employee updated successfully....\n");
						fclose(fp);
						return;
				}
		}
		printf("Sorry employee not found:\n");
		fclose(fp);
}

void delete_emp_by_id(int id)
{
     emp_t e1;
     FILE *fp = fopen("emp.db","rb+");

     while( (fread(&e1,sizeof(e1),1,fp)) != 0 )
     {
        if(e1.id == id)
        {
             while(fread(&e1, sizeof(e1), 1, fp) != 0)
                {
                    fseek(fp, -2 * sizeof(e1), SEEK_CUR);
                    fwrite(&e1, sizeof(e1), 1, fp);
                    fseek(fp, +1 * sizeof(e1), SEEK_CUR);
                }
                break;
        }
     }
    fseek(fp, -1 * sizeof(e1), SEEK_END);
	int pos = ftell(fp);
	printf("%d\n", pos);
	fclose(fp);
	truncate("Emp.txt", pos);

 }

		
int main()
{
		int choice;
		emp_t e1;
		
		do{
				printf("0.Exit\n1.Add Employee\n2.Display Employee\n3.Search By ID \n4.Search by name \n5.Update Employee info Using ID\n6.Delete employee using ID\n7.Total Employee\n");
        printf("Your Choice : ");
        scanf("%d",&choice);
        if(choice==0)
		{
				break;
		}

		switch(choice)
		{
				case 1: accept(&e1);
						add_emp(&e1);
						break;
				case 2: display();
					    break;
				case 3: search_by_ID(10);
						break;
				case 4: search_by_name("suhas");
						break;
				case 5: update_employee_using_id(20);
						break;

		}
		}while(choice!=0);
}



