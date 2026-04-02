#include<stdio.h> 
int aaa(int n) {  
    int a=1,b=1;
    while(a<=n){
    	b*=a;
    	a++;
	}
	return b;
}  
int main() {  
    int i, a, b, c;  
    for (i = 100; i <= 999; i++) {  
        a = i / 100;  
        b = (i % 100) / 10;   
        c = i % 10;  
        if (i == aaa(a) + aaa(b) + aaa(c)) {  
            printf("%d\n", i);  
        }  
    }  
    return 0;  
}
