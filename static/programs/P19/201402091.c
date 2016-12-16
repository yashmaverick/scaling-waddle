#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct trienode
{   
    int end;
    struct trienode* children[11];
}trienode;
typedef struct trie
{
    struct trienode* root;
}trie;
trienode* get(void)
{   int i;
    trienode* new=(trienode*)(malloc(sizeof(trienode)));
    for(i=0;i<11;i++)
        new->children[i]=NULL;
    return new;
}
int insert(trie* t,char key[],int l)
{   
    trienode* tr=t->root;
    int i;
    for(i=0;i<l-1;i++)
    {   
        if(!tr->children[key[i]-'0'])
        {
            tr->children[key[i]-'0']=get();
            tr->children[key[i]-'0']->end=0;
        }
        else
        {
            if(tr->children[key[i]-'0']->end==1)
                return 1;
        }
        tr=tr->children[key[i]-'0'];
    }
    if(!tr->children[key[l-1]-'0'])
    {
        tr->children[key[l-1]-'0']=get();
        tr->children[key[i]-'0']->end=1;
        return 0;
    }
    else
        return 1;
}
int main()
{
    int t,i,n,l;
    char N[12];
    scanf("%d",&t);
    while(t--)
    {   
        int found=0;
        scanf("%d",&n);
        trie* t=(trie*)malloc(sizeof(trie));
        t->root=get();
        for(i=0;i<n;i++)
        {
            scanf("%s",N);
            l=strlen(N);
            if(found==0)
            {
                found=insert(t,N,l);
            }
        }
        if(found)
            printf("NO\n");
        else
            printf("YES\n");
    }
}

