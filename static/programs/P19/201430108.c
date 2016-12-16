#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct trie trie;
typedef struct tnode tnode;
#define char_digit(c) ((int)c - (int)'0')
struct tnode
{   
    long long int value;
    long long int val;
    tnode *children[10];
};
struct trie
{
    long long int count;
    tnode *root;
};
void initialize(trie *pTrie);
tnode *new(void);
void insert(trie *pTrie,char key[]);
long long int search(trie *pTrie,char key[]);
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {   
        long long int i;
        trie trie;
        initialize(&trie);
        char a[100001];
        long long int n;
        scanf("%lld",&n);
        int flag=0; 
        for(i=0;i<n;i++)
        {
          scanf("%s",a); 
          if(flag==0)
          {
            if(search(&trie,a)!=0)
            {
              printf("NO\n");
              flag=1;
            }
            insert(&trie,a);
          }
        }
        if(flag==0)
          printf("YES\n");
    }      
 return 0;
}
void initialize(trie *pTrie)
{
    pTrie->root=new();
    pTrie->count=0;
}
tnode *new(void)
{
    tnode *node=NULL;
    node=(tnode*)malloc(sizeof(tnode));
    if(node)
    {   long long int i;
        node->value=0;
        node->val=0;
        for(i=0;i<10;i++)
            node->children[i] = NULL;
    }
    return node;
}
void insert(trie *pTrie,char key[])
{
    long long int level,i,k;
    long long int length=strlen(key);
    tnode *trie_line;
    pTrie->count++;
    trie_line=pTrie->root;
    long long int digit;
    for(k=0;k<length;k++)
    {   
        i=char_digit(key[k]);
        if(!trie_line->children[i])
            trie_line->children[i]=new();
        trie_line=trie_line->children[i];
    }
    trie_line->value = pTrie->count;
    trie_line->val++;
    //printf("%lld\n",trie_line->val );
}
long long int search(trie *pTrie,char key[])
{
    long long int level,i,k;
    tnode *trie_line;
    long long int length=strlen(key);
    trie_line=pTrie->root;
    long long int flag=0;
    for(k=0;k<length;k++)
    {   
        i=char_digit(key[k]);
        long long int j;     
            if(!trie_line->children[i])
                return 0;
            trie_line=trie_line->children[i];
            flag=0;
            //printf("%lld\n",trie_line->val );
            if(trie_line->val>0)
                return 1;
    }
    //return (0 != trie_line && trie_line->value);
            return 1;
}