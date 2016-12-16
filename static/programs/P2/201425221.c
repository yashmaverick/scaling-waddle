#include<stdio.h>
int bs(int a[],int s,int lo,int hi);
int main()
{
	int t,i,p,q,r,a[100001],b[100001],c[100001],x;
	long long int bc[100001],ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&p);
		for(i=1;i<=p;i++)
			scanf("%d",&a[i]);
		scanf("%d",&q);
		for(i=1;i<=q;i++)
			scanf("%d",&b[i]);
		scanf("%d",&r);
		for(i=1;i<=r;i++)
			scanf("%d",&c[i]);
		for(i=1;i<=q;i++)
		{
			if(i<=r)
			{
				x=bs(c,b[i],i,r);
				if(x!=0)
					bc[i]=r-x+1;
				else if(x==0)
					for(i=i;i<=q;i++)
						bc[i]=0;
			}
			else
				for(i=i;i<=q;i++)
					bc[i]=0;
		}
		for(i=q-1;i>0;i--)
			bc[i]+=bc[i+1];
		ans=0;
		for(i=1;i<=p;i++)
		{
			x=bs(b,a[i],i,q);
			if(x!=0)
				ans+=bc[x];
			else
				if(x==0)
					break;
		}
		printf("%lld\n",ans);
	}	
	return 0;
}
int bs( int a[],int s,int lo,int hi)
{
	int mid=(hi+lo)/2;
	if(a[mid]<s)
	{
		if(mid==hi)
			return 0;
		else
			return bs(a,s,mid+1,hi);
	}
	else
	{
		if(mid==lo)
			return lo;
		else
		{
			if(a[mid-1]<s)
				return mid;
			else 
				return bs(a,s,lo,mid-1);
		}
	}
}
