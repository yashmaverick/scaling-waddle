#include<stdio.h>
int size[1000099];
int r[1000099];
int s[1000099];
int t[1000099];
void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	temp=r[i];
	r[i]=r[j];
	r[j]=temp;
	temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}
void quick_sort(int a[],int low,int high)
{
	if(low>=high)
		return;
	int pivot=high;
	int i,j;
	j=low;
	for(i=low;i<pivot;i++)
	{
		if(a[i]<a[pivot])
		{
			swap(a,i,j);
			j++;
		}
	}
	swap(a,j,pivot);
	quick_sort(a,low,j-1);
	quick_sort(a,j+1,high);
}
int p[1000099];
int root(x)
{
	if(p[x]==x)
		return x;
	p[x]=root(p[x]);
	return p[x];
}
int main()
{
	int m,n,i;
	scanf("%d %d",&m,&n);
	int u,v,w;
	long long int count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		r[i]=u;
		s[i]=v;
		t[i]=w;
	}
	quick_sort(t,0,n-1);
	for(i=1;i<=m;i++)
	{
		p[i]=i;
		size[i]=1;
	}
	for(i=0;i<n;i++)
	{
		if(root(r[i])!=root(s[i]))
		{
			if(size[root(s[i])]>size[root(r[i])])
			{
				size[root(s[i])]+=size[root(r[i])];
				p[root(r[i])]=root(s[i]);
			}
			else
			{
				size[root(r[i])]+=size[root(s[i])];
				p[root(s[i])]=r[i];
			}
			count+=t[i];
		}
	}
	if(size[root(r[0])]!=m)
		printf("-1\n");
	else
	printf("%lld\n",count);
	return 0;
}
