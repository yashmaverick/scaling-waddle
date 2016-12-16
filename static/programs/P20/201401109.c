#include<stdio.h>
#include<stdlib.h>
int num;int b[1000100],n1,c[1000100],lastnum,h[1001000];
typedef struct list
{
    int data;
    struct list *node;
}list;
list a[1000100];
int v,e;
int count1,count2,max,sindex;
void pop()
{
    //int i;
//    printf("%d  ",b[sindex]);
    lastnum=b[sindex];
/*    for(i=0;i<n1;i++)
    {
        b[i]=b[i+1];
    }*/
    sindex=sindex+1;
    //n1--;
}
void bfs()
{
    int i=0;
    int   p=v;
    while(p--)
    {
        list *temp;
        temp=&a[b[sindex]];
        pop();
        while(temp->node!=NULL)
        {
            temp=temp->node;
            if(c[temp->data]!=1)
            {
                //i++;
                b[n1]=temp->data;
                h[temp->data]=h[b[sindex-1]]+1;
                c[temp->data]=1;
                n1++;
            }
        }
        //pop();
        //i--;
    }
  //  printf("\n");
}
void print()
{
    int i;
    for(i=1;i<=v;i++)
    {
        list *temp;
        temp=&a[i];
        printf("%d-> ",i);
        while(temp->node!=NULL)
        {
            temp=temp->node;
            printf("%d ",temp->data);
        }
        printf("\n");
    }
}
int main()
{
    int i,j,k,n,t,v1,v2;
    scanf("%d",&t);
    while(t--)
    {
        n1=1;
        scanf("%d",&v);
        e=v-1;
        for(i=0;i<e;i++)
        {
            scanf("%d%d",&v1,&v2);
            if(i==0)
                num=v1;
            list *temp,*temp3;
            temp=&a[v1];
            while(temp->node!=NULL)
            {
                temp=temp->node;
            }
            list *temp1;
            temp1=(list *)malloc(sizeof(list));
            temp1->data=v2;
            temp1->node=NULL;
            temp->node=temp1;
            temp3=&a[v2];
            while(temp3->node!=NULL)
            {
                temp3=temp3->node;
            }
            list *temp4;
            temp4=(list *)malloc(sizeof(list));
            temp4->data=v1;
            temp4->node=NULL;
            temp3->node=temp4;
        }
        //scanf("%d",&num);
        sindex=0;
        b[0]=num;
        c[num]=1;
        h[num]=0;
      //  print();
        bfs();
        //printf("nodes==%d\n",h[lastnum]+1);
        for(i=1;i<=v;i++)
        {
            b[i]=0;c[i]=0;h[i]=0;
//            a[i].node=NULL;
        }
        n1=1;
        sindex=0;
        b[sindex]=lastnum;
        c[lastnum]=1;
        h[lastnum]=0;
        bfs();
        printf("%d\n",h[lastnum]+1);
        for(i=1;i<=v;i++)
        {
            b[i]=0;c[i]=0;h[i]=0;
//            a[i].node=NULL;
            a[i].node=NULL;
        }
    }
    return 0;
}
