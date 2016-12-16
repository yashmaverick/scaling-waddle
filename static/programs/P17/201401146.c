#include<stdio.h>
#include<string.h>
int L[100001]={0},R[100001]={0},ind[100001]={0},pre[100001];
int vis[100001]={0},par[100001]={0};
int n,p=0;
void Make_tree(int res_L,int res_R,int k)
{
	int I=ind[pre[k]];
	if(I-res_L>0)
	{
		L[pre[k]]=pre[k+1];
		Make_tree(res_L,I-1,k+1);
	}
	if(res_R-I>0)
	{
		R[pre[k]]=pre[k+I-res_L+1];
		Make_tree(I+1,res_R,k+I-res_L+1);
	}
	return;
}
/*void print_T()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("L:%d-->%d ",pre[i],L[pre[i]]);
		printf("R:%d-->%d\n",pre[i],R[pre[i]]);
	}
	return;
}*/
void DFS(int x)
{
	if(vis[x])
		return;
	vis[x]=1;
	if(L[x])
	{
		par[L[x]]=x;
		DFS(L[x]);
	}
	if(R[x])
	{
		par[R[x]]=x;
		DFS(R[x]);
	}
	return;
}
int main()
{
	int i,j,x,t,a,b;
	scanf("%d",&n);
	int mark[n+1];
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		ind[x]=i;
	}
	Make_tree(0,n-1,0);
	//print_T();
	//printf("\n");
	DFS(pre[0]);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		memset(mark,0,sizeof(mark));
		while(a)
		{
			mark[a]=1;
			a=par[a];
		}
		while(b)
		{
			if(mark[b]==1)
			{
				printf("%d\n",b);
				break;
			}
			b=par[b];
		}
	}
	return 0;
}
