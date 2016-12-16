#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[100];
		int a[1005],n,k,i,flag=0;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%d",&a[i]);
		}
		qsort(a,n,sizeof(int),cmpfunc);
		//for(i=0;i<n;i++)
		//	printf("%d ",a[i]);
		//printf("\n");
		for(i=0;i<n;i++)
		{
			int first=i+1,last=n-1;
			while(first<last)
			{
				int sum=a[i]+a[first]+a[last];
				if(sum==k)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				else if(sum<k)
					first++;
				else
					last--;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

