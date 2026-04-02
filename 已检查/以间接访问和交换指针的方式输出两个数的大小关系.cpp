#include <stdio.h>
void compare(int *x, int *y) {
	if (*x < *y)   
        printf("a < b\n");  
    else if (*x > *y)   
        printf("a > b\n");  
    else   
        printf("a = b\n");
}
int main() {  
    int a = 10, b = 20;  
    int *p1= &a, *p2= &b;
    printf("交换前\n");
    printf("a = %d,b = %d,", a, b); 
    compare(p1, p2);
    int temp = *p1;  
    *p1 = *p2;  
    *p2 = temp; 
    printf("交换后\n");
    printf("a = %d,b = %d,", a, b); 
	compare(p1, p2);   
    return 0;  
}
