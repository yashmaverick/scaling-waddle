#include<stdio.h>
int main()
{
	int t;int a[10002];
	scanf("%d",&t);int min;
	while(t>0)
	{
		int cnt=0;
		int l[10002]={0};
		int r[10002]={0};
		int i,j;int n,k;int mod;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(cnt%k==0)
			{
				min=a[i];
				l[i]=a[i];cnt++;
			}
			else if(a[i]<min)
			{
				l[i]=a[i];
				min=a[i];cnt++;
			}
			else
			{
				l[i]=min;
				cnt++;
			}
		}
		mod=n%k;
		min=a[n-1];
		for(i=n-1;i>=n-mod;i--)
		{
			if(a[i]<min)
			{
				min=a[i];
				r[i]=min;
			}
			else
			{
				r[i]=min;
			}
		}
		cnt=0;
		for(i=n-mod-1;i>=0;i--)
		{
			if(cnt%k==0)
			{
				min=a[i];
				r[i]=min;
				cnt++;
			}
			else if(a[i]<min)
			{
				min=a[i];
				r[i]=min;
				cnt++;
			}
			else
			{
				r[i]=min;
				cnt++;
			}
		}
		/*for(i=0;i<n;i++)
		{
			printf("l=%d  r=%d\n",l[i],r[i]);
		}*/
		for(i=0;i<n-k;i++)
		{
			if(l[i+k-1]<r[i])
			{
				printf("%d ",l[i+k-1]);
			}
			else
			{
				printf("%d ",r[i]);
			}
		}
		for(i=n-k;i<=n-k;i++)
		{
			if(l[i+k-1]<r[i])
			{
				printf("%d",l[i+k-1]);
			}
			else
			{
				printf("%d",r[i]);
			}
		}
		printf("\n");
		t--;
	}
	return 0;
}


			


