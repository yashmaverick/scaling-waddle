#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define DIGIT_SIZE (10)
#define DIGIT_TO_INDEX(c) ((int)c - (int)'0')

typedef struct trie_node trie_node_t;

struct trie_node
{
    int value;
    trie_node_t *children[DIGIT_SIZE];
};

typedef struct trie trie_t;
struct trie
{
    trie_node_t *root;
    int count;
};

//create Trie Node
trie_node_t *createNode(void)
{
    trie_node_t *pNode = NULL;

    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

    if( pNode )
    {
        int i;

        pNode->value = 0;

        for(i = 0; i < DIGIT_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }

    return pNode;
}
// Initializes trie (root is dummy node)
void initialize(trie_t *pTrie)
{
    pTrie->root = createNode();
    pTrie->count = 0;
}

// Return 1, if substring already exists
int insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
    int duplicate=0;
    int newNodeCreated=0;

    pTrie->count++;
    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = DIGIT_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = createNode();
            newNodeCreated=1;
        }

        pCrawl = pCrawl->children[index];

        // sub-string already exists
        if (pCrawl && pCrawl->value>0)//error at this line according to gdb
            duplicate=1;
    }

    // mark last node as leaf
    pCrawl->value = pTrie->count;

    // Check if new node crated. If no, means substring...
    if (newNodeCreated==0)
        duplicate=1;

    return duplicate;
}

int get_digits(int i)
{
        return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int main()
{
    int i,j,n,num,x;

    scanf("%d",&n);
    char key[DIGIT_SIZE+1];

    // Read N Sets
    for (i=0;i<n;i++)
    {
         trie_t trie;
         initialize(&trie);
         int duplicate=0;
          // Read # of Numbers
          scanf("%d",&num);
          while (num--)
          {
                scanf("%s",key);
                ///Read aKey
                /*scanf("%d",&x);
                
                int digit=get_digits(x);
                key[digit]=0;
                for(j=digit-1;j>=0;j--)
                {
                    key[j]='0'+x%10;
                    x/=10;
                }*/

                if (insert(&trie, key))
                    duplicate=1;
          }
          if (duplicate)
            printf("NO\n");
          else
            printf("YES\n");

    }
    return 0;
}
