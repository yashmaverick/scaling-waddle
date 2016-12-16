#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * c, const void * b)
{
   return ( *(int*)c - *(int*)b );
}

int bs(int* a,int l,int b,int k)
{
	int mid;
	while(l<=b)
	{
		mid=(l+b)/2;
		if(a[mid]==k)
			return 1;
		if(a[mid]<k)
			l=mid+1;
		else
			b=mid-1;
	}
	return 0;
}

int main()
{
	int t,n,k,a[1005],i,flag,j,ans;
	char s[100];
	scanf("%d",&t);
	while(t--)
	{
		flag=1;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%d",a+i);
		}
		qsort(a, n, sizeof(int), cmpfunc);
		for(i=0;i<n;i++)
		{
			if(!flag)
				break;
			for(j=i+1;j<n;j++)
			{
				ans=k-(a[i]+a[j]);
				if(bs(a,j+1,n-1,ans))
				{
					flag=0;
					break;
				}
			}
		}
		if(!flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}






