#include<stdio.h>
#include<math.h>
float fact(int a){   
    int n;
	double sum = 1;
	for(n = 1;n <= a;n++)
		sum = sum * n;
	return sum;
}
int main(){   
    int i=1;
	double x, j, s=0;
	scanf("%lf",&x);
	j = x;
	while(fabs(j) >= 0.00001){   
	    s = s + j;
	    i++;
		j = pow(x,i) / fact(i);	
	}
	printf("%lf",s);
	return 0;
}
