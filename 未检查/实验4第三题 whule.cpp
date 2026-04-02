#include<stdio.h> 
#include<math.h>
int main()
{
	float fz=1,fm=1,x,s=0,i=1;
	scanf("%f",&x);
	if(x<=1)
	printf("error");
	else
	{
		while(fabs(fz/fm)>(1e-5))
		{
			fz=i*pow(-1,i-1);
			fm=pow(x,i-1);
			s=s+(fz/fm);
			i++;
		}
	}
	printf("%f",s);
	return 0;
}
