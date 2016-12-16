#include<stdio.h>
int main()
{
	int t,m;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		int n,max,small,i;
		scanf("%d",&n);
		if(n==0 || n==1)
		{
			printf("0\n");
			continue;
		}
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		max=a[1]-a[0];
		small=a[0];
		for(i=1;i<n;i++)
		{
			if((a[i]-small)>max)
				max=a[i]-small;
			if(a[i]<small)
				small=a[i];
		}
		if(max>=0)
			printf("%d\n",max);
		if(max<0)
			printf("0\n");
	}
	return 0;
}





