#include<stdio.h> 
int main()
{
	int a[6]={1,5,10,15,20},i=0,j=0,k=0;
	scanf("%d",&a[5]);
	for(i=0;i<5;i++)
		for(j=i+1;j<6;j++)
		if(a[i]>a[j])
		{k=a[i];
		 a[i]=a[j];	
		 a[j]=k;
		}
	for(j=0;j<6;j++)
	printf("%d ",a[j]);
	return 0;
}
