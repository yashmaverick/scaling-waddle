#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n,stock[100005];
    int i,j,k,l;
    int max,min,diff;
    int flag=0;

    for(i=0;i<t;i++)
    {
	flag=0;
	scanf("%d",&n);
	scanf("%d",&stock[0]);
		min=max=stock[0];
		diff=0;
	for(j=1;j<n;j++)
	{
	    scanf("%d",&stock[j]);
	    if(stock[j]>max||flag==1)
	    {
		max=stock[j];
		if((max-min)>diff)
		diff=max-min;
	//	printf(" MAX %d DIFF %d MIN %d ",max,max-min,min);
	    }
	    if (stock[j]<min)
	    {
	//	printf("MIN: %d\n",min);
		min=stock[j];
		flag=1;
	    }
	}
	printf("%d\n",diff);
    }
    return 0;
}
