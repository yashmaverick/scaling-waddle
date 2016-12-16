#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node
{
    int wordend;
    int digit;
    struct node *children[11];
}trie;
trie *root;
int f=0;
int flags(trie *t)
{
    int i;
    for(i=0;i<11;i++)
        if(t->children[i]!=NULL)
            f=1;
    return f;
}
trie *create_node(trie *q)
{
    int i;
    q = (trie*)malloc(sizeof(trie));
    for(i=0;i<11;i++)
        q->children[i]=NULL;
    q->digit=-1;
    q->wordend=0;
    return q;
}
int insertion(char word[])
{
    int y;
//    printf("aaaaa\n");
    trie *rlocal;
 //   printf("aaa\n");
    rlocal=root;
 //   printf("aaaa\n");
    int len;
    len=strlen(word);
    int i;
 //   create_node(rlocal);
//    printf("a4\n");
    for(i=0;i<len;i++)
    {
        y=word[i]-'0';
        //        printf("%d\n",y);
        
   //         printf("bbbbb\n");
            if((rlocal->children[y])==NULL)
            {
    //            printf("ccccc\n");
                rlocal->children[y]=create_node(rlocal->children[y]);
                rlocal->children[y]->digit=y;
            }
            else if(rlocal->children[y]->wordend==1)
            {
            //    f=0;
                return 1;
                break;
            }
            else if(i==len-1 && flags(rlocal->children[y]))
            {
                f=0;
                return 1;
                break;
            }
                    

        //    if(i==len-1 && rlocal->children[y]!=NULL)
          //  {
          //      return 1;
          //      break;
          //  }

            if(i==len-1)
                rlocal->children[y]->wordend=1;
        
            rlocal=rlocal->children[y];

    }
    return 0;
}



int main()
{
    int T,i,j,k,l,N,flag;
    char number[11],p;
    scanf("%d",&T);
    while(T--)
    {
        flag=0;
        f=0;
        k=0;
        root=create_node(root);
        scanf("%d",&N);
        //        printf("dgsg");
        for(i=0;i<N;i++)
        {
            scanf("%s",number);
       

    //        printf("gdhdg\n");
       
            flag=insertion(number);
            if(flag==1)
                k=1;
       //     if(flag==1)
         //       break;
        }

        
        if(k==1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
