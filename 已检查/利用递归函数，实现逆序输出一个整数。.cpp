#include<stdio.h>    
int aaa(int a){
	if(a == 0);
	else{
	    printf("%d",a % 10);
	    aaa(a / 10);
	}
	return 0;
}  
int main(){  
    int i;
    scanf("%d",&i);
    aaa(i);
    return 0;  
}
