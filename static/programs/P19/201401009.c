#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **a;
typedef struct node{
        int count;
        struct node *child[10];
}node;

typedef struct trie{
        struct node *root;
}trie;

void newtrie(trie *tr){
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        int i;
        newnode->count=0;
        for(i=0;i<10;i++){
                newnode->child[i]=NULL;
        }
        tr->root=newnode;
}

void insert(trie *tr,char a[]){
        int l;
        int i;
        node *trial;
        trial=tr->root;
        for(i=0;i<strlen(a);i++){
                l=a[i]-'0';
                if(trial->child[l]==NULL){
                        node *new;
                        new=(node *)malloc(sizeof(node));
                        int j;
                        new->count=0;
                        for(j=0;j<10;j++){
                                new->child[i]=NULL;
                        }
                        trial->child[l]=new;
                }
                trial=trial->child[l];
        }
        trial->count+=1;
        return ;
}

int search(trie *tr,char a[]){
        int level;
        node *test;
        test =tr->root;
        int flag=0;
        int i;
        for(i=0;i<strlen(a);i++){
                if(test->count>=1)
                        return 1;
                test=test->child[a[i]-'0'];
        }

        if(test->count>1)
                return 1;
        else
                return 0;
        /*
        if(test!=NULL){
                if(test->count==1){
                        for(i=0;i<10;i++){
                                if(test->child[i]!=NULL){
                                        flag=1;
                                }
                        }
                        if(flag==1){
                                return (test->count);
                        }
                }
                else if(test->count>1){
                        return 1;
                }
                else
                        return 0;

        }
        else
                return 0;*/
}
int main(){
        int test;
        scanf("%d",&test);
        while(test--){
                int n;
                scanf("%d",&n);
                trie tr;
                newtrie(&tr);
                int i;
                a=(char **)malloc(n*sizeof(char *));
                for(i=0;i<n;i++){
                    a[i]=(char *)malloc(12*sizeof(char));
                }
                int flag=0;
                for(i=0;i<n;i++){
                        scanf("%s",a[i]);
                        insert(&tr,a[i]);
                }
                for(i=0;i<n;i++){
                        int x=search(&tr,a[i]);
                        if(x==1){
                                printf("NO\n");
                                flag=1;
                                break;
                        }
                }
                if(flag==0)
                        printf("YES\n");
                free(a);
        }
        return 0;
}
