#include<stdio.h>
#include<stdlib.h>
//int stack[100000];
int top;
typedef struct tree
{
     int value;
     struct tree* right;
     struct tree* left;
}node;
int b[100010];
//node* createnode(node *tmp,int x)
//{
  //   tmp=(node*)malloc(sizeof(node));
    //      tmp->value=x;
      //    tmp->right=NULL;
        //  tmp->left=NULL;
          //return tmp;
//}
void stackpush(int x)
{
     top++;
    // p[top]=(node*)malloc(sizeof(node));
     b[top]=x;
}
void stackpop()
{
     top--;
}
int stacktop()
{
     return b[top];
}
int main()
{
   //  node *p[100000];
     int a[100010];
    int depth[100010];
     int t,i,j,k,l,m,n,maxdepth,min;
     scanf("%d",&t);
     while(t--)
     {
          top=-1;
          scanf("%d",&n);
          for(i=0;i<n;i++)
                scanf("%d",&a[n-i-1]);
          
          
          for(i=0;i<n;i++)
          {
             // p[i]=createnode(p[i],i);
               if(top==-1)
               {
                    stackpush(i);
                    depth[i]=0;
                    maxdepth=depth[i];
                    min=a[i];
               }
               else if(a[i]>a[stacktop()])
               {
                  //  p[i]=(node*)malloc(sizeof(node));
                   
               //     p[stacktop()]->right=p[i];
                    depth[i]=depth[b[top]]+1;
                    if(depth[i]>=maxdepth)
                    {
                         min=a[i];
                         maxdepth=depth[i];
                       //  if(a[i]<min)
                         //     min=a[i];
                   }
                    stackpush(i);
               }
               else
               {
                    while(top!=-1)
                    {
                         if(a[i]<a[stacktop()])
                             stackpop();
                         else
                              break;
                    }
                  //  p[stacktop()+1]->left=p[i];
                    depth[i]=depth[b[top+1]]+1;
                         if(depth[i]>=maxdepth)
                         {
                              maxdepth=depth[i];
                              if(a[i]<min)
                                   min=a[i];
                         }
                   stackpush(i);
               }
         }
          printf("%d %d\n",min,maxdepth);
     }
     return 0;
}
          
