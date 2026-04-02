#include<stdio.h> 
int main()
{
	int i=1,j=1;
	double max=1,sum=0;
	while(i<=10)
	{
		while(j<=i)
		{
			max=max*j;
			j++;
			sum=max+sum;
		}
	i++;	
	}
	printf("%lf",sum); 
	return 0;
}
