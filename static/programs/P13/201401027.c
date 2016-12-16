#include<stdio.h>
#include<stdlib.h>
int arr[200000],stack[200000],left[200000],right[200000],prev[200000],depth[200000];
int main()
{
	int tc,i,n,j,head,max,maxi;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		scanf("%d",&n);
		maxi=n;
		max=0;
		stack[0]=left[0]=right[0]=head=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&arr[j]);
			left[j]=right[j]=depth[j]=0;
		}
		for(j=1;j<=n;j++)
		{
			//just min
			while(head>=0 && arr[j]<arr[stack[head]])
				head--;
			if(head==-1)
				stack[++head]=0;
			stack[++head]=j;
			if(head==0)
				left[j]=0;
			else
				left[j]=stack[head-1];
		}
		head=-1;
		for(j=1;j<=n;j++)
		{
			//just max
			while(head>=0 && arr[j]>arr[stack[head]])
				head--;
			if(head==-1)
				stack[++head]=0;
			stack[++head]=j;
			if(head==0)
				right[j]=0;
			else
				right[j]=stack[head-1];
		}
		head=-1;
		for(j=n;j>0;j--)
		{
			if(!depth[left[j]])
				depth[left[j]]=depth[j]+1;
			if(!depth[right[j]])
				depth[right[j]]=depth[j]+1;
		}
		for(j=1;j<=n;j++)
		{
			if(depth[j]>max)
			{
				max=depth[j];
				maxi=j;
			}
			else if(depth[j]==max && arr[j]<arr[maxi])
				maxi=j;
		}
		printf("%d %d\n",arr[maxi],max);
		/*for(j=1;j<=n;j++)
			printf("%d ",left[j]);
		printf("\n");
		for(j=1;j<=n;j++)
			printf("%d ",right[j]);
		printf("\n");*/
	}
	return 0;
}
