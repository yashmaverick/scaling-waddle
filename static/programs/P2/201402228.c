#include<stdio.h>
int bisearch(long long int a[],int l,int h,int x,int f)
{
	int mid,c=0;
	if(l<=h)
	{
		mid=(l+h)/2;
		if(x==a[mid])
		{
			c=1;
			if(x==a[mid+1] && f==0)
			{
				return bisearch(a,mid+1,h,x,f);
			}
			else if(x==a[mid-1] && f==1)
				return bisearch(a,l,mid-1,x,f);
		}
		else if(x<a[mid])
			return bisearch(a,l,mid-1,x,f);
		else
			return bisearch(a,mid+1,h,x,f);
	}
	if(c==1)
		return mid;
	else
		return (l-1);
}

int main()
{
	int t,i,p,q,r,j,l,h,y1,y2,k,e,s;
	long long int a[100001],b[100001],c[100001];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long long int count=0;
		int flag;
		int count1,count2;
		scanf("%d",&p);
		for(j=0;j<p;j++)
			scanf("%lld",&a[j]);
		scanf("%d",&q);
		for(k=0;k<q;k++)
			scanf("%lld",&b[k]);
                scanf("%d",&r);
		for(e=0;e<r;e++)
			scanf("%lld",&c[e]);
		for(j=0;j<q;j++)
		{
			flag=0;
			l=0;
			h=p-1;
			y1=bisearch(a,l,h,b[j],flag);
			l=0;
			h=r-1;
			flag=1;
			y2=bisearch(c,l,h,b[j],flag);
			if(j>=y1 && j<y2)
			{
				count1=y1+1;
				count2=r-y2;
			}
			else if(j>=y1 && j>=y2)
			{
				count1=y1+1;
				if(q<=r)
					count2=r-j;
				else
					count2=0;
			}
			else if(j<y1 && j<y2)
			{
				count1=j+1;
				count2=r-y2;
			}
			else if(j<y1 && j>=y2)
			{
				count1=j+1;
				if(q<=r)
					count2=r-j;
				else
					count2=0;
			}
			count=count+(count1*count2);
		}
		printf("%lld\n",count);
	}
	return 0;
}
















