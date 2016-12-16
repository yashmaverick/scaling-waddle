#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t!=0)
	{
	int *a,n,i,max,min,d;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);

		if(i==0)
		{
			min=i;
			max=i;
			d=0;
			
		}
		if(a[i]<a[min])
		{
			min=i;
			max=i;
		}
		if(a[i]>a[max])
		{
			max=i;
			
		}
		if(max>min && a[max]-a[min]>d)
			d=a[max]-a[min];
	}
	
	if(max==0 || max<min)
		printf("0\n");
	else
	printf("%d\n",d);
	t--;
	}
	return 0;
}

