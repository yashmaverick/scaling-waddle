#include<stdio.h>
int min(int *a,int c,int b);
int main()
{
	int t,n,k,i,p,a[10007],q,o;
		scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&k);
		for(p=0;p<n;p++)
		{
			scanf("%d",&a[p]);
		}
		q=min(a,0,k-1);
		if(n==k)
		printf("%d\n",q);
		else
			printf("%d ",q);
		for(o=1;o<=n-k;o++)
		{
			if(a[o-1]==q)
			{
				q=min(a,o,o+k-1);
			}
			else if(a[o+k-1]<q)
			{
				q=a[o+k-1];
			}
			if(o!=n-k)
			printf("%d ",q);
			else
				printf("%d\n",q);

		}

	}
	return 0;
}
int min(int *a,int c,int b)
{
	int mi,i;
       	mi=a[c];
	//printf(";;%d;;",mi);
	for(i=c;i<=b;i++)
	{
		if(a[i]<mi)
		{
			mi=a[i];
		}
	}
	
	return mi;
}
