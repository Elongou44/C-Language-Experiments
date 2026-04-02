#include<stdio.h>
int main() {
	char a[] = "a1a2a3a4";  
	char *p = a;
    while( *p != '\0') {
    	if( *p == 'a') 
    	*p = 'b';
    	p++;
	}
	printf("%s", a);
	return 0;
} 
