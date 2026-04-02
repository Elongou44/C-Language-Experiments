#include<stdio.h>
int main()
{
	int i, j, a[10];
	a[0] = 1;
	for(i = 0; i < 5; i++)
	{
		for (j = i; j < 5; j++)
		{
			a[j] = a[i] + 1; 
		}
	} 
	 for(i = 0; i < 5; i++)
	 {
	 	printf("%4d",a[i]) ;
	 }
	 return 0;
}
