#include<stdio.h> 
int main()
{
	int a[6],i=0,j=0,k=0;
	for(i=0;i<6;i++)
	scanf("%d",&a[i]);
	for(i=0;i<5;i++)
		for(j=i+1;j<6;j++)
		if(a[i]<a[j])
		{k=a[i];
		 a[i]=a[j];	
		 a[j]=k;
		}
	for(j=0;j<6;j++)
	printf("%d ",a[j]);
	return 0;
}
