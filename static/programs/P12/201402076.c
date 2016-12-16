#include<stdio.h>
#define LL long long
int a[500023],b[500023],c[500023];
int n;
long long ans;
void input()
{

	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	a[n+1]=0;
	a[0]=0;
}
void process()
{
	int i;
	
	b[1]=0;
	for(i=2;i<=n;i++)
	{
		int temp=i-1;
		while(a[temp]<a[i]&&temp>=1)
			temp=b[temp];
		b[i]=temp;
	}
	c[1]=0;
	for(i=2;i<=n;i++)
	{
		int temp=i-1;
		while(a[temp]<=a[i]&&temp>=1)
			temp=c[temp];
		c[i]=temp;
	}
	ans=0;
/*	for(i=1;i<=n;i++)
		printf("%d ",b[i]);
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%d",c[i]);
	printf("\n");
*/
	for(i=2;i<=n;i++)
	{
		long long temp;
		ans+=(i-1);
		temp=i-1;
		while(temp>=c[i])
		{
			if(temp==c[i])
			{
				if(c[i]!=0)
					ans--;
				break;
			}
			temp=b[temp];
			ans--;
		}
//		printf("%lld\n",ans);
	}


}
void output()
{
	printf("%lld\n",ans);
}

int main()
{
	scanf("%d",&n);
	while(n!=0)
	{
		input();
		process();
		output();
		scanf("%d",&n);
	}
	return 0;
}


