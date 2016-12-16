#include<stdio.h>
int b[100000],maxd=-1,min=100001,mind=-1;
void func(int a[],int lo,int hi,int d)
{
	if(lo>hi)
		return;
	if(lo==hi)
	{
		if(d>=maxd)
		{	
			maxd=d;
			if(mind==d)
			{
				if(a[lo]<min)
					min=a[lo];
			}
			else
				min=a[lo];
			mind=d;
		}
	}
	if(b[hi]==-1)
		func(a,lo,hi-1,d+1);
	else
	{
		func(a,lo,b[hi],d+1);
		func(a,b[hi]+1,hi-1,d+1);
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mind=maxd=-1;
		min=100001;
		int n,i,j;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[0]=-1;
		for(i=1;i<n;i++)
		{
			j=i-1;
			if(a[j]<a[i])
				b[i]=j;
			else
			{
				while(b[j]!=-1)
				{
					if(a[b[j]]<a[i])
					{
						b[i]=b[j];
						break;
					}
					else
						j=b[j];
				}
				if(b[j]==-1)
					b[i]=-1;	
			}
		}
		func(a,0,n-1,0);
		printf("%d %d\n",min,maxd);
	}
	return 0;
}
