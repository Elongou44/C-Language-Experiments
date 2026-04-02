#include<stdio.h>
#include<string.h>
int main()
{   int i=0,j=0;
	char ch[100];
	gets(ch);
	i=strlen(ch);
	for(j=i-1;j>=0;j--)
		printf("%c",ch[j]);
    return 0;
}
