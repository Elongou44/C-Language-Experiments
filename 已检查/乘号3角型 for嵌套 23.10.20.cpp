#include<stdio.h> 
int main()
{
	int i=1,j=1;
	while(i<=5)
	{
		while(j<=2*i-1)
		{
			while(j<=9-i)
	 	    {printf(" ");
	 	    j++;
	     	}
		printf("*");
		printf("\n");
		}
	i++;
	}
	return 0;
}
