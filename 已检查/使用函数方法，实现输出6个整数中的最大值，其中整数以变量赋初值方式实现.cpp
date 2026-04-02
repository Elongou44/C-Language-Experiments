#include<stdio.h>
int max(int x,int y)
{   if(x>y)
	return x;
	else
	return y;}
int main()
{   int a1=5,a2=6,a3=9,a4=2,a5=3,a6=11,i;
	i=max(a1,max(a2,max(a3,max(a4,max(a5,a6)))));
	printf("最大值为%d",i);
	return 0;}
