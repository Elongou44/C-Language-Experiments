#include <stdio.h>  
int main() {  
    char a[] = "Hello, world", b, c;  
    char *p = a;
    printf("Hello, world\n请分别输入要修改的某个字符和替代的字符\n");
    b = getchar();
    c = getchar();
	while(*p != '\0') {
		if(*p == b)
        *p = c;   
        p++;
    }
    printf("%s", a);
    return 0;  
}
