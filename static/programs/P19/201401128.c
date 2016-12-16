#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int end;
    struct node *next[10];
};

typedef struct node DIGIT;
typedef DIGIT *LINK;

int main()
{
    int t,n,i,j,done;
    char c;
    scanf("%d",&t);
    LINK root,prev;
    root=(LINK)malloc(sizeof(DIGIT));
    char num[11];
    while(t--)
    {
        done=0;
        for(i=0;i<10;i++)
        {
            root->next[i]=NULL;
        }
        scanf("%d",&n);
        getchar();
        while(n--)
        {
            scanf("%[^\n]",num);
            getchar();
            c=num[0];
            if(root->next[c-'0']==NULL)
            {
                root->next[c-'0']=(LINK)malloc(sizeof(DIGIT));
                //printf("This node imalloced set 1 %llu\n",(unsigned long long ) root->next[c-'0']);
                root->next[c-'0']->end=0;
            }
            prev=root->next[c-'0'];
            for(i=1;num[i]!='\0';i++)
            {
                //printf("running for %c\n",num[i]);
                if(prev->end==1)
                {
                  //  printf("This node is 1 %llu\n",(unsigned long long ) prev);
                   // printf("breakindone1 %s %c\n",num,num[i]);
                    done=1;
                    break;
                }
                c=num[i];
              //  printf("%c is c\n",c);
                if(prev->next[c-'0']==NULL)
                {
                    prev->next[c-'0']=(LINK)malloc(sizeof(DIGIT));
                    prev=prev->next[c-'0'];
                //    printf("This node is malloced  %llu\n",(unsigned long long ) prev);
                    for(j=0;j<10;j++)
                    {
                        prev->next[j]=NULL;
                    }
                    prev->end=0;
                }
                else
                    prev=prev->next[c-'0'];
            }
            if(prev->end==1)
            {
             //   printf("done2 %s\n",num);
                done=1;
            }
         //   printf("This node is being set 1 %llu\n",(unsigned long long ) prev);
            prev->end=1;
            for(i=0;i<=9;i++)
            {
                if(prev->next[i]!=NULL)
                {
           //         printf("done3\n");
                    done=1;
                    break;
                }
            }
            if(done==1)
            {
                while(n--)
                {
                    scanf("%[^\n]",num);
                    getchar();
                }
                break;
            }
        }
        if(done==1)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
