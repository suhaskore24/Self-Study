#include<stdio.h>
struct student{
		char name[20];
		int id;
		float per;
};

void accept(struct student *sptr)
{
		printf("Enter values");
		scanf("%s %d %f",sptr->name,&sptr->id,&sptr->per);
}
void print(struct student *sptr)
{
		printf("%s %d %f",sptr->name,sptr->id,sptr->per);
}
int main()
{
       struct student s1;
	   struct student s2={"Rohit",45,264};
	   struct student  *ptr;
	   ptr=&s2;
       struct student arr[3];
	   for(int i=0;i<3;i++)
	   {
			   accept(&arr[i]);
	   }
	   for(int i=0;i<3;i++)
	   {
			   print(&arr[i]);
	   }
}

	  /* gets(s1.name);
	   scanf("%d",&s1.id);
	   scanf("%g",&s1.per);

		printf("Name %s\nID %d\nPercentage %.2f",s1.name,s1.id,s1.per);
		*/
//	   printf("Name %s \nID %d\nPercentage %g\n",ptr->name,ptr->id,ptr->per);

		
