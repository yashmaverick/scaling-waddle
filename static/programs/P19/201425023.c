#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
        int data;
        struct node *numbers[11];
}node;
int k;
typedef struct strings
{
        char str[100];
}strings;
//char *s;
node *root;
node* create_node()
{
        node *q=malloc(sizeof(node));
        for(k=0;k<10;k++)
                q->numbers[k]=NULL;
        q->data=-1;
        return q;
}
void insert(char s[])
{
        int len=strlen(s);
        int index;
        int level=0;
        if(root==NULL)
                root=create_node();
        node *q=root;
        for(level=0;level<len;level++)
        {
                index = s[level]- '0';
                if(q->numbers[index]==NULL)
                        q->numbers[index]=create_node();
                q=q->numbers[index];
        }
        q->data+=1;
        //   printf("%d %d--\n",index,q->data);
}
int search(char s[])
{
        node *q=root;
        int index=0;
        int len=strlen(s);
        int level=0;
        //        printf("%s",s);
        for(level=0;level<len;level++)
        {
                int index = s[level] - '0';
                if(q->numbers[index]!=NULL){
                        q=q->numbers[index];
                        //                        printf("--%d %d\n",index,q->data);
                        if(q->data!=-1 && level!=len-1){
                                //                            printf("a\n");
                                return 1;
                        }
                        if(level==len-1 && q->data>0){
                                return 1;
                        }
                }
                else
                        break;
                //return -1;
        }
        //        printf("--%d--\n",q->data);
        // if( q->data==-1)
        //         return 1;
        return -1;
}
int main()
{
        int t,n,i,j,flag;
      //  strings *s1;
        scanf("%d",&t);
        // s1=malloc(sizeof(strings)*n);
        for(i=0;i<t;i++)
        {
                //char *s;
                //node *root;
                strings *s1;
                
                flag=-1;
                scanf("%d",&n);
                getchar();
                s1=malloc(sizeof(strings)*n);
                for(j=0;j<n;j++)
                {
                        scanf("%s",s1[j].str);
                        insert(s1[j].str);
                }

                for(j=0;j<n;j++)
                {
                        //        printf("\n\n-%d-\n\n",search(s1[j].str));
                        if(search(s1[j].str)==-1)
                                flag=1;
                        else {
                                flag=0;
                                break;
                        }
                }
                if(flag==0)
                        printf("NO\n");
                else printf("YES\n");
                for(j=0;j<11;j++)
                        root->numbers[j]=NULL;
              //  free(s1);
             //   free(root);
          //    free(q);
        }
        return 0;
}
