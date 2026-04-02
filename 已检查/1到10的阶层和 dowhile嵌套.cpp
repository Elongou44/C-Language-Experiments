#include<stdio.h> 
int main()
{
	int i=1,j=1;
	double max=1,sum=0;
	do{i++;
		do{max=max*j;
		   j++;
		   sum=sum+max;
		  }while(j<=i);
	  }while(i<=9);
	printf("%lf",sum);
	return 0;
}
