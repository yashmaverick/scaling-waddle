#include<stdio.h>
long long int a[1000005], b[1000005],c[1000005];
long long int binarysearch(long long int start, long long int end, long long int i)
{
//	printf("-1");
	long long int mid;
	mid=(start+end)/2;
	if(c[mid]>=b[i])
	{
		if(mid==i)
		{
			return mid;
		}
		else if(c[mid-1]<b[i])
		{
			return mid;
		}
		else 
		{
//			printf("99932893472");
			binarysearch(start,mid-1,i);
		}
	}
	else
	{
		if(mid==end)
		{
			return mid+1;
		}
		else
		{
			binarysearch(mid+1,end,i);
		}
	}
}
long long int binarysearch2(long long int start, long long int end, long long int i)
{
//	printf("-1");
	long long int mid;
	mid=(start+end)/2;
	if(b[mid]>=a[i])
	{
		if(mid==i)
		{
			return mid;
		}
		else if(b[mid-1]<a[i])
		{
			return mid;
		}
		else 
		{
//			printf("99932893472");
			binarysearch2(start,mid-1,i);
		}
	}
	else
	{
		if(mid==end)
		{
			return mid+1;
		}
		else
		{
			binarysearch2(mid+1,end,i);
		}
	}
}

int main()
{
	long long int i,j,k,l,test,alen,blen,clen,t,start,end;
	scanf("%lld", &test);	
	for(t=0;t<test;t++)
	{

		long long int tot=0,count=0;
		long long int d[1000005];
		count=0;
		scanf("%lld", &alen);
		for(i=0;i<alen;i++)
		{
			scanf("%lld", &a[i]);
		}
		scanf("%lld", &blen);
		for(i=0;i<blen;i++)
		{
			scanf("%lld", &b[i]);
		}
		scanf("%lld", &clen);
		for(i=0;i<clen;i++)
		{
			scanf("%lld", &c[i]);
		}
		for(i=0;i<blen;i++)
		{
			start=i;
			end=clen-1;
			if(i>=clen)
			{
				blen=i;
				break;
			}
			j=binarysearch(start,end,i);
			count=j;
			if(i>=clen)
			{
				blen=i;
				break;
			}
			d[i]=d[i-1]+clen-count;	
		//	printf("%lld ", d[i]);
		}
	//	printf("\n");
		for(i=0;i<alen;i++)
		{
			start=i;
			end=blen-1;
			if(i>=clen || i>=blen)
				break;
		//	printf("i=%lld\n", i);
			j=binarysearch2(start,end,i);
		//	printf("j=%lld\n",j);
			count=j-1;
		//	printf("%lld\n", count);
			tot=tot+d[blen-1]-d[count];
		//	printf("%lld\n", tot);
		}
		printf("%lld\n",tot);
	}
	return 0;
}
				
