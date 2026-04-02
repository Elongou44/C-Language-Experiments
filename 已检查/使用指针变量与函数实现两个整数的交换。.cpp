#include<stdio.h>
void ec(int *e1, int *e2) {
	int temp;
	temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}
int main() {
	int a = 2, b = 5;
	printf("交换前\na = %d, b = %d\n", a, b);
	int *p1 = &a, *p2 = &b;
	ec(p1, p2);
	printf("交换后\na = %d, b = %d", a, b);
	return 0;
} 
