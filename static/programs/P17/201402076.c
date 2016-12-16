#include<stdio.h>
int n;
int pre[100005],in[100005];
int preb[100005],inb[100005];
void input()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
}

void precompute()
{
	int i;
	for(i=0;i<n;i++)
		preb[pre[i]]=i;
	for(i=0;i<n;i++)
		inb[in[i]]=i;
}
int compute(int a,int b)
{
	int c=inb[a];
	int d=inb[b];
	int i;
	for(i=0;i<n;i++)
	{
		int temp=inb[pre[i]];
		if(c<=temp&&temp<=d)
			return pre[i];
	}

}
int main()
{
	input();
	precompute();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int ans;
		if(a==b)
		{
			printf("%d\n",a);
			continue;
		}
		if(inb[a]<=inb[b])
			ans=compute(a,b);
		else 
			ans=compute(b,a);
		printf("%d\n",ans);
	}
	return 0;
}
