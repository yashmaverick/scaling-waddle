#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ans[3];
int flag;
typedef struct trienode
{
        int value;
        struct trienode *children[10];
}node;
node *newNode()
{
        node *temp=malloc(sizeof(node));
        long long int i;
        temp->value=1;
        return(temp);
}

int insert(char no[],node *root)
{
        int length;
        length=strlen(no);
        int i,substr=0;
        node *tnode=root;
        for(i=0;i<length;i++)
        {
                
                if(tnode->children[no[i]-'0']==NULL)
                {
                        tnode->children[no[i]-'0']=newNode();
                       // printf("Creating newNode() %c!\n", no[i]);

                         tnode=tnode->children[no[i]-'0'];;

                }
                else
                {
                        //printf("Didnt Create!\n");
                        if(tnode->children[no[i]-'0']->value==-1)
                                flag=1;
                        if(i==length-1)
                        {
                                tnode->value=-1;
                                flag=1;
                        }
                        tnode=tnode->children[no[i]-'0'];
                        substr=1;

                }
                //tnode=tnode->children[no[i]];
        }
        tnode->value=-1;
        return flag;
}

int main()
{
        long long int test,t,n,i;
        int check;
        char no[11];
        node *root=NULL;
        scanf("%lld",&test);
        root=newNode();
        for(t=0;t<test;t++)
        {
                //root=NULL;
                scanf("%lld",&n);
                flag=0;
               // root=newNode();
                check=0;
                strcpy(ans,"YES");
                for(i=0;i<n;i++)
                {
                        scanf("%s",no);
                        check=insert(no,root);
                        if(check==1)
                                strcpy(ans,"NO");
                }
                printf("%s\n",ans);
                for(i=0;i<10;i++)
                {
                        root->children[i]=NULL;
                      //  printf("Nullified ");
                }
                //root=NULL;
        }
        return 0;
}

