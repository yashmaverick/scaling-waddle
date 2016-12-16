#include<stdio.h>
#include<stdlib.h>
typedef long long int lld;
typedef struct list
{
    lld data;
    lld weight;
    struct list *node;
}list;
list a[1000101];
lld distance[1000101],queue[1000101],baap[1000101];
lld visited[1000101]={0};
lld v,e,lindex;
void swap(lld k1,lld k2)
{
    lld temp;
    temp=queue[k1];
    queue[k1]=queue[k2];
    queue[k2]=temp;
}

void insert1(lld num)
{
    lld i,num1,num2;
    num1=(lindex+1)/2;
    if(lindex>=-1)
    {
    num2=lindex+1;
   
    queue[lindex+1]=num;
    lindex++;
    while(distance[queue[num1]]>distance[queue[num2]])
    {
        swap(num1,num2);
        num2=num1;
        num1=num1/2;
    }
    }
}


void dikstra(lld vertex)
{
    list *temp,*temp1;
    temp=&a[vertex];
    while(temp->node!=NULL)
    {
        temp=temp->node;
        if(distance[vertex]+temp->weight<distance[temp->data])
        {
            distance[temp->data]=distance[vertex]+temp->weight;
            baap[temp->data]=vertex;
            if(visited[temp->data]==0)
            {
                visited[temp->data]=1;
               insert1(temp->data);
            }
        }
    }
}


void deletemin()
{
    lld i,num1,num2,num3,small;
    if(lindex>=0)
    {
    queue[1]=queue[lindex];
    lindex--;
    num1=1;
    num2=2;num3=3;
    while(1)
    {
        if(lindex>=num3)
        {
            if(distance[queue[num1]]>distance[queue[num2]] ||distance[queue[num1]]>distance[queue[num3]])
            {
                if(distance[queue[num2]]>distance[queue[num3]])
                {
                    i=num3;
                    small=queue[num3];
                }
                else
                {
                    i=num2;
                    small=queue[num2];
                }
                swap(i,num1);
                num1=i;
                num2=num1*2;
                num3=num1*2+1;
            }
            else
                break;
        }
        else if(lindex>=num2&&lindex<num3)
        {
            if(distance[queue[num1]]>distance[queue[num2]])
                swap(num1,num2);
            num1=num2;
            num2=num1*2;
            num3=num1*2+1;
        }
        else
            break;
    }
    }
    else
        lindex++;
}
int main()
{
    lld i,j,k,n,t,v1,v2,w,min,s;
    scanf("%lld%lld",&v,&e);
    list *temp;
    lindex=2;
    for(i=0;i<e;i++)
    {
        scanf("%lld%lld%lld",&v1,&v2,&w);
        list *temp,*temp3;
        temp=&a[v1];
        while(temp->node!=NULL)
        {
            temp=temp->node;
        }
        list *temp1;
        temp1=(list *)malloc(sizeof(list));
        temp1->data=v2;
        temp1->weight=w;
        temp1->node=NULL;
        temp->node=temp1;
    }
    scanf("%lld%lld",&s,&t);
    for(i=1;i<=v;i++)
    {
        distance[i]=10000000000000001;
        baap[i]=0;
    }
    distance[s]=0;
/*    for(i=1;i<=v;i++)
    {
        insert1(i);
    }*/
    visited[s]=1;
    queue[1]=s;
    j=0;
    while(j<v)
    {
        min=queue[1];
     //   if(visited[min]==1)
      //  {
        //    j--;
        //    deletemin(min);
       // }
       // else
       // {
         //   visited[min]=1;
            deletemin();
            dikstra(min);
       // }
        j++;
    }
    for(i=1;i<=v;i++)
    {
        a[i].node=NULL;
    }
    if(distance[t]!=10000000000000001)
        printf("%lld\n",distance[t]);
    else
        printf("NO\n");
    return 0;
}
