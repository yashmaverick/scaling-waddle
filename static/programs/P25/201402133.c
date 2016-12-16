#include <stdio.h>
#include <stdlib.h>

int Edges[1000019][3];

int n, m, cnt, sum;

int Group[100019];

void swapEdges(int a, int b)
{
    int i;
    for(i=0;i<3;++i)
    {
        int t = Edges[a][i];
        Edges[a][i] = Edges[b][i];
        Edges[b][i] = t;
    }
}
void quickSort(int l, int r)
{
    if(r-l<=1)
        return;
    
    int k = (rand()%(r-l))+l;
    swapEdges(l,k);
    
    int b = l+1, i;
    for(i=l+1; i<r; ++i)
    {
        if(Edges[i][2] < Edges[l][2] || (Edges[i][2] == Edges[l][2] && (rand()%2)==0))
        {
            swapEdges(i,b);
            b++;
        }
    }
    
    swapEdges(l,b-1);
    quickSort(l,b-1);
    quickSort(b,r);
}
int getGroup(int u)
{
    if(Group[u] == u)
        return u;
    
    Group[u] = getGroup(Group[u]);
    return Group[u];
}
void merge(int a, int b)
{
    if(rand()%2 == 0)
        Group[a] = b;
    else
        Group[b] = a;
}

int main()
{
    srand(19);
    
    int i;
    scanf("%d %d", &n, &m);
    
    for(i=0; i<m; ++i)
    {
        int a, b, w;
        scanf("%d %d %d",&a,&b,&w);
        
        Edges[i][0] = a;
        Edges[i][1] = b;
        Edges[i][2] = w;
    }
    for(i=1; i<=n; ++i)
    {
        Group[i] = i;
    }
    
    quickSort(0,m);
    
    for(i=0; i<m; ++i)
    {
        int a = Edges[i][0], b = Edges[i][1];
        
        a = getGroup(a), b = getGroup(b);
        
        if(a != b)
        {
            merge(a,b);
            cnt++;
            sum += Edges[i][2];
        }
    }
    
    if(cnt == n-1)
        printf("%d\n",sum);
    else
        printf("-1\n");
    
    return 0;
}