#include<stdio.h>
int main()
{
	int t,n,k,i,j,min,inx,p;
	int arr[10000],Min[10000];
	scanf("%d",&t);
	while(t--)
	{
		p=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			if(i==0)
				min=arr[0];
			if(i<k)
			{
				if(arr[i]<=min)
				{
					inx=i;
					min=arr[i];
				}	
			}
			if(i==k-1)
				Min[p++]=min;
			if(i>=k)
			{
				if(inx>=i-k+1 && arr[inx]<arr[i])
					Min[p++]=arr[inx];
				else if(inx>=i-k+1 && arr[inx]==arr[i])
				{
					Min[p++]=arr[inx];
					inx=i;
				}
				else
				{
					min=arr[i-k+1];
					for(j=i-k+1;j<=i;j++)
					{
						if(arr[j]<=min)
						{
							inx=j;
							min=arr[j];
						}
					}
					Min[p++]=min;
				}
			}
		}
		for(i=0;i<p;i++)
		{
			if(i<p-1)
				printf("%d ",Min[i]);
			else
				printf("%d",Min[i]);
		}
		printf("\n");
	}
}
