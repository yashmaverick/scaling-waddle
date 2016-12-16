#include<stdio.h>
#include<stdlib.h>
int check(int a[],int n,int k);
int cmpfunc(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int main()
{
	int i,j,t,n,k,a[100005];
	char str[1000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)
			scanf("%s%d",str,&a[j]);
		qsort(a,n,sizeof(int),cmpfunc);
		if(check(a,n,k))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
int check(int a[],int n,int k)
{
	int j,r,l;
	for(j=0;j<n-1;j++)
	{
		l=j+1;
		r=n-1;
		while(l<r)
		{
			if(a[j]+a[l]+a[r]==k)
				return 1;
			if(a[j]+a[l]+a[r]>k)
				r--;
			else
				l++;
		}
	}
	return 0;
}
