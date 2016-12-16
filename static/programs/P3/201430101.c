#include<stdio.h>
#include<stdlib.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int temp,temp2,n,i,flag=0,maxsum=0,sum;
		scanf("%d",&n);
		int *a=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i-1] && flag==0)
			{
				temp=a[i-1];
				temp2=a[i];
				flag=1;
				i++;
				maxsum=temp2-temp;
				
			}
			if(flag==1)
			{
				if(a[i]<temp)
				{
					temp=a[i];
				}
				temp2=a[i];
				sum=temp2-temp;
				if(sum>maxsum)
				maxsum=sum;
			}
		}
		printf("%d\n",maxsum);
	}
	return 0;
}
