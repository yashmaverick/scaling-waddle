#include<stdio.h>
int visited[10001]={0};
int n;
//int a[1001][1001]={{0}},b[1001][1001]={{0}};
void dfs1(int index,int a[1005][1005])
{
        if(visited[index]==1)
                return;
                visited[index]=1;
                int l;
                for(l=1;l<=n;l++)
                {
                        if(a[index][l]==1 && visited[l]!=1)
                                dfs1(l,a);
                }
}
void dfs2(int vert,int b[1005][1005])
{
        if(visited[vert]==1)
                return;
                visited[vert]=1;
                int l=1;
                for(l=1;l<=n;l++)
                {
                        if(b[vert][l]==1 && visited[l]!=1)
                                dfs2(l,b);
                }
}

int main()
{
        int t,i,j,k,w,winner,flag;
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
		int a[1005][1005]={{0}},b[1005][1005]={{0}};
		
                scanf("%d",&n);
		for(j=0;j<=n;j++)
			visited[j]=0;
/*		for(j=0;j<=n;j++)
		{
			for(k=0;k<=n;k++)
			{
				a[i][j]=0;
				b[i][j]=0;
			}
		}*/
                for(j=1;j<=n;j++)
                {
                        scanf("%d",&w);
                        for(k=1;k<=w;k++)
                        {
                                scanf("%d",&winner);
                                a[winner][j]=1;
                                b[j][winner]=1;
                        }
                }
                /*for(j=1;j<=n;j++)
                {
                        for(k=1;k<=n;k++)
                                printf("%d ",b[j][k]);
                }*/
                for(k=1;k<=n;k++)
                        visited[k]=0;

                for(j=1;j<=n;j++)
                {
                        flag=0;
                        dfs1(j,a);
                        for(k=1;k<=n;k++)
                        {
                                if(visited[k]!=1)
                                {
                                       flag=1;
				       break;
                                }
                        }
                   //     printf("flag=%d\n",flag);
                        if(flag!=1)
                                break;
                        for(k=1;k<=n;k++)
                                visited[k]=0;

                }
               // printf("j=%d\n",j);
                for(k=1;k<=n;k++)
                        visited[k]=0;
                dfs2(j,b);
                int count=0;
                for(k=1;k<=n;k++)
                {
                        if(visited[k]==1)
                                count++;
                }
                printf("%d\n",count);

        }
        return 0;
}


