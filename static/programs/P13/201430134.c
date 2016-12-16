#include<stdio.h>
int A[2][100002];
int s;
void f(int a[],int ans[],int stack[],int n)
{
	int sp=-1;
	int i,j;
	for(i=0;i<n;i++)
	{
	if(sp==-1)
	{
		sp=sp+1;
		stack[sp]=i;
		ans[i]=-1;
	}
	else if(a[i]>a[stack[sp]])
	{
		ans[i]=stack[sp];
		sp=sp+1;
		stack[sp]=i;
	}
	else
	{
		while(sp>=0 && a[i]<=a[stack[sp]])
		{
			sp=sp-1;
		}
		if(sp!=-1)
		{
		ans[i]=stack[sp];
		sp=sp+1;
		stack[sp]=i;}
		else
		{
			ans[i]=-1;
			sp=sp+1;
			stack[sp]=i;
		}

	}
	}
}
/*int bs(int e,int i,int j,int a[])
{
	int p;
	for(p=i;p<=j;p++)
	{
		if(a[p]>e)
		{
			return p;
		}
	}
	return j+1;
}*/
void tr(int start,int end,int a[],int cnt,int ans[])
{
	int x;
	if(start==end)
	{
		A[0][s]=a[start];
		A[1][s++]=cnt;
	//	printf("%d %d\n",A[0][start],A[1][start]);
		return;
	}
	else
	{
		x=ans[end];
		//printf("%d",x);
		if(x!=start-1)
		{
			tr(start,x,a,cnt+1,ans);
		}
		if(x!=end-1)
		{
			tr(x+1,end-1,a,cnt+1,ans);
		}
	}
}
int main()
{
	int t;int n,max,node,i;
	int a[100002],ans[100002],stack[100002];
	scanf("%d",&t);
	while(t>0)
	{
		for(i=0;i<100002;i++)
		{
			A[1][i]=0;
		}
		s=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		f(a,ans,stack,n);
		tr(0,n-1,a,0,ans);
		max=A[1][0];i=0;node=0;
		while(A[1][i]!=0)
		{
			if(A[1][i]>max)
			{
				max=A[1][i];
				node=i;
			}
			i++;
		}
		printf("%d %d\n",A[0][node],max);
		t--;
	}
	return 0;
}

