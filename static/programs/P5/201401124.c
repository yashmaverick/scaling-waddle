#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return(*(int*)a - *(int*)b);
}
int main()
{
	int i,j,n,sum,e,k,flag=0,t;
	char a[100000];
	scanf("%d",&t);
	while(t)
	{
		flag=0;
		scanf("%d %d",&n,&e);
		int arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			scanf("%d",&arr[i]);
		}
		qsort(arr,n,sizeof(int),compare);
		//for(i=0;i<n;i++)
		//	printf("%d ",arr[i]);
		int temp=n;
		for(i=0;i<temp;i++)
		{
			if(arr[i]<e)
			{
				j=i+1;k=n-1;
				while(j<k)
				{
					sum=arr[i]+arr[j]+arr[k];
					if(sum==e)
					{
						flag=1;
						break;
					}
					if(sum>e)
						k--;
					else if(sum<e)
						j++;
				}
			}
			if(flag==1)
				break;
			if(arr[i]>e)
				break;

		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
		t--;
	}
	return 0;
}
