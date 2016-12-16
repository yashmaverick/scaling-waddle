#include<stdio.h>
int test,size,price,i,j,a[100000],profit;
int main()
{
    int k,min,max;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
	profit=0;
	scanf("%d",&size);
	scanf("%d",&a[0]);
	min=a[0];
	max=a[0];
	for(j=1;j<size;j++)
	{
	    scanf("%d",&a[j]);
	    if(a[j]<min)
	    {
		min=a[j];
		max=a[j];
	    }
	    if(a[j]>min && a[j]>max)
	    {
		max=a[j];
	    }
	    if((max-min) > profit )
	    {
		profit= max-min;	
	    }
	}
	printf("%d\n",profit);
    }
    return 0;
}

