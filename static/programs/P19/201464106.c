#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie_node
{
    int val;
    struct trie_node *ptr[10];
}trie_node;

int flag1=0,flag2=0;    //flag1 for yes/no and flag2 for same nos.

void insert(trie_node *root,char a[])
{
    int i,j,c=0;
    trie_node *temp=root;
    for(i=0;a[i]!='\0';i++)
    {
        int x=a[i]-48;
        if(temp->ptr[x]==NULL)
        {
            temp->ptr[x]=malloc(sizeof(trie_node));
            temp=temp->ptr[x];
            for(j=0;j<10;j++)
                temp->ptr[j]=NULL;                        //imp. step
            if(i==strlen(a)-1)
                temp->val=-1;
            else
                temp->val=1;            
        }
        else
        {
            temp=temp->ptr[x];
            c++;                  // for same nos.
        }
    }
    if(c==strlen(a))
    {
        printf("NO\n");
        flag2=1;
    }
}


void check_prefix(trie_node *root)
{
    int i,j,flag=0;
    trie_node *temp=root;
    for(i=0;i<10;i++)
    {
        if(temp->ptr[i]!=NULL)
        {
            flag=0;                             //flag to determine whether there's any node whose next is not null
            for(j=0;j<10;j++)
            {
                if(temp->ptr[i]->ptr[j]!=NULL)
                    flag=1;
            }
            if(temp->ptr[i]->val==-1 && flag==1)
            {
                    printf("NO\n");
                    flag1=1;
                    break;
            }
            else if(flag==1 && temp->ptr[i]->val==1)
                check_prefix(temp->ptr[i]);
        }
    }
//    if(flag1!=1)
  //      printf("YES\n");
}





/*void del(trie_node *root)
  {
  int i;
  if(root==NULL)
  return;
  else
  {
  for(i=0;i<11;i++)
  {
  if(root->ptr[i]!=NULL)
  {
  del(root->ptr[i]);
  free(root->ptr[i]);
  printf("IN DEL\n");
  }
  }
  }
  }*/


int main()
{
    int t;
    for(scanf("%d",&t);t--;)
    {
        int i;
        trie_node *root;
        root=malloc(sizeof(trie_node));
        root->val=0;
        for(i=0;i<10;i++)
            root->ptr[i]=NULL;
        int n;
        scanf("%d",&n);
        char a[12];
        for(i=0;i<n;i++)
        {
            scanf("%s",a);
            if(flag2!=1)
                insert(root,a);
        }
        if(flag2!=1)
            check_prefix(root);
        if(flag1!=1 && flag2!=1)
            printf("YES\n");
        flag1=flag2=0;
    }
    return 0;
}

