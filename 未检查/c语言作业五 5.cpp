#include<stdio.h>
int main()
{
    char ch;
    int num=0;
    for(;(ch=getchar())!='\n';)
    {
    	if(ch>='A'&&ch<='Z')
    	putchar(ch+32);
    	else
    	num++;
	}
	printf("\n其他字符个数为:%d",num);
	return 0;
}
