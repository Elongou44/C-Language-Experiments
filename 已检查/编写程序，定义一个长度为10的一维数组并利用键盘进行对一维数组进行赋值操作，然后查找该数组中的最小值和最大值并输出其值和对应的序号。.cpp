#include<stdio.h>
int main()
{
	int a[10],i,j=0,k=0,max,min;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	max=a[0];
	min=a[0];
	for(i=0;i<10;i++)
    {
    	if(a[i]>max)
    	{max=a[i];
    	 j=i;
		}
		if(a[i]<min) 
		{min=a[i];
		 k=i;
		}
	}
    printf("最大值的序号为%d,其值为%d\n",j,a[j]);
    printf("最小值的序号为%d,其值为%d",k,a[k]);
	return 0; 
}
