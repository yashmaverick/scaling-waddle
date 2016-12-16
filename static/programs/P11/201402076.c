#include<stdio.h>
#define LL long long
int a[100023],b[100023],c[100023];
int n;
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
	b[n]=n+1;
	for(i=n-1;i>=1;i--)
	{
		int temp=i+1;
		while(a[temp]>=a[i])
			temp=b[temp];
		b[i]=temp;
	}
	c[1]=0;
	for(i=2;i<=n;i++)
	{
		int temp=i-1;;
		while(a[temp]>=a[i])
			temp=c[temp];
		c[i]=temp;
	}
}
void output()
{
	int i;
	long long ans=0;
	for(i=1;i<=n;i++)
	{
		long long temp;
		temp=(b[i]-c[i]-1)*1LL*a[i];
		if(ans<temp)
			ans=temp;
	}
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


