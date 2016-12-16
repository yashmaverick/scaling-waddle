#include<stdio.h>
long long a[270012];
long long seg[270000];
long long min(long long a,long long b)
{
	if(a<b)
		return a;
	else
		return b;
}
long long segtree(long long start,long long end,long long root)
{
	if(start>=end)
	{
		seg[root]=a[start];
		return seg[root];
	}
	seg[root]=min(segtree(start,(start+end)/2,2*root+1),
			segtree(((start+end)/2)+1,end,2*root+2));
	return seg[root];
}
long long getval(long long l,long long r,long long ss,long long se,long long index)
{
	if(l<=ss&&r>=se)
		return seg[index];
	if(l>se||r<ss)
		return 1000000001;
	return min(getval(l,r,ss,(ss+se)/2,2*index+1),
			getval(l,r,((ss+se)/2)+1,se,2*index+2));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,k;
		scanf("%lld %lld",&n,&k);
		long long i;
		long long xleaves=3*n;
		for(i=0;i<3*n;i++)
			seg[i]=1000000001;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		segtree(0,n-1,0);
//		for(i=0;i<3*n;i++)
//			printf("%lld ",seg[i]);
		for(i=0;i+k-1<n-1;i++)
			printf("%lld ",getval(i,i+k-1,0,n-1,0));
		printf("%lld",getval(i,i+k-1,0,n-1,0));
		printf("\n");
	}
	return 0;
}
