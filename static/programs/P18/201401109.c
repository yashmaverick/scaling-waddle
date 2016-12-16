#include<stdio.h>
#include<stdlib.h>
int n1,b[100010],visited[100010],v,e,index1,d[100010],arr[100010]; 
typedef struct list
{
    int data;
    struct list *node;
}list;
list a[1000010],bb[1000010];
int count,max,ver,ucount,ucount1;
void dfs(int z)
{
    visited[z]=2;    
    list *temp=&a[z];                    
    if(temp->data==0)temp=temp->node;
    while(temp!=NULL)
    {
        if(visited[temp->data]==0)
        {
            ucount++;
            dfs(temp->data);
            visited[temp->data]=1;         
        }
        temp=temp->node;
    }
}
void dfs1(int z)
{
    visited[z]=2;    
    list *temp=&bb[z];                    
    if(temp->data==0)temp=temp->node;
    while(temp!=NULL)
    {
        if(visited[temp->data]==0)
        {
            ucount++;
            dfs1(temp->data);
            visited[temp->data]=1;         
        }
        temp=temp->node;
    }
}
int main()
{
    int i,i1,j,k,n,t,v1,v2,index,ran,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&v);
        e=v;
        list *temp;
        for(i=1;i<=e;i++)
        {
            scanf("%d",&m);
            j=0;
            while(j<m)
            {
                scanf("%d",&ran);
                list *temp00,*temp000,*dup1,*dup2;
                temp000=(list *)malloc(sizeof(list));
             //   temp000->node=NULL;
                temp000->data=ran;
                temp00=&bb[i];
                dup1=&bb[i];
                dup1=dup1->node;

               // while(temp00->node!=NULL)
               // {
                //    temp00=temp00->node;

               // }
                temp00->node=temp000;
                temp000->node=dup1;
                v1=ran;
                list *temp,*temp3;
                temp=&a[v1];
                dup2=&a[v1];
                dup2=dup2->node;
                v2=i;
               // while(temp->node!=NULL)
               // {
                 //   temp=temp->node;
               // }
                list *temp1;
                temp1=(list *)malloc(sizeof(list));
                temp1->data=v2;
               // temp1->node=NULL;
                temp->node=temp1;
                temp1->node=dup2;
                j++;
            }
        }
      //  ucount1=0;
        for(i=1;i<=v;i++)
        {
            ucount=0;
            dfs(i);
            if(ucount+1==v)
            {
                ucount=0;
                int i1;
                for(i1=0;i1<=v;i1++)
                {
                    visited[i1]=0;
                }
                dfs1(i);
                break;
            }
            for(j=0;j<=v;j++)
            {
                visited[j]=0;
            }
        }
        if(i>v)
            printf("0\n");
         else
        printf("%d\n",ucount+1);
        for(i=1;i<=v;i++)
        {
            visited[i]=0;
            a[i].node=NULL;
            bb[i].node=NULL;
        }
    }
    return 0;
}
