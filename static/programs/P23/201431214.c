#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int value;
    struct list* next;
}list;
int  q[500005];
int depth[500005];
int top=0;
list* head[500005];
void insert(int num1,int num2)
{
    list* temp=(list*)malloc(sizeof(list));
    temp->value=num2;
    temp->next=NULL;
    list* p;
    if(head[num1]==NULL)
    {
        head[num1]=temp;
    }
    else
    {
        p=head[num1];
        //  head[num1]->next=temp;
        //  temp->next=p;
        head[num1]=temp;
        temp->next=p;
    }
    depth[num2]++;
}
void insertheap(int n1)
{
    int j;
    int temp;
    if(top==0)
    {
        top++;
        q[top]=n1;
    }
    else
    {
        top++;
        q[top]=n1;
        j=top;
        while(j/2!=0 && ((q[j])<(q[j/2])))
        {
            temp=q[j];
            q[j]=q[j/2];
            q[j/2]=temp;
            j=j/2;
        }
    }
}
void deletemin()
{
    int i;
    int  temp;
    q[1]=q[top];
    top--;
    i=1;
    while((2*i<=top && q[i] > q[2*i] ) || (2*i+1<=top && q[i] >     q[2*i+1])){
        if(q[2*i+1] < q[2*i]){
       //     te=hash[q[i]->src];
         //   hash[q[i]->src]=hash[q[2*i+1]->src];
           // hash[q[2*i+1]->src]=te;
            temp=q[(2*i)+1];
            q[(2*i)+1]=q[i];
            q[i]=temp;
            i=(2*i)+1;
        }
        else{
           // te=hash[q[i]->src];
           // hash[q[i]->src]=hash[q[2*i]->src];
           // hash[q[2*i]->src]=te;
            temp=q[(2*i)];
            q[(2*i)]=q[i];
            q[i]=temp;
            i=(2*i);
        }
    }
    return ;
}


int main()
{
    int n,m,i,j,x,y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        depth[i]=0;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        insert(x,y);
    }
    for(i=1;i<=n;i++)
    {
        if(depth[i]==0)
        {
            insertheap(i);
        }
    }
    list* temp;
    list* temp2;
    int cnt=0;
    while(top!=0)
    {
        temp2=head[q[1]];
        temp=head[q[1]];
        printf("%d",q[1]);
        deletemin();
        cnt++;
        if(cnt<n)
        {
            printf(" ");
        }
        while(temp!=NULL)
        {
            depth[temp->value]=depth[temp->value]-1;
            temp=temp->next;
        }
        while(temp2!=NULL)
        {
            if(depth[temp2->value]==0)
            {
                insertheap(temp2->value);
            }
            temp2=temp2->next;
        }
    }
    printf("\n");
    return 0;
}


