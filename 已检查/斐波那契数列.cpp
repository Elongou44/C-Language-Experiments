#include<stdio.h>    
int aaa(int a){
	if(a == 1 || a ==2)
	return 1;
	else
	return aaa(a-1)+aaa(a-2);
}  
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",aaa(n));
	return 0;
}
