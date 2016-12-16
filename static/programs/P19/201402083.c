
/*
_____________________________________________
PROBLEM STATEMENT: 
TEST CASES:
COMMENTS:

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int result;
typedef  struct node node;
struct node
{
    int word_end;
    node* next[11];
};

node* initialize(node *trie)
{
    int i;
    trie->word_end=0;
    for(i=0;i<11;i++) trie->next[i]=NULL;
    return trie;
}

node *insert(int begin,int end,char data[],node *trie)
{
    int i;
    if(begin>=end) 
    {
        if(begin==end)
            trie->word_end++;
        
        if(trie->word_end==1)
        {
            for(i=0;i<11;i++) 
            { 
                if(trie->next[i]!=NULL) result=1;
            }
        }
//        printf("%c: %d %d\n",data[begin],result,trie->word_end);
        if(trie->word_end>1) result=1;
        return trie;
    }
    else
    {
        if(trie->next[data[begin]-'0']==NULL)
        {
            trie->next[data[begin]-'0']=(node *)malloc(sizeof(node));
            trie->next[data[begin]-'0']=initialize(trie->next[data[begin]-'0']);
        }
        //if(begin==end) {
        //    trie->word_end++;}
        if(trie->word_end==1)
        {
            for(i=0;i<11;i++) 
            { 
                if(trie->next[i]!=NULL) result=1;
            }
        }
       // if(trie->word_end>1) result=1;
        trie->next[data[begin]-'0']=insert(begin+1,end,data,trie->next[data[begin]-'0']);
        return trie;
    }
    
}
int main()
{
    int t,n;
    char temp[11];
    scanf("%d",&t);
    while(t--)
    {
        node *trie;
        trie=(node *)malloc(sizeof(node));
        trie=initialize(trie);
        result=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",temp);
            int k=strlen(temp);
            trie=insert(0,k,temp,trie);
          //  printf("%s: %d-res\n",temp,result);
        }
        if(result==1)  printf("NO\n");
        else   printf("YES\n");
    }
return 0;
}
