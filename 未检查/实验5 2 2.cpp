#include<stdio.h> 
int main()
{   int a[6],i=0,j=0,k=0,t;
	for(i=0;i<6;i++)
	scanf("%d",&a[i]);
	for(i=0;i<5;i++)
	{k=i;
	for(j=i+1;j<6;j++)
	if(a[k]<a[j])
	k=j;
	 if(i!=k)
	 {t=a[k];
	 a[k]=a[i];	
	 a[i]=t;}
    }
	for(j=0;j<6;j++)
	printf("%d ",a[j]);
	return 0;}
