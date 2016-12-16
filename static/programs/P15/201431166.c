#include<stdio.h>

int cmp(const void *c,const void *b)
{
	return (*(int*)c-*(int*)b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int a[n],i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int flag=0,l,j=0;
		int ans,count1=0,count2=0,count3=0;
		ans=a[0];
		count1++;
		count3++;
		if(n==1)
			printf("%d",ans);
		else if(n==2)
		{
			if(k==1)
			{
				printf("%d ",a[0]);
				printf("%d",a[1]);
			}
			if(k==2)
			{
				if(a[0]>a[1])
					printf("%d",a[1]);
				else
					printf("%d",a[0]);
			}
		}
		else if(k==1)
		{
			for(i=0;i<n-1;i++)
				printf("%d ",a[i]);
			printf("%d",a[n-1]);
		}
		else if(n==k)
		{
			qsort(a,n,sizeof(int),cmp);
			printf("%d",a[0]);
		}
		else
		{
			for(i=1;i<n;i++)
			{
				if(count3==k && flag==0)
				{
					printf("%d ",ans);
					count3=0;
					flag=1;
				}
				count1++;
				count3++;
				if(count1 < k+1)
				{
					if(a[i]<=ans)
					{
						ans=a[i];
						j=i;
					}
				}
				else 
				{
					if(j>=i-k+1 && j<i)
					{
						if(a[j]>=a[i])
						{
							ans=a[i];
							j=i;
						}
					}
					else
					{
						ans=a[i];
						for(l=i-1;l>=i-k+1;l--)
						{
							if(ans>=a[l])
							{	
								ans=a[l];
								j=l;
							}
						}
					}
					printf("%d",ans);
					if(i!=n-1)
						printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}




