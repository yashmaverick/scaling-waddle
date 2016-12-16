#include<stdio.h>
int main()
{
	int t,max,n,i,a[100004],min,diff;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	//min=a[0];
	diff=0;
	max=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>min)
		{
			diff=a[i]-min;
			if(diff>max)
				max=diff;
		}
	}
	printf("%d\n",max);
	}
	return 0;
}
