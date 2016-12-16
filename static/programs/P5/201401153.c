#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void * p,const void * q)
{
	return ( *(int*)p - *(int*)q );
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d\n",&n,&k);
		int a[n],i,j,sum=0,flag=0,x,y;
		char s[100];
		for(i=0;i<n;i++)
		{
			scanf("%s %d",s,&a[i]);
		}
		qsort(a,n,sizeof(int),cmpfunc);
//		for(i=0;i<n;i++)
//			printf("%d ",a[i]);
//		printf("\n");
		for(i=0;i<n;i++)
		{

			for(x=i+1,y=n-1;x<y;)
			{
				if((a[i]+a[x]+a[y])<k)
					x++;
				else if((a[i]+a[x]+a[y])>k)
					y--;

				if((a[i]+a[x]+a[y])==k && x!=y)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
