//Abhinav Aggarwal
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A[100006][2];
int P[100006];
int H[100006];

int to_left(int par,int var,int *A)
{
    int i;
    for(i=1;A[i]!=par;i++)
    {
        if(A[i]==var)
            return 1;
    }
    return 0;
}

void mark_height(int root,int h)
{
    H[root]=h;
    if(A[root][0]!=-1)
        mark_height(A[root][0],h+1);
    if(A[root][1]!=-1)
        mark_height(A[root][1],h+1);
}

int LCA(int a,int b)
{
    while(a!=b)
    {
        if(H[a]>H[b])
            a=P[a];
        else
            b=P[b];
    }
    return a;
}

int main()
{
    int stack[100006],top=-1;
    int n,t,a,b;
    scanf("%d",&n);
    int In[100006],Pre[100006];
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&Pre[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&In[i]);
    }
    
    //make tree
    for(i=1;i<=n;i++)
    {
        A[i][0]=A[i][1]=-1;
    }
    int par=Pre[1];
    int root=Pre[1];
    P[root]=-1;
    for(i=2;i<=n;i++)
    {
        if(to_left(par,Pre[i],In))
        {
            A[par][0]=Pre[i];
            stack[++top]=par;
            P[Pre[i]]=par;
            par=Pre[i];
        }
        else
        {
            while(top>=0 && !to_left(stack[top],Pre[i],In))
            {
                par=stack[top];
                top--;
            }
            A[par][1]=Pre[i];
            P[Pre[i]]=par;
            par=Pre[i];
        }
    }
    
  /*//printstree
    for(i=1;i<=n;i++)
    {
        printf("%d: %d %d\n",i,A[i][0],A[i][1]);
    }
  */
    mark_height(root,0);
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",LCA(a,b));
    }

return 0;
}
