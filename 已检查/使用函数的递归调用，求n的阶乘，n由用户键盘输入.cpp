#include<stdio.h>
int aaa(int t) {  
    if(t == 0)
        return 1;
    else
        return t * aaa(t-1);
}  
int main() {  
    int n, a;
    scanf("%d",&n);
    a = aaa(n);
    printf("%dµÄ½×²ã:%d",n,a);
    return 0;  
}
