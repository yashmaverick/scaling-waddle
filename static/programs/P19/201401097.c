#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int v[10];
    struct node *next[10];
}node;
char a[100005];
int flag=0,count=0;
node *head,*prev;
void work(node * temp,long long int ind)
{
    
   
   while(a[ind]!='\0') 
   {
       a[ind]=a[ind]-'0';
    if(temp==NULL) 
    {
            
       
        temp=(node *)malloc(sizeof(node));
        temp->v[a[ind]]=1;
        if(ind!=0)
        prev->next[a[ind-1]]=temp;
       if(count==0)
            head=temp;
        count++;
    //  printf("1-%c\n",a[ind]);
      prev=temp;
              temp=NULL; 
    }
    else if(temp->v[a[ind]]==1)
        {
            prev=temp;
            temp=temp->next[a[ind]];
            flag=1;
// printf("2-%c\n",a[ind]); 

    }
    else if(temp->v[a[ind]]!=1)
    {
               temp->v[a[ind]]=1;
               prev=temp;
               temp=temp->next[a[ind]];
        flag=0;
      //  printf("3-%c\n",a[ind]); 

    }
       
    ind++;
   }

}
int main ()
{
    long long int i,j,k,l,m,n,mflag=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        mflag=0;
        scanf("%lld",&k);
        for(j=0;j<k;j++)
        {
            scanf("%s",a);
         //   if(mflag!=1)
            work(head,0); 
               if(flag==1)
                   mflag=1;

        }
        if(mflag==1)
            printf("NO\n");
        else
            printf("YES\n");
        flag=0;
        mflag=0;
        count=0;
        head=NULL;
        

    }

    return 0;
}
