#include<stdio.h>
long long int f[100005],s[100005],t[100005];
int main()
{
    long long int test;
    int i,j;
    //int f[100005],s[100005],t[100005];
    long long int p,q,r;
    long long int mid;
    long long int indexs;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
	scanf("%lld",&p);
	for(j=0;j<p;j++)
	    scanf("%lld",&f[j]);
	scanf("%lld",&q);
	for(j=0;j<q;j++)
	    scanf("%lld",&s[j]);
	scanf("%lld",&r);
	for(j=0;j<r;j++)
	    scanf("%lld",&t[j]);
	indexs=0;
	long long int limit;
	long long int posf=0,post=0;
	long long int start;
	long long int end;
	long long int total=0;
	while(indexs<q)
	{
	    posf=0;
	    post=0;
	    if(indexs>p-1)
		limit=p-1;
	    else
		limit=indexs;
	    start=0;
	    end=limit;

	    while(start<=end)
	    {
		mid=(start+end)/2;
		if(f[mid]<=s[indexs]&& (f[mid+1]>s[indexs] | mid==limit))
		{
		    //if(f[mid+1]<=s[indexs] && mid==limit)
		    posf=mid+1;

		    //  else
		    //	posf=mid+2;
		    break;
		}
		else if (f[mid]>s[indexs])
		    end=mid-1;
		else
		    start=mid+1;
	    }
	    start=indexs;
	    end=r-1;
	    while(start<=end)
	    {
		mid=(start+end)/2;
		if((t[mid]<=s[indexs] | mid==indexs)&&(t[mid+1]>s[indexs] | mid+1==r))
		{

		    if(mid+1==r && (t[mid]>s[indexs] && mid!=indexs))
			post=0;
		    else
			post=r-mid;
		    break;
		}
		else if(t[mid]<s[indexs])
		    start=mid+1;
		else
		{
		    if(start==end | mid-1<start)
		    {
			post=r-mid;
			break;
		    }
		    end=mid-1;
		}
	    }
	    total+=(posf*post);
	    indexs++;
//	    printf("%d %d %d\n",posf,post,indexs);
	}
	printf("%lld\n",total);
    }
    return 0;
}

