#include<stdio.h>
int main()
{   int i,j=0;
	char ch[]="ccbab";
	for(i=0;i<5;i++)
	 for(j=0;j<i;j++)
	 if(ch[i]==ch[j])
	 ch[j]='\0';
	for(i=0;i<5;i++)
	printf("%c",ch[i]);
	return 0;}
