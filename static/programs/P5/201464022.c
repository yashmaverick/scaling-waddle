#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
	return ( *(int*)a - *(int*)b );
}
int findnums(int a[],int n,int sum)
{
	int b,c,i;
	for(i=0;i<n-2;i++)
	{
		b=i+1;
		c=n-1;
		while(b<c)
		{
			if(a[i]+a[b]+a[c]==sum)
			{
				return 1;
			}
			else if(a[i]+a[b]+a[c]<sum)
				b++;
			else
				c--;
		}
	}
	return -1;
}

int main()
{
	int t,i,*a,sum,n;
	char b[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&sum);
		a=malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%s%d",b,&a[i]);
		qsort(a,n,sizeof(int),cmpfunc);
		if(findnums(a,n,sum)==1)
			printf("YES\n");
		else printf("NO\n");
		free(a);
	}
	return 0;
}

