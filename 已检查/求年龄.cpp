#include<stdio.h>    
int aaa(){
	static int a = 24,b = 5;
	if(b == 1)
         printf("%d",a);
	else{
		a=a-3;
		b--;
		aaa();
	}
	return 0;
}  
int main(){  
    int i=5; 
    aaa();
    return 0;
}
