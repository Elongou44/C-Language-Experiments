#include<stdio.h>
#include<string.h>
int main() {
	char a[] = "a1a2a3a4", i;  
	char *p = a;
    for( i = 0; i <= strlen(a); i++) {
    	if( *(p++) == 'a' ) 
    	a[i] = 'b';
	}
	printf("%s", a);
	return 0;
} 
