#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node
{
    int value,check;
    node *arr[11];
}; 

int flag=0;

void insert(char c[],node *head,int charpos)
{
    if (c[charpos]=='\n' || c[charpos]=='\0')
    {
        if(head->check==1)
            flag=1;
        head->check=1;
        int i,k=0;
        for(i=0;i<11;i++)
        {
            if(head->arr[i]!=NULL)
                k++;
        }
        if(k>0)
            flag=1;
        return;
    }
    if (head->arr[c[charpos]-'0']==NULL)
    {
        int i;
        if(head->check==1)
            flag=1;
        head->arr[c[charpos]-'0']=(node*)malloc(sizeof(node));
        node *k = head->arr[c[charpos]-'0'];
        k->value=c[charpos]-'0';
        k->check=0;
        for(i=0;i<11;i++)
        {
            k->arr[i]=NULL;
        }
    }
    insert(c,head->arr[c[charpos]-'0'],charpos+1);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        int n,i;
        scanf("%d",&n);
        node *HEAD=(node*)malloc(sizeof(node));
        for(i=0;i<11;i++)
        {
            HEAD->arr[i]=NULL;
        }
        HEAD->value=0;
        while(n--)
        {
            char c[12];
            scanf("%s",c);
            insert(c,HEAD,0);
        }
        if(flag==1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
