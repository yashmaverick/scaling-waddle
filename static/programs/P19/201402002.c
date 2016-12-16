#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int K=11;
struct node{
    char val;
    struct node *chil[11];
};

int ans=0;

struct node* insert(struct node *root, char data[], int data_size)
{
    struct node *orig_root=root;
    if (root==NULL)
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->val='+';
        int i;
        for (i=0;i<11;i++)
            temp->chil[i]=NULL;
        orig_root=root=temp;
    }

    int j=0;
    while(j <= data_size)
    {
        if (j==data_size)
            data[j]='$';
        char VAL;
        int i;
        for (i=0;i<11;i++)
        {
            if ((root->chil)[i] == NULL)
            {
                VAL=-111;
                break;
            }
            VAL=((root->chil)[i])->val;
            if (VAL == data[j])
                break;
        }

        if (VAL == data[j])
        {
            if (j==data_size)
                ans++;
            root=root->chil[i];
        }
        else
        {
            struct node *temp=(struct node*)malloc(sizeof(struct node));
            temp->val=data[j];
            int i;
            for (i=0;i<11;i++)
                temp->chil[i]=NULL;

            i=0;
            while ((root->chil)[i]!=NULL)
                i++;

            (root->chil)[i]=temp;
            root=(root->chil)[i];
        }
        j++;
    }
    return orig_root;
}

void print(struct node *root)
{
    int i=0;
    if (root==NULL)
        return;

    printf("%c ->>>>>",root->val);
    while((root->chil)[i]!=NULL && i<11)
    {
        printf("%c, ",((root->chil)[i])->val);
        i++;
    }
    printf("\n");
    i=0;
    while((root->chil)[i]!=NULL && i<11)
    {
        if (((root->chil)[i])->val!='$')
            print((root->chil)[i]);
        i++;
    }
}


void count_prefix(struct node *root)
{
    int i=0,NOT_NULL=0,DOLLAR=0;
    if (root==NULL)
        return;

    while((root->chil)[i]!=NULL && i<11)
    {
        if (((root->chil)[i])->val == '$')
            DOLLAR=1;
        if (((root->chil)[i]) != NULL && ((root->chil)[i])->val != '$' )
            NOT_NULL=1;

        if (DOLLAR && NOT_NULL)
            break;
        i++;
    }

    if (DOLLAR && NOT_NULL)
        ans++;

    i=0;
    while((root->chil)[i]!=NULL && i<11)
    {
        if (((root->chil)[i])->val!='$')
            count_prefix((root->chil)[i]);
        i++;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    char str[20];
    while(t--)
    {
        struct node *root=NULL;
        ans=0;

        int n;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",str);
            root=insert(root,str,strlen(str));
  //          print(root);
        }
        count_prefix(root);
//        printf("%d\n",ans);
        (ans>0)?(printf("NO\n")):(printf("YES\n"));
    }

    return 0;
}
