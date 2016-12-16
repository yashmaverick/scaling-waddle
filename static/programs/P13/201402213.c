#include<stdio.h>
int a[100010];
int l[100010];
int r[100010];
int stack[100010];
int p[100010];
int maxdepth,ans;
void f(int depth,int index)
{
	if(depth>maxdepth)
	{
		maxdepth=depth;
		ans=a[index];
	}
	if(depth==maxdepth&&a[index]<ans)
		ans=a[index];
	if(l[index]!=-1)
		f(depth+1,l[index]);
	if(r[index]!=-1)
		f(depth+1,r[index]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int top=-1;
		for(i=0;i<n;i++)
		{
			while(top!=-1&&a[stack[top]]>a[i])
				top--;
			if(top==-1)
				l[i]=-1;
			else
				l[i]=stack[top];
			top++;
			stack[top]=i;
			if(i!=0&&a[i-1]>a[i])
			{
				r[i]=i-1;
				p[r[i]]=1;
			}
			else
				r[i]=-1;
		}
		for(i=n-1;i>=0;i--)
		{
			if(l[i]!=-1&&p[l[i]]==1)
				l[i]=-1;
			else
				p[l[i]]=1;
		}
//		for(i=0;i<n;i++)
//			printf("%d ",l[i]);
//		printf("\n");
//		for(i=0;i<n;i++)
//			printf("%d ",r[i]);
		ans=0;maxdepth=-1;
		f(0,n-1);
		printf("%d %d\n",ans,maxdepth);
		for(i=0;i<n;i++)
			p[i]=0;
	}
	return 0;
}
