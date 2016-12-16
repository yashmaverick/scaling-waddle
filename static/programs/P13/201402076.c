#include<stdio.h>
int n,a[100023],b[100023],c[100023],maxdepth,vertex;
struct pair{
	int vert;
	int val;
};
typedef struct pair pair;
void input()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	maxdepth=0;
}
void process()
{
	int i;
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		int temp=i-1;
		while(a[temp]>a[i])
			temp=b[temp];
		b[i]=temp;
	}
/*	a[0]=500023;
	for(i=1;i<=n;i++)
	{
		int temp=i-1;
		while(a[temp]<a[i])
			temp=c[temp];
		c[i]=temp;
	}*/
}

pair solve(int i,int j)
{
	//printf("%d %d\n",i,j);
	if(i==j)
	{
		pair temp;
		temp.val=0;
		temp.vert=a[i];
		return temp;
	}
	pair temp;
	temp.val=0;
	temp.vert=0;
	if(b[j]>=i)
		c[j]=b[j]+1;
	else
		c[j]=i;
	if(b[j]>=i)
	{
		pair t1=solve(i,b[j]);
		if(temp.val<1+t1.val)
		{
			temp=t1;
			temp.val++;
		}
	}
	if(c[j]<=j-1)
	{
		pair t1=solve(c[j],j-1);
		if(temp.val<1+t1.val)
		{
			temp=t1;
			temp.val++;
		}
	}
	return temp;
}

	
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		input();
		process();
		pair k=solve(1,n);
		printf("%d %d\n",k.vert,k.val);
	}
	return 0;
}
	
