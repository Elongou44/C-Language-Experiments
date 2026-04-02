#include<stdio.h>
int main() {
	int *a;  
    char *b;  
    double *c;  
    float *d;  
    printf("整型指针变量的长度为%d\n", sizeof(a));  
    printf("字符型指针变量的长度为%d\n", sizeof(b));  
    printf("双精度浮点型指针变量的长度为%d\n", sizeof(c));  
    printf("单精度浮点型指针变量的长度为%d", sizeof(d));  
	return 0;
} 
