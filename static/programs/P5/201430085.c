#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc(const void * a,const void * b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int x,y;
	scanf("%d",&x);
	for(y=0;y<x;y++)
	{
		int n,m,i,a[10000],p,q,r,j,k,flag=0;
		char s[10000];
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s %d",&s,&a[i]);
		qsort(a,n,4,cmpfunc);
		for(i=0;i<n;i++)
		{
			p=a[i];
			j=i+1;
			k=n-1;
			while(k>j && flag==0)
			{
				q=a[j];
				r=a[k];
				if((p+q+r)==m)
					flag=1;
				else if((p+q+r)>m)
					k--;
				else if((p+q+r)<m)
					j++;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else if(flag==0)
			printf("NO\n");
	}
	return 0;
}
