#include<stdio.h>
#include<stdlib.h>
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
int search (int a[],int d,int beg,int end)
{
	int mid;
	if(beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]==d)
			return d;
		else if(a[mid]>d)
			search(a,d,beg,mid-1);
		else if(a[mid]<d)
			search(a,d,mid+1,end);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		char s[100];
		scanf("%d %d",&n,&k);
		int a[n],i,j,sum,d,flag=0;
		for(i=0;i<n;i++)
			scanf("%s %d",s,&a[i]);
		qsort(a,n,sizeof(int),cmpfunc);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				sum=0;
				sum=a[i]+a[j];
				if(sum>=k)
					break;
				else
				{
					d=search(a,k-sum,j+1,n-1);
					if(d==k-sum)
						flag=1;		
				}
			}
		}
		if(flag==1)
			printf("YES\n");
		if(flag!=1)
			printf("NO\n");
	}
	return 0;
}
