#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    int leaf;
    struct node *next[11];
}node;
node* root;
int flag;
node* createnode()
{
    node* temp=NULL;
    temp=(node*)malloc(sizeof(node));
        temp->value=0;
        temp->leaf=0;
    return temp;
}
void insert(char s[10001])
{
    int i,length;
    length=strlen(s);
    node* temp2;
    temp2=root;
    for(i=0;i<length;i++)
    {
        if(temp2->next[s[i]-'0']==NULL)
        {
            temp2->next[s[i]-'0']=createnode();
        }
        else
        {
            if(s[i+1]!='\0')
            {
                if(temp2->next[s[i]-'0']->leaf==1)
                {
                    flag=1;
                }
            }
            else
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            break;
        }
        temp2=temp2->next[s[i]-'0'];
        if(s[i+1]!='\0')
        {
            temp2->leaf=0;
        }
        else if(s[i+1]=='\0')
        {
            temp2->leaf=1;
        }
    }
}
int main()
{
    int test,t;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        flag=0;
        int i,n;
        root=createnode();
         for(i=0;i<=9;i++)
         {
             root->next[i]=NULL;
         }
         scanf("%d",&n);
         char s[100001];
         for(i=1;i<=n;i++)
         {
             scanf("%s",s);
             if(flag==0)
             {
                 insert(s);
             }
         }
         if(flag==1)
         {
             printf("NO\n");
         }
         else
         {
             printf("YES\n");
         }
         for(i=0;i<=9;i++)
         {
             root->next[i]=0;
         }
         root=NULL;
    }
    return 0;
}


