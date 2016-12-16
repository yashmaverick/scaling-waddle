
/*
   _____________________________________________

PURPOSE : 


created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int BST[100005],LESS[100005],depth[100005];
int stack[100005];
int SP;

void push(int d)
{
    stack[++SP]=d;
}

int pop()
{
    return stack[SP--];
}

void compute_depth(int i,int j,int d)
{
    if(j<i)
        return;
    depth[j]=d+1;
    if(i==j)
    {
        return;
    }
    if(i==j-1)
    {
        depth[i]=d+2;
        return;
    }
    int k;
    int min=LESS[j];
    if(min<i)
    {
        compute_depth(i,j-1,depth[j]);
        return;
    }
    compute_depth(i,min,depth[j]);
    compute_depth(min+1,j-1,depth[j]);
}

int main()
{
    int t,n,max_depth;
    scanf("%d",&t);
    
    int i;

    while(t--)
    {
        SP=-1;
        scanf("%d",&n);
        if(n==0)
            continue;
        for(i=0;i<n;i++)
        {
            scanf("%d",&BST[i]);
        }
        for(i=0;i<n;i++)
            depth[i]=0;
        
        push(0);
        LESS[0]=-1;
        for(i=1;i<n;i++)
        {
            if(BST[i]>BST[i-1])
                LESS[i]=i-1;
            else if(BST[i]==BST[i-1])
                LESS[i]=LESS[i-1];
            else
            {
                while(SP!=-1 && BST[stack[SP]]>BST[i])
                {
                    pop();
                }
               // printf("SP is %d\n",SP);
                if(SP!=-1)
                  LESS[i]=stack[SP];
                else LESS[i]=-1;
            }
          push(i);
       }
     /*  for(i=0;i<n;i++)
      {
           printf("%d ",LESS[i]);
      }
       printf("\n");
     */ 
       compute_depth(0,n-1,-1);
      /* for(i=0;i<n;i++)
       {
           printf("%d ",depth[i]);
       }

       printf("\n");
      */ 
       max_depth=0;
       for(i=1;i<n;i++)
       {
          if(depth[i]>depth[max_depth])
              max_depth=i;
          else if (depth[i]==depth[max_depth])
          {
              if(BST[i]<=BST[max_depth])
                  max_depth=i;
          }
       }
       printf("%d %d\n",BST[max_depth],depth[max_depth]);
    }
    return 0;
}
