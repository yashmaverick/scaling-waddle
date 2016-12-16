#include<stdio.h>
int main()
{
	int t,n,i,max,tmp;
	int a[100001];
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
                       scanf("%d",&a[i]);

		}
		max=0;
		
		for(i=0;i<n-1;i++)
		{
			if(a[i+1]-a[i]>0)
			{
				if(a[i+1]-a[i]>max)
					max=a[i+1]-a[i];
				tmp=a[i+1];
				a[i+1]=a[i];
				a[i]=tmp;

			}
		}
			printf("%d\n",max);

	}
	return 0;
}
