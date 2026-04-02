#include <stdio.h>
int main() 
{int i,j,k;
i=1;
do{for(j=1;j<=20-i;j++) 
  {
  printf(" ");}
  for(k=1;k<=2*i-1;k++)
  {
  printf("*");}
  printf("\n");
  i++;
}while(i<=5);
return 0;
}

