#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int value;
    struct list* next;
}list;
list* head[1000005];
int n,depth[1000005];
int top=-1;
int visited[1000005],st[1000005];
int flag,max=0,redfs;
void insert(int num1,int num)
{
    int l;
    list* temp=(list*)malloc(sizeof(list));
    temp->value=num;
    temp->next=NULL;
    list* p;
    if(head[num1]==NULL)
    {
        head[num1]=temp;
    }
    else
    {
        p=head[num1];
        //	head[num1]->next=temp;
        //	temp->next=p;
        head[num1]=temp;
        temp->next=p;
    }
}
void dfs(int v)
{
    int m,l;
    while(top!=-1)
    {
        if(top!=-1)
        {
            m=st[top];
           // printf("m=%d\n",m);
            top--;
        }
   //     printf("m=%d\n",m);
       list* temp=head[m];
 //      printf("t->v=%d\n",temp->value);
        while(temp!=NULL)
        {
          //  printf("checktempnull\n");
            if(visited[temp->value]==0)
            {
              //  printf("checkvisited\n");
            top++;
            st[top]=temp->value;
            visited[temp->value]=1;
            depth[temp->value]=depth[m]+1;
            }
            if(max<depth[temp->value])
            {
               // printf("insideif\n");
                max=depth[temp->value];
            }
            temp=temp->next;
        }
    }
    for(l=1;l<=n;l++)
    {
        visited[l]=0;
        depth[l]=0;
    }
    top=-1;
}
int main()
{
    int test,t;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        int n,i,x,y,k,j,max1;
        max1=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            visited[i]=0;
            depth[i]=0;
        }
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            insert(x,y);
            insert(y,x);
        }
        int p=0;
                depth[1]=1;
                visited[1]=1;
                top++;
                st[top]=1;
                dfs(1);
                for(i=1;i<=n;i++)
                {
                    visited[i]=0;
                    if(depth[i]>max1)
                    {
                        max1=depth[i];
                        redfs=i;
                    }

                    depth[i]=0;
                }
                top=-1;
                depth[redfs]=1;
                visited[redfs]=1;
                top++;
                st[top]=redfs;
               // printf("redfs=%d\n",redfs);
                dfs(redfs);
        printf("%d\n",max);
        for(i=1;i<=n;i++)
        {
            head[i]=NULL;
        }
        max=0;
        top=-1;
        redfs=0;
    }
    return 0;
}
