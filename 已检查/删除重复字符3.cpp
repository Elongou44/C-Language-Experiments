#include<stdio.h>
#include<string.h>
int main()
{   int i=0,j=1,k=0,t=1;
	char a[]="aabbc";
    for(i=0;i<5;i++)
    {   k=1;
    	for(j=t;j<5;j++)
    	{   if(a[i]==a[j])
    		a[i]='0';}
		t++;
	}
	for(i=0,j=0;i<5;i++)
	    if(a[i]!='0')
	    a[j++]=a[i];
	a[j]='\0';
	printf("%s",a);
	return 0;}
