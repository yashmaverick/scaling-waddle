#include<stdio.h>
//int arr[1010][1010];
void  func(int n1,int n,int vis[],int arr[1010][1010])
{

	vis[n1]=1;
	int i=1;
	while(i<=n)
	{
		if(arr[n1][i]==1)
			if(vis[i]==0)
				func(i,n,vis,arr);
		i++;
	}
}
/*void  func1(int n1,int n,int vis1[])
{
	vis1[n1]=1;
	int i=1;
	while(i<=n)
	{
		if(arr[n1][i]==2)
			if(vis1[i]==0)
				func1(i,n,vis1);
		i++;
	}
}*/
int main()
{
	int t,t1;
	scanf("%d",&t);
	for(t1=0;t1<t;t1++)
	{
		int n,n1;
		int b,c;
		scanf("%d",&n);
		int arr[1010][1010],arr1[1010][1010];
		int flag=0;
		for(n1=0;n1<=n;n1++)
			for(b=0;b<=n;b++)
			{
				arr[n1][b]=0;
				arr1[n1][b]=0;
			}
		for(n1=1;n1<=n;n1++)
		{
			scanf("%d",&arr[n1][0]);
			for(b=1;b<=arr[n1][0];b++)
			{
				scanf("%d",&c);
				arr1[n1][c]=1;//2;
				arr[c][n1]=1;
			}
		}
//		for(n1=1;n1<=n;n1++)
//		{
//			for(b=1;b<=n;b++)
//				printf("%d "arr[n1][b]);
//			printf("\n");
//		}
		int ver,flag1=0;
		for(n1=1;n1<=n;n1++)
		{
			int i;
			int vis[1010];
			for(i=0;i<=n;i++)
				vis[i]=0;
			func(n1,n,vis,arr);
			flag=0;
			for(i=1;i<=n;i++)
				if(vis[i]==0)
					flag=1;
			if(flag==0)
			{
				ver=n1;
				flag1=1;
				break;
			}
		}
//		printf("ver=%d",ver);
		if(flag1==1)
		{
			int ans=0;
			int i;
			int count=0;
			int vis1[1010];
			for(i=0;i<=n;i++)
				vis1[i]=0;
			func(ver,n,vis1,arr1);
			for(i=1;i<=n;i++)
				if(vis1[i]==1)
					count++;
			ans+=count;
			printf("%d\n",ans);
		}
		else
			printf("0\n");
	}
	return 0;
}
