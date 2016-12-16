#include<stdio.h>
int main()
{
	int test,n,i,maxpro,j;
	scanf("%d",&test);
	while(test--)
	{
		int spot=0,k;
		maxpro = 0;
		scanf("%d",&n);
		int a[n];
		scanf("%d%d",&a[0],&a[1]);
		int min=(a[0]>a[1])?a[1]:a[0];
		int maxdiff=a[1]-a[0];
		for(i=2;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]-min>maxdiff)
			maxdiff=a[i]-min;
			if(a[i]<min)
			min=a[i];;			
		}
		if(maxdiff<0)
		printf("0\n");
		else
		printf("%d\n",maxdiff);
	}
	return 0;
}
