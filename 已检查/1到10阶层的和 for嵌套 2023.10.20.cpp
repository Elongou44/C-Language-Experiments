#include<stdio.h> 
int main()
{
	int i,j;
	double max,sum=0;
	for(i=1;i<=10;i++)
	{
		max=1;
		for(j=1;j<=i;j++)
		max=max*j;
		sum=max+sum;
	}
	printf("%lf",sum); 
	return 0;
}
