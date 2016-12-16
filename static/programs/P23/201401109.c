#include<stdio.h>
#include<stdlib.h>
typedef long long int lld;
typedef struct list
{
    lld data;
    struct list *node;
}list;
list a[1000100];
lld stack[1000010],n,index1,n1,num1,num2,count,printed[1000010],store[1000100],accesed[1000100];
void popandstore()
{
    index1++;
    store[index1]=stack[n1];
    n1--;
    count++;
}
void func()
{
    lld i,j,k,flag1,flag3,count2;
    list *temp,*temp1;
    while(1)
    {
        count2=0;
        flag3=0;
        flag1=0;
        temp=&a[stack[n1]];
     if(accesed[stack[n1]]!=1)
     {
         accesed[stack[n1]]=1;
        while(temp->node!=NULL)
        {
           
            flag1=1;
            temp=temp->node;
            if(accesed[temp->data]==0)
            {
            n1++;
            stack[n1]=temp->data;
            }
        }
     }
        if(flag1==0)
        {
            if(printed[stack[n1]]==0)
            {
            printed[stack[n1]]=1;
            popandstore();
            }
            else
                n1--;
        }
        if(count==n)
        {
            break;

        }

        
    }
}
int main()
{
    lld i,j,k,m,flag,v1,v2;
    count=0;
    index1=-1;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<m;i++)
    {
        flag=0;
        list *temp,*temp1,*temp2;
        scanf("%lld%lld",&v1,&v2);
        temp=&a[v1];
        temp2=&a[v1];
        temp1=(list *)malloc(sizeof(list));
        temp1->data=v2;
        while(temp->node!=NULL)
        {
           temp=temp->node;
           if(temp->data>v2)
           {
               flag=1;
               break;
           }
           temp2=temp;
        }
        if(flag==1)
        {
            temp2->node=temp1;
            temp1->node=temp;
        }
        else
        {
            temp1->node=NULL;
            temp->node=temp1;
        }
    }
    for(i=1;i<=n;i++)
    {
        stack[i]=i;
    }
    n1=n;
    func();
    for(i=n-1;i>=1;i--)
        printf("%lld ",store[i]);
    printf("%lld\n",store[0]);


    return 0;
}

