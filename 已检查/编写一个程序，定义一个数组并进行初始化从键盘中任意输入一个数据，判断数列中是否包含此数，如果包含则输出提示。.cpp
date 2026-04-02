#include<stdio.h> 
int main()
{   int a[5]={1,2,3,4,5},i=0,j;
	scanf("%d",&j);
	for(i=0;i<5;i++)
	{
		if(j==a[i])
		{printf("数列中包含此数:%d",j); 
		 goto aaa;
		}
	}
	printf("数列中不包含此数:%d",j); 
	aaa:return 0;
	return 0;}
