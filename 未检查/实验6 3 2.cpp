#include<stdio.h> 
int main()
{   int a[5][6]={{100,100,100,100,100},{99,99,99,99,99},{98,98,98,98,98},{97,97,97,97,97}},i,j;
    for(i=0;i<5;i++)
    a[i][5]=0;
    for(i=0;i<6;i++)
    a[4][i]=0;
    for(i=0;i<4;i++)
    {   a[i][5]=0;
	    for(j=0;j<5;j++)
	    {   a[i][5]+=a[i][j];
		    a[4][j]+=a[i][j];
		    if(j==4)
		    printf("第%d位同学的平均分为%f\n",i+1,(float)a[i][5]/5);
		    if(i==3) 
		    printf("  第%d门课程的平均分为%f\n",j+1,(float)a[4][j]/4);
	    }
    }
	return 0;}
