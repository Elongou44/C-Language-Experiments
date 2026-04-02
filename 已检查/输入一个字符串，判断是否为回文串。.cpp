#include<stdio.h>
#include<string.h>
int main()
{   int i=0,j=0,k=0,t=1;
	char ch[100];
	gets(ch);
	i=strlen(ch);
	for(j=i-1;k<j;j--,k++)
	 {if(ch[k]!=ch[j])
      t=0;}
	if(t==1)
	printf("是回文串");
	else
	printf("不是回文串");
	return 0;}
