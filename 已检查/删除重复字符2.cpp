#include<stdio.h>
#include<string.h>
int main()
{   int i=0,j=1,k=0,t=1,n=0;
	char a[]="ccbab",b[5];
    for(i=0;i<5;i++)
    {   k=1;
    	for(j=t;j<5;j++)
    	{   if(a[i]==a[j])
    		k=0;}
		t++;
		if(k==1)
        {b[n]=a[i];
		 n++;}
	}
	for(i=0;i<5;i++)
	printf("%c",b[i]);
	return 0;}
