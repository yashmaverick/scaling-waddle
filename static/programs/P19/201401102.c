#include<stdio.h>
#include<stdlib.h>
struct node
{
        int valid;
        struct node* children[10];
};
typedef struct node node;
node* root;
int flag;
void insert(char a[])
{
        int i;        
        if(root->children[a[0]-'0']==NULL)
        {
                root->children[a[0]-'0']=(node* )malloc(sizeof(node));
        }
        else if(root->children[a[0]-'0']->valid==1)
        {
                flag=1;
                return;
        }
        else if(a[1]=='\0')
        {
                flag=1;
                return;
        }
        node* temp=root->children[a[0]-'0'];        
        for(i=1;a[i]!='\0';i++)
        {
                if(temp->children[a[i]-'0']!=NULL&&temp->children[a[i]-'0']->valid==1)
                {
                        flag=1;
                        return;
                }
                else if(temp->children[a[i]-'0']==NULL)
                {
                        temp->children[a[i]-'0']=(node* )malloc(sizeof(node));  
                        temp->valid=-1;
                }
                else if(a[i+1]=='\0')
                {
                        flag=1;
                        return;
                }
                temp=temp->children[a[i]-'0'];                
        }
        
        temp->valid=1;
}
int main()
{
        long long int t,n,i,j;
        char a[11];
        scanf("%lld",&t);
        root=(node* )malloc(sizeof(node));
        root->valid=99;
        for(i=0;i<t;i++)
        {
                for(j=0;j<10;j++)                
                        root->children[j]=NULL;               
                flag=0;
                scanf("%lld",&n);
                for(j=0;j<n;j++)
                {
                        scanf("%s",a);
                        if(flag!=1)
                                insert(a);
                }
                if(flag==1)
                        printf("NO\n");
                else
                        printf("YES\n");
        }
        return 0;
}
