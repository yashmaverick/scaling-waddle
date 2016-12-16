#include<stdio.h>
int a[1005];
void qusort(int sp,int ep)
{
	if(sp>=ep)
		return;
	int pivot=a[sp];
	int wall=sp,i;
	for(i=sp+1;i<=ep;i++)
	{
		if(a[i]<pivot)
		{
			int temp=a[i];
			wall++;
			a[i]=a[wall];
			a[wall]=temp;
		}
	}
	int temp=a[wall];
	a[wall]=a[sp];
	a[sp]=temp;
	qusort(sp,wall-1);
	qusort(wall+1,ep);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		long long k;
		scanf("%d %lld",&n,&k);
		for(i=0;i<n;i++)
		{
			char c[10000];
			scanf("%s",c);
			scanf("%d",&a[i]);
		}
		int flag=0;
		qusort(0,n-1);
//		for(i=0;i<n;i++)
//			printf("%d",a[i]);
		for(i=0;i<n-2;i++)
		{
			int j=i+1;
			int m=n-1;
			while(j<m)
			{
				long long sum=a[i]+a[j]+a[m];
				if(sum==k)
				{
					flag=1;
					break;
				}
				else if(sum>k)
					m--;
				else
					j++;
			}
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

