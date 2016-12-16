#include<stdio.h>
long long int b_search(long long int s[],long long int low,long long int high,long long int key)
{
	long long int mid;
	mid=(low+high)/2;
	if(low>high)
	{
		//printf("key not found\n");
		return -1;
	}
	if((key<=s[mid] && key>s[mid-1]) || (key<=s[mid] && low==mid))
	{
		return mid;
	}
	else if(key<=s[mid] && key==s[mid-1])
		return mid-1;

	else if(s[mid]>key)
		b_search(s,low,mid-1,key);
	else if(s[mid]<key)
		b_search(s,mid+1,high,key);
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int p,q,r,i,j,count=0,x,y;
		scanf("%lld",&p);
		long long int a[p];
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		long long int b[q];
		long long int e[q];
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		long long int c[r];
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		for(j=0;j<q;j++)
		{
			y=b_search(c,j,r-1,b[j]); //printf("y is %lld\n",y);
			if(y==-1)
				e[j]=0;
			else
			e[j]=(r-y); //printf("e[j] is %lld\n",e[j]);
		}
		for(j=q-1;j>=1;j--)
		{
			e[j-1]=e[j-1]+e[j]; //printf("modified e[j] is %lld\n",e[j-1]);
		}
		for(j=0;j<p;j++)
		{
			x=b_search(b,j,q-1,a[j]); //printf("x is %lld\n",x); printf("corres e[x] is %lld\n",e[x]);
			if(x!=-1)
				count+=e[x];
		}
		printf("%lld\n",count);
	}
	return 0;
}
