#include<stdio.h>
#include<math.h>
#include<string.h>

#define din(N) scanf("%d",&N)
#define llin(N) scanf("%lld",&N)
#define sin(N) scanf("%s",&N)
#define fin(N) scanf("%lf",&N)
#define chin(N) scanf(" %c",&N)

typedef long long ll;

int N, prInd[200000], inInd[200000], inorder[200000];

int main()
{
    din(N);
    int i, j, k;
    for ( i = 0; i < N; i++ )
    {
        din(k);
        prInd[k] = i;
    }
    for ( i = 0; i < N; i++ )
    {
        din(inorder[i]);
        inInd[inorder[i]] = i;
    }
    int t;
    din(t);
    while ( t-- )
    {
        int beg, end, minInd = 200000, minPr;
        din(beg); din(end);
        if ( inInd[beg] > inInd[end] )
        {
            beg += end;
            end = beg - end;
            beg -= end;
        }
        for ( i = inInd[beg]; i <= inInd[end]; i++ )
        {
            if ( prInd[inorder[i]] < minInd )
            {
                minInd = prInd[inorder[i]];
                minPr = inorder[i];
            }
        }
        printf("%d\n",minPr);
    }

    return 0;
}
