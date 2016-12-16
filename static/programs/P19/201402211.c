#include<stdio.h>
#include<math.h>
#include<string.h>

#define din(N) scanf("%d",&N)
#define llin(N) scanf("%lld",&N)
#define sin(N) scanf("%s",N)
#define fin(N) scanf("%lf",&N)
#define chin(N) scanf(" %c",&N)

typedef long long ll;

struct node {
    int add[10];
    int isEnd;
} trie[100000];

int N, lastNode = 1;
char input[15];
/*ll reverse ( ll *inp )
{
    ll ret = 0;
    while ( *inp )
    {
        ret *= 10;
        ret += (*inp%10);
        *inp /= 10;
    }
    //printf("%lld\n",ret);
    *inp = ret;
}*/

int main()
{
    int tcases, i, j, k, currNode, valid, newBranch;
    din(tcases);
    while(tcases--)
    {
        din(N);
        valid = lastNode = 1;
        for ( j = 0; j < N; j++ )
        {
            sin(input);
            //printf("%s %d\n",input,j);
            //reverse(&input);
            currNode = newBranch = 0;
            for ( i = 0; input[i] != '\0'; i++ )
            //while ( input && valid )
            {
                //printf("%lld\n",input);
                if ( trie[currNode].isEnd )
                {
                    //printf("reached end\n");
                    valid = 0;
                    break;
                }
                if ( trie[currNode].add[input[i] - '0'] == 0 )
                {
                    newBranch = 1;
                    trie[currNode].add[input[i] - '0'] = lastNode;
                    currNode = lastNode;
                    lastNode++;
                }
                else
                {
                    currNode = trie[currNode].add[input[i] - '0'];
                }
            }
            if ( !newBranch )
                valid = 0;
            trie[currNode].isEnd = 1;
        }

        valid ? printf("YES\n") : printf("NO\n");
        memset(trie,0,sizeof(struct node)*lastNode);
    }

    return 0;
}
