#include<stdio.h> 
#include<math.h>
int main()
{
    float fz=1,fm=1,x,s,i;
	scanf("%f",&x);
	if(x<=1)
	printf("error");
	else
	{
		for(i=1;fabs(fz/fm)>(1e-5);i++)
		{
		fz=-i*pow(-1,i);
		fm=pow(x,i-1);
		s+=(fz/fm);
	    }
	}
	printf("%f",s);
	return 0;
} 
