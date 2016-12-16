#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tries{char val;char exists;char children;struct tries* next[10];}tries;
tries* insert(tries *root,char key[15],int n,int *flag,int len)
{
    //printf("root%c\n",root->val);
    //printf("    childindex%d\n",key[n]-'0');
    root->children='t';
    if(root->exists=='t')//already a number exists in the path which is a prefix to this,delete this sub tree
    {
        *flag=1;
        return NULL;
    }
    if(root->next[key[n]-'0']==NULL)
    {
        //child doesnt'exist
        tries *t=(tries*)malloc(sizeof(tries));
        t->val=key[n];
        int i;
        for(i=0;i<10;++i)
            t->next[i]=NULL;
        //printf("    childtocreate%c\n",t->val);
        if(n+1==len)
            {
                t->exists='t';
                t->children='f';
                root->next[key[n]-'0']=t;
                //printf("    child%c\n",root->next[key[n]-'0']->val);
            }
        else
        {
            //printf("    child%c\n",root->next[key[n]-'0']->val);
            root->next[key[n]-'0']=insert(t,key,n+1,flag,len);
        }
    }   
    else if(root->next[key[n]-'0']!=NULL)
    {  
        //printf("    child%c\n",root->next[key[n]-'0']->val);
        if(n+1==len)
            {
                root->next[key[n]-'0']->exists='t';

                if(root->next[key[n]-'0']->children=='t'||root->next[key[n]-'0']->exists=='t')//already a number exists below this guy,to which this num will be the prefix
                {   *flag=1;
                    return NULL;
                }
            }
        else   
        root->next[key[n]-'0']=insert(root->next[key[n]-'0'],key,n+1,flag,len);
    } 
    return root;
}


int main()
{
    //init 
    int i;
    int test,flag,num;
    char key[15];
    scanf("%d",&test);
    tries *myroot=(tries*)malloc(sizeof(tries)),*temp;

    while(test--)
    {
        myroot=(tries*)malloc(sizeof(tries)),*temp;
        myroot->val='-';
        myroot->exists='f';
        myroot->children='f';
        for(i==0;i<10;++i)
        myroot->next[i]=NULL;

        scanf("%d",&num);
        getchar();
        flag=0;
        for(i=0;i<num;++i)
        {
            scanf("%s",key);
            int len=strlen(key);
            //myroot alwyays begins with -, with the rest as it children
            
            if(flag==0)
            myroot=insert(myroot,key,0,&flag,len);
            else if(flag==1)
                continue;   

        }
        if(flag==1)
            printf("NO\n");
        else
            printf("YES\n");
        myroot=NULL;
    }
return 0;
}
