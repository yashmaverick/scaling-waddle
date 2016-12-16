#include<stdio.h>
int c,p;
int a[1001][1001],s[1001]={0};
int new[1001][1001];
int size[1001];
int vid[1001]={0};
void dfs(int x,int arr[][1001],int y,int chk)
{
	//		printf("@@%d@@\n",x);
	int i;
	for(i=0;i<y;i++)
	{	if(vid[arr[x][i]]==0)
		{
			vid[arr[x][i]]=1;
			c++;
			if(chk==1)
			{
				dfs(arr[x][i],arr,size[arr[x][i]],chk);
			}
			else
			{
				dfs(arr[x][i],arr,s[arr[x][i]],chk);
			}
		}
	}					
}    

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i,j;p=0;int no;
		int flag=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&size[i]);
			for(j=0;j<size[i];j++)
			{
				scanf("%d",&a[i][j]);
				new[a[i][j]][s[a[i][j]]]=i;
				s[a[i][j]]++;
			}
		}
		/*	for(i=1;i<=n;i++)
			{
			k=0;
			for(j=1;j<=n;j++)
			{
			if(b[j][i]==1)
			{
			new[i][k]=j;
			k++;
			}
			}
			}*/

		//		for(i=1;i<=n;i++)
		//		{
		//			printf("\n");
		//			for(j=0;j<n;j++)
		//			{
		//				printf("%d ",new[i][j]);
		//			}
		//		}
		//		printf("\n");
		//		for(i=1;i<=n;i++)
		//			printf("%d\n",s[i]);
		for(i=1;i<=n;i++)
		{
			c=0;
			vid[i]=1;
			dfs(i,new,s[i],0);
			//		printf("$%d$\n",c);
			if(c==n-1)
			{
				no=i;
				flag=1;
			}
			for(j=0;j<=n;j++)
				vid[j]=0;
			if(flag==1)
				break;
		}
		//	printf("#%d#\n",no);
		c=1;
		if(flag==1)
		{	
			vid[no]=1;
			dfs(no,a,size[no],1);
			//			printf("$%d$\n",c);
			p+=c;
			printf("%d\n",p);
		}
		else
			printf("0\n");
		for(i=0;i<1001;i++)
		{
			s[i]=0;vid[i]=0;}
	}
	return 0;
}
