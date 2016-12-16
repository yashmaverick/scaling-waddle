#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
{
    int data;
    struct list *node[10];
}list;
list *head;
int count,count1,l,b[10],flag;
void create()
{
    list *temp;
    head=(list *)malloc(sizeof(list));
    temp=head;
    int j=9;
    while(j>=0)
    {
        temp->node[j]=NULL;
        j--;
    }
    head=temp;
}
void insert()
{
    flag=0;
    int num,j;
    list *temp;list *temp1;
    temp=head;
    int count=0;
    count1=0;
    while(count<l)
    {
        num=b[count];
        if(temp->node[num]==NULL)
        {
//            printf("count==%d  ",count);
            if(temp->data==1)
                flag=1;
            temp1=(list *)malloc(sizeof(list));
            if(count==l-1)
                temp1->data=1;
            j=9;
            while(j>=0)
            {
                temp1->node[j]=NULL;
                j--;
            }
            temp->node[num]=temp1;
            temp=temp->node[num];
        }
        else
        {
           temp=temp->node[num];
      //      if(temp->data==1)
        //        count1++;
          //  else
           // {
               count1++;
                if(count==l-1)
                    temp->data=1;
            //}
        }
        count++;
    }
  //  printf("count1==%d  \n",count1);
}
int main()
{
    int i,j,k,t,n,f;
    char c[10];
    list *temp,*temp1;
    scanf("%d",&t);
    while(t--)
    {
        create();
        f=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",c);
            count1=0;

            l=strlen(c);
            for(i=0;i<l;i++)
            {
                b[i]=(int)c[i]-48;
            }
            insert();
            if(count1==l)
            {
                f=1;
            }
            if(flag==1)
            {
                f=1;
            }
        }
        if(f==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
