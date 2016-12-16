#include<stdio.h>
int n,a[10023],b[10023],c[10023],d[10023],k;
void input()
{
	scanf("%d %d",&n,&k);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
}
void process()
{
	int i;
	a[0]=-1;
	for(i=1;i<=n;i++)
	{
		int temp=i-1;
		while(a[temp]>a[i])
			temp=b[temp];
		b[i]=temp;
	}
}
void solve()
{
	int i;
	int min=a[1],ind=1;
	for(i=1;i<=k;i++)
		if(a[i]<=min)
		{
			min=a[i];
			ind=i;
		}
	for(i=1;i<=k;i++)
		if(b[i]>0)
			c[b[i]]=i;
	if(n!=k)
	printf("%d ",min);
	else
	printf("%d", min);
	int j=n-k;
	j++;
	for(i=2;i<=j;i++)
	{
		int z=k+i;
		z--;
		if(a[z]<=min)
		{
			min=a[z];
			ind=z;
			if(i!=j)
			printf("%d ",min);
			else
			printf("%d", min);
			continue;

		}
		c[b[z]]=z;
		if(i-1==ind)
		{
			ind=c[ind];
			min=a[ind];
			if(i!=j)
			printf("%d ",min);
			else
			printf("%d", min);
			continue;
		}
		if(i!=j)
		printf("%d ",min);
		else
		printf("%d", min);
	}
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		input();
		process();
		solve();
	}
	return 0;
}
	
