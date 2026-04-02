#include<stdio.h>    
int gcd(int m, int n) {  
    if (n == 0) {  
        return m;  
    } else {  
        return gcd(n, m % n);  
    }  
}  
int main() {  
    int m, n;  
    printf("请输入两个正整数: ");  
    scanf("%d%d", &m,&n);    
    printf("最大公约数为: %d\n", gcd(m, n)); 
    return 0;  
}
