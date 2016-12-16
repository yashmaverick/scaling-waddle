#include<stdio.h>
int G[1002][1002]={0},visited[1002],n,count=0;
int xx=0,yy=0;
void DFS(int i)
{
	int j;
	count++;
	if(count==n)
		xx=1;
	visited[i]=1;
//	printf("%d\n",i);
	for(j=1;j<=n;j++){
		if(!visited[j]&&G[i][j]==1)
		{
			DFS(j);
		}}
}
int main()
{
	int i,j,t,no;
	int x;
	scanf("%d",&t);
	while(t--)
	{
		int b[1002][1002];
		scanf("%d",&n);
		int hi,bye;
		for(hi=1;hi<=n;hi++)for(bye=1;bye<=n;G[hi][bye++]=0,b[hi][bye]=1);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&no);
			for(j=1;j<=no;j++)
			{
				scanf("%d",&x);
				G[x][i]=1;
			}
		}
		int gg;
		int sakshi;
		gg=0;
		xx=0;
		count=0;
		for(i=1;i<=n;i++)
			visited[i]=0;
		for(i=1;i<=n;i++){
			count=0;
		for(sakshi=1;sakshi<=n;sakshi++)
			visited[sakshi]=0;
			xx=0;
			DFS(i);
			if(xx){
		//		printf("%d\n",i);
				gg=1;
				break;
			}
		}
		//le(a,b);
		int w,ww;
		for(w=1;w<=n;w++)

		{
			for(ww=1;ww<=n;ww++)
			{	
				b[w][ww]=G[ww][w];
			}
		}
		for(w=1;w<=n;w++){
			for(ww=1;ww<=n;ww++)
			{
				G[w][ww]=b[w][ww];
			}
	}

		count=0;
		int www;
		for(www=1;www<=n;visited[www++]=0);
		if(gg)
		{
//			printf("YES\n");
			DFS(i);
		}
		printf("%d\n",count);}
		return 0;
	}
