#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * a,const void * b)
{
	return ( *(int*)a - *(int*)b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int a[n];
		int i,j,l;
		char s[1000];
		for(i=0;i<n;i++)
			scanf("%s %d",s,&a[i]);

		qsort(a,n,sizeof(int),cmpfunc);
		/*
		   for(i=0;i<n;i++)
		   printf("%d ",a[i]);
		   printf("\n");
		 */
		int flag=0;
		for(i=0;i<n-2;i++)
		{
			j=i+1;
			l=n-1;
			while(j<l)
			{if(a[j]+a[i]+a[l]==k)
				{	flag=1;
					break;
				}
				else if(a[j]+a[i]+a[l]<k)
					j++;
				else
					l--;
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



