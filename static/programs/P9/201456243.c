#include <stdio.h>

const int maxN = 1e3+3;

int n, mod, v;

int i, j, k;

int m[1003];
int* items[1003];
int weight[1003];

void swap(int x, int y)
{
    int* tl;
    
    int tw = weight[y], tm = m[y];
    weight[y] = weight[x];
    weight[x] = tw;
    
    tl = items[y];
    items[y] = items[x];
    items[x] = tl;
    
    m[y] = m[x];
    m[x] = tm;
}

void input()
{
    scanf("%d%d",&n,&mod);
    for(i=0;i<n;++i)
    {
        scanf("%d",&m[i]);
        weight[i] = 0;
        
        items[i] = malloc(m[i]*sizeof(int));
        
        for(j=0;j<m[i];++j)
        {
            scanf("%d",&items[i][j]);
            weight[i] += items[i][j];
            weight[i] %= mod;
        }
    }
}

void solve()
{
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<n-1;++j)
        {
            if(weight[j]>weight[j+1])
            {
                swap(j,j+1);
            }
        }
    }
    
    for(i=0;i<n;++i)
    {
        printf("%d\n",weight[i]);
        for(j=0;j<m[i];++j)
        {
            printf("%d\n",items[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    input();
    solve();
    
    return 0;
}