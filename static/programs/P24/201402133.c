#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int query[200019][2];
int val[200019], len, raw[200019], rawlen;
int healthy[200019];

int Beg[4*200019], End[4*200019], Seg[4*200019];

void buildTree(int start, int finish, int node)
{
    Beg[node] = start;
    End[node] = finish;
    Seg[node] = 0;
    
    if(start == finish)
        return;
    
    int left = node*2, right = left+1;
    int mid = (start+finish)/2;
    
    buildTree(start,mid,left);
    buildTree(mid+1,finish,right);
}
void update(int idx, int node)
{
    if(Beg[node] == End[node])
    {
        Seg[node]++;
        return;
    }
    
    int left = node*2, right = left+1;
    if(idx < Beg[right])
        update(idx,left);
    else
        update(idx,right);
    
    Seg[node] = Seg[left]+Seg[right];
}
int rangesum(int start, int finish, int node)
{
    if(start>End[node] || finish<Beg[node])
        return 0;
    if(start<=Beg[node] && finish>=End[node])
        return Seg[node];
    
    int left = node*2, right = left+1;
    return (rangesum(start,finish,left)+rangesum(start,finish,right));
}
int kth(int idx, int node)
{    
    if(Beg[node] == End[node])
    {
        return Beg[node];
    }
    
    int left = node*2, right = left+1;
    
    if(idx<=Seg[left])
        return kth(idx,left);
    else
        return kth(idx-Seg[left],right);
}

void swap(int a, int b)
{
    
    int t = raw[a];
    raw[a] = raw[b];
    raw[b] = t;
}
void quickSort(int l, int r)
{
    if(r-l<=1)
        return;
    
    int k = (rand()%(r-l))+l;
    swap(l,k);
    
    int b = l+1, i;
    for(i=l+1; i<r; ++i)
    {
        if(raw[i] < raw[l])
        {
            swap(i,b);
            b++;
        }
    }
    
    swap(l,b-1);
    quickSort(l,b-1);
    quickSort(b,r);
}
int getid(int v)
{
    int l = 0, u = len;
    while(u-l > 1)
    {
        int d = (u+l)/2;
        
        if(val[d] > v)
        {
            u = d;
        }
        else
        {
            l = d;
        }
    }
    
    return l;
}

int main()
{
    srand(19);
    
    int q, i;
    scanf("%d",&q);
    
    for(q=0;;++q)
    {
        int x;
        char op[100];
        
        scanf(" %s",op);
        
        if(op[0] == 'Q')
            break;
        
        scanf("%d",&x);
        query[q][1] = x;
        
        if(op[0] == 'S')
            query[q][0] = 0;
        else if(op[0] == 'C')
            query[q][0] = 1;
        else if(op[0] == 'H')
            query[q][0] = 2;
        else if(op[0] == 'R')
            query[q][0] = 3;
        else
            assert(0);
        
        if(op[0]!='H') raw[rawlen++] = x;
    }
    
    quickSort(0,rawlen);
    
    val[len++] = raw[0];
    for(i=1; i<rawlen; ++i)
    {
        if(raw[i-1] != raw[i])
            val[len++] = raw[i];
    }
    
    buildTree(0,len-1,1);
    for(i=0;i<q;++i)
    {
        int x = getid(query[i][1]);
        
        if(query[i][0] == 0)
        {
            healthy[x] = 1;
            update(x,1);
        }
        else if(query[i][0] == 1)
        {
            if(healthy[x] == 1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else if(query[i][0] == 2)
        {
            x = query[i][1];
//             printf("%d %d ",x,Seg[1]);
            
            if(x>Seg[1])
                printf("NONE\n");
            else
                printf("%d\n",val[kth(x,1)]);
        }
        else if(query[i][0] == 3)
        {
            printf("%d\n",rangesum(0,x-1,1));
        }
        else
            assert(0);
    }
    
    return 0;
}