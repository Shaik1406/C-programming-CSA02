#include<stdio.h>
void main()
{
struct bank
{
int acc_no;
char name[20];
int bal;
}b[5];

int i;


for(i=0;i<5;i++)
{
printf(" \n\n enter the acc_no,name,balance\n\n");
printf("\nenter the account no\n");
scanf("%d",&b[i].acc_no);
printf("\n enter the name\n");
scanf("%s",b[i].name);
printf("\n enter the balance\n");
scanf("%d",&b[i].bal);
}
for(i=0;i<5;i++)
{
if(b[i].bal<100)
{
printf("\n---------------------------------------------\n");
printf("\n\n The acc_no,name,balance below RS:-100\n\n");
printf("\n the account no:-%d\n",b[i].acc_no);
printf("\n the name:-%s\n",b[i].name);
printf("\n the balance:-%d\n",b[i].bal);
}
}
return 0;
}
