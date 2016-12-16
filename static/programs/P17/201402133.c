#include <stdio.h>

int n, q;
int Pre[1000019];
int In[1000019];
int Seg[4*1000019], Beg[4*1000019], End[4*1000019];
int Loc[1000019];

void buildTree(int start, int finish, int node)
{
    Beg[node] = start;
    End[node] = finish;
    
    Seg[node] = 1e9;
    
    if(start == finish)
        return;
    
    int left = node*2, right = left+1;
    int middle = (start+finish)/2;
    
    buildTree(start,middle,left);
    buildTree(middle+1,finish,right);
}
void update(int idx, int val, int node)
{
    if(Beg[node] == End[node])
    {
        Seg[node] = val;
        return;
    }
    
    int left = node*2, right = left+1;
    
    if(idx < Beg[right])
        update(idx, val, left);
    else
        update(idx, val, right);
    
    if(Seg[left]<Seg[right])
        Seg[node] = Seg[left];
    else
        Seg[node] = Seg[right];
}
int minimum(int start, int finish, int node)
{    
    if(start>End[node] || finish<Beg[node])
        return 1e9;
    if(start<=Beg[node] && finish>=End[node])
        return Seg[node];
    
    int left = node*2, right = left+1;
    
    int lval = minimum(start,finish,left);
    int rval = minimum(start,finish,right);
    
    if(lval<rval)
        return lval;
    else
        return rval;
}
void printTree(int node)
{
    printf("%d: %d %d %d\n",node,Beg[node],End[node],Seg[node]);
    
    if(Beg[node] == End[node])
        return;
    
    int left = node*2, right = left+1;
    
    printTree(left);
    printTree(right);
}

int main()
{
    int i, j, k;
    scanf("%d",&n);
    
    for(i=0;i<n;++i)
        scanf("%d",&Pre[i]);
    for(i=0;i<n;++i)
    {
        scanf("%d",&In[i]);
        Loc[In[i]] = i;
    }
    
    buildTree(0,n-1,1);
    for(i=0;i<n;++i)
        update(Loc[Pre[i]],i,1);
    
//     printTree(1);
    
    scanf("%d",&q); 
    for(i=0;i<q;++i)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        
        a = Loc[a], b = Loc[b];
        if(a>b)
        {
            int tmp = b;
            b = a;
            a = tmp;
        }
        
        printf("%d\n",Pre[minimum(a,b,1)]);
    }
    
    return 0;
}