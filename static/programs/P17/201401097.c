#include<stdio.h>
#include<stdlib.h>
long long int pre[100005],in[100005];
typedef struct node 
{
    struct node *left;
    struct node *right;
    struct node *par;
     long long int no;  
     long long int index;
}node;
node *root;
void build(long long int n)
{
    long long int i,j,flag=0;
    node *temp,*last;
    temp=(node *)malloc(sizeof(node));
    temp->no=pre[0];
    temp->left=NULL;
    temp->right=NULL;
    temp->index=in[pre[0]];
    temp->par=NULL;
    
    root=temp;
        for(i=1;i<n;i++)
       {
           temp=root;
           flag=0;
           while(temp!=NULL)
           {
               last=temp;
              if(in[pre[i]]<temp->index)
              {
                  temp=temp->left;
                  flag=1;
              }
                
              else
              {
                  flag=0;
                  temp=temp->right;
              }
           }
            temp=(node *)malloc(sizeof(node));
           temp->no=pre[i];
           temp->left=NULL;
           temp->right=NULL;
           temp->index=in[pre[i]];
           temp->par=last;
           if(flag==1)
               last->left=temp;
           else
               last->right=temp;
           
        }
}
void path(long long int a,long long int pa[])
{
    node *temp;
    long long int i=0;
    temp=root;
    while(temp!=NULL)
   {
       if(in[a]<temp->index)
       { 
           pa[i++]=temp->no;
           if(temp->no==a)
               break;
           temp=temp->left;
          
       }
       else
       {
           pa[i++]=temp->no;
            if(temp->no==a)
               break;
   
           temp=temp->right;
                  }
      
      
    }
}
void lca(long long int a,long long int b)
{
    long long int pa[100005],pb[100005],i=0;
         for(i=0;i<100005;i++)
         {
             pa[i]=-1;
             pb[i]=-2;
         }
         i=0;
    path(a,pa);
    path(b,pb);
 /*   while(pa[i]!=-1)
        printf("i%lld\n",pa[i++]);
    i=0;
    while(pb[i]!=-2)
        printf("l%lld\n",pb[i++]);*/
    i=0;
    while(pa[i]==pb[i])
        i++;
    printf("%lld\n",pa[i-1]);

  
   
}

void inorder(node *temp)
{
    
          if(temp!=NULL)
          {
           inorder(temp->left);
           printf("%lld\n",temp->no);
           inorder(temp->right);
           
          }
          else
              return;

       
}
int main ()
{
    long long int i,j,k,t,m,n,l,a,b;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&pre[i]);
     }
    for(i=0;i<n;i++)
    {
        scanf("%lld",&t);
        in[t]=i;
    }
    build(n);
    scanf("%lld",&k);
    for(i=0;i<k;i++)
    {
        scanf("%lld%lld",&a,&b);
        lca(a,b);

    }
    
    return 0;
}
