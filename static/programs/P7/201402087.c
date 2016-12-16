#include<stdio.h>
int a[1000006];

int main()
{
		int t,n;
		int i,j,max,td,md,p;
		scanf("%d",&t);
		long long ans;
		while(t--)
		{
				int b[1000006]={};
				scanf("%d",&n);
				ans=0;
				for(j=0;j<n;j++)
						scanf("%d",&a[j]);
				int min = a[0]; 
				for(j=0;j<n;j++)
						if(a[j]<min)
								min=a[j];
				for(j=0;j<n;j++)
				{
						ans += b[a[j]-min];
						b[a[j]-min]++;
				}
				printf("%lld\n",ans);
		}
		return 0;
}
