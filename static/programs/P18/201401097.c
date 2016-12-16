#include<stdio.h>

#include<stdlib.h>
typedef struct node
{
    long long int no;
    struct node *next;


}node;
int vis[100005];
node *list1[100005];
node *list2[100005];
long long int winner,flag,wcount=0,twcount=0;
void insert1(long long int v1,long long int v2)
{
    node *temp2;
    temp2=(node *)malloc(sizeof(node));
    temp2->no=v1;
    temp2->next=list2[v2];
    list2[v2]=temp2;
}
void insert2(long long int v1,long long int v2)
{
    node *temp2;
    temp2=(node *)malloc(sizeof(node));
    temp2->no=v1;
    temp2->next=list1[v2];
    list1[v2]=temp2;
}

void dfs(long long int s)
{
    node  * temp;
    temp=list1[s];
    vis[s]=1;

    while(temp!=NULL)
    {
        if(!vis[temp->no])
        {
            dfs(temp->no);
        }

        temp=temp->next;
    }


}
void twodfs(long long int s)
{

    node *temp=list2[s];
    vis[s]=1;
    while(temp!=NULL)
    {
        if(!vis[temp->no])
            twodfs(temp->no);
        temp=temp->next;
    }
}
int  find(int q)
{
    int j;

        for(j=1;j<=q;j++)
            vis[j]=0;
        int o,winner;
        for(o=1;o<=q;o++)
        {
            winner=o;

            for(j=1;j<=q;j++)
                vis[j]=0;
            dfs(o);
            flag=0;
            int j=1;
            for(;j<=q;j++)
            {
                if(vis[j]==0)
                {
                    flag=1;
                    break;
                }
            }
            for(j=1;j<=q;j++)
                vis[j]=0;
            if(flag==0)
                return winner;
        }
        return 0;
}

int finalans(int q)
{
    int j;
    for(j=1;j<=q;j++)
            vis[j]=0;
    int t=find(q);
    if(t==0)
        return 0;
    twodfs(t);
    twcount=0;
    for(j=1;j<=q;j++)
            if(vis[j]==1)
                    twcount++;
    return twcount;
}
int main ()
{
    long long int i,d,j,z,king,k,m,q,o,n,l,e,v1,v2;
    scanf("%lld",&k);
    for(i=0;i<k;i++)
    {
        scanf("%lld",&q);
        for(j=1;j<=q;j++)
        {

            scanf("%lld",&m);
            for(o=0;o<m;o++)
            {
                scanf("%lld",&v1);
                insert1(v1,j);
                insert2(j,v1);
            }
        }
        printf("%d\n",finalans(q));
        for(z=1;z<=q;z++)
            list1[z]=NULL;
        for(z=1;z<=q;z++)
            list2[z]=NULL;


    }
    return 0;
}
