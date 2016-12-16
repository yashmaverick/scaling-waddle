#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct node
{
    char c;
    int child[11];
    struct node* children[11];
    long long int ccount;
}node;

node * newnode(char ch)
{
    node *a=(node*)malloc(sizeof(node));
    a->c=ch;
    a->ccount=0;
    memset(a->child,0,sizeof(int)*10);
    return a;
}

int insert (char s[100],node *top)
{
    node *head=top;
    int len=strlen(s);
    int new=0;
    int inscount=0;
    int flag=1;
    if(head->child[s[0]-48]==0)
        new=1;
    int i;
    for(i=0;i<len;i++)
    {
     //   printf("inserting %c\n",s[i]);
        if(head->child[s[i]-48]==0)
        {
            if(head->ccount==0&&!new)
            {
            //    printf("setting flag =0 because of %c is null \n",head->c);
                flag=0;
                break;
            }
            else
            {
                head->child[s[i]-48]=1;
                head->ccount+=1;
                head->children[s[i]-48]=newnode(s[i]);
                head=head->children[s[i]-48];
                new=1;
                inscount+=1;
            }
        }
        else
        {
            head=head->children[s[i]-48];
        }
    }
    if(flag&&inscount==0)
       {
         //   printf("setting flag=0 because insertion count is 0 for string %s \n",s);
            flag=0;
        }
    return flag;
}


int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        node*head=newnode('h');
        int flag=1;
        while(n--)
        {
            char s[100];    
            scanf("%s",s);
            if(flag)
            {
                int ans=insert(s,head);
                if(ans==0)
                    flag=0;
            }
        }
        if(flag==1)
            printf("YES\n");
        else {
            printf("NO\n");
        }
        free(head);
    }
    return 0;



}
