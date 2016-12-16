#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next[11];
}node;
node *head;
int flag;
void check(int arr[],int j,int n)
{
    node *temp=head;
    int i;
    int k=0;
    node *temp1;
    if(temp->next[arr[j-1]]!=NULL)
    {
       // temp=temp->next[arr[j-1]];
        while((j-k-1>=0) && (temp->next[arr[j-k-1]]!=NULL) )
        {
            temp=temp->next[arr[j-k-1]];
            k++;
        }
        if(j-k-1<0)
             flag=1;
        else if(temp->next[arr[j-k-1]]==NULL&&temp->next[10]!=NULL)
            flag=1;
    
      //  while(temp!=NULL&&(j-k-1>=0))
        //{
          //  if(temp->val==arr[j-k-1])
            //    k++;
           // temp1=temp;
           // temp=temp->next[arr[j-k-1]];
       // }
       // if(j-k-1<0)
         //   flag=1;
       // else if(temp==NULL&&temp1->next[10]!=NULL)
         //   flag=1;
    }
}

void insert(int arr[],int j,int n)
{
    int i;
    node *temp=head;
    int k;
    for(i=j-1;i>=0;i--)
    {
        if(temp->next[arr[i]]==NULL)
        {
            node *p;
            p=(node *)malloc(sizeof(node));
            p->val=arr[i];
            for(k=0;k<11;k++)
                p->next[k]=NULL;
            temp->next[p->val]=p;
        }
        temp=temp->next[arr[i]];
    }
    node *end;
    end=(node *)malloc(sizeof(node));
    end->val=10;
    for(k=0;k<11;k++)
        end->next[k]=NULL;
    temp->next[10]=end;
}
int main()
{ 
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        flag=0;
        scanf("%d",&n);
        head=NULL;
        head=(node *)malloc(sizeof(node));
        head->val=0;
        int l;
        for(l=0;l<11;l++)
            head->next[l]=NULL;
        for(l=0;l<n;l++)
        {
            long long int num;
            scanf("%lld",&num);
            long long int temp=num;
            int arr[11];
            int j=0;
            if(flag==0)
            {
                if(num==0)
                {
                    arr[j]=0;
                    j++;
                }
                else
                {
                    while(temp!=0)
                    {
                        arr[j]=temp%10;
                        temp=temp/10;
                        j++;
                    }
                }
                check(arr,j,n);
                if(flag==0)
                    insert(arr,j,n);
            }
        }
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
