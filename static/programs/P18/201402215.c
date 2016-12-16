#include<stdio.h>
#include<stdlib.h>
int count=0,n,visited[1001],won[1001],matches=0;
struct node{
	int val;
	int a[1001];
};
typedef struct node node;
void bfs(node k[],int j)
{
	int i;
	/*if(won[w]==1)
	  {
	  won[w]=0;
	  return ;
	  }*/
	if(k[j].val==0)
		return ;

	else
	{
		//		printf("visited %d\n",visited[j]);
		for(i=0;i<k[j].val;i++)
		{
			//	printf("visited in array %d\n",visited[k[j].a[i]]);
				if(matches==n-1)
					return;
			if(visited[k[j].a[i]]==0)
			{
				//		printf("match b/w %d and %d\n",j,k[j].a[i]);
				visited[k[j].a[i]]=1;
				matches++;
				if(matches==n-1)
					return;
				if(won[k[j].a[i]]==0)
					bfs(k,k[j].a[i]);
				else
				{	
					matches=n-1;
					won[j]=1;
					return ;
				}
			} 
		}
		//	visited[j]=0;
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		int i,j,m,x;
		node k[1001];
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			k[i].val=0;
			won[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			//k[i].now=m;
			//	k[i].a=(int *)malloc(m*sizeof(int));
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);

				//	printf("%d ",k[x].next);
				//	k[x].next=NULL;
				//	printf("%d\n",i);
				k[x].a[k[x].val]=i;
				k[x].val++;
				//printf("%d %d\n",x,k[x].next->val);
				//print(k[x].next);
			}
			//	k[x].a[j]=-1;
			//		for(j=1;j<=n;j++)
			//			print(k[j].next);
			//printf("\n");
		}
		/*		for(j=1;j<=n;j++)
				{
				printf("%d ",j);
				for(i=0;i<k[j].val;i++)
				printf("%d ",k[j].a[i]);
				printf("\n");
				}*/
		for(j=1;j<=n;j++)
		{
			//	printf("starting with warrior %d\n",j);
			for(i=0;i<1001;i++){
				visited[i]=0;
			}
			matches=0;
			visited[j]=1;
			if(k[j].val!=0)	
				bfs(k,j);
			if(matches==n-1)
			{	
				
					count++;
					//printf("winner is %d\n",w);
					won[j]=1;
			}
		}
		printf("%d\n",count);

	}
	return 0;
}

