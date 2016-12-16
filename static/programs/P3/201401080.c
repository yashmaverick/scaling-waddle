#include<stdio.h>
int main()
{
	int i,j,t,n,max;
	scanf("%d",&t);
		for(i=0;i<t;i++)
		{
			scanf("%d",&n);
			int a[100000],b[100000];
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[j]);
				b[j]=a[j];
			}
			max=b[0]-a[0];
			for(j=1;j<n;j++)
			{
				if(a[j-1]<a[j])
					a[j]=a[j-1];
				if(b[n-j-1]<b[n-j])
					b[n-j-1]=b[n-j];

				if(max<b[j]-a[j])
					max=b[j]-a[j];
			}
			printf("%d\n",max);
		}
	return 0;
}
