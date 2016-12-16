#include<stdio.h>
#include<stdlib.h>
int a[1000000];
int f( const void * a, const void * b)
{return (*(int*)a - *(int*)b );
}
int main()
{
	int e,f1;
	scanf("%d",&e);
	for(f1=0;f1<e;f1++)
	{
		int n,i,t,j,k,flag=0,ansh;
		scanf("%d%d",&n,&t);
		char v[100000];
		for(i=0;i<n;i++)
		{scanf("%s%d",v,&a[i]);}
		qsort(a,n,sizeof(int),f);
		for(i=0;i<n;i++)
		{
			j=i+1;
			k=n-1;
			while(j<k)
			{
				ansh=a[i]+a[j]+a[k];
				if(ansh==t)
				{
					flag=1;
					break;
				}
				if(ansh<t)
				{
					j++;
				}
				if(ansh>t)
				{
					k--;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
