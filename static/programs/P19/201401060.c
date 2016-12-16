#include<stdio.h>
#include<stdlib.h>
struct tries
{
    struct tries * edges[10];
    int end;
    int prefix;
};

int insert(struct tries * vertex,char * num)
{
    int k;
    int ret=0;
    if (num[0]=='\0')
    {
        if(vertex->end==0)
        vertex->end=1;
        else
            vertex->prefix=1;
        //printf("i am here\n");
    }
    else
    {
        struct tries * t=(struct tries *)malloc(sizeof(struct tries));
        //if(vertex->prefix=0)
        //{
        vertex->prefix=1;
        char c=num[0];
        k=(int)c-48;
        if (vertex->edges[k]==NULL)
        {
            int i;
            t->end=0;
            t->prefix=0;
            for(i=0;i<10;i++)
                t->edges[i]=NULL;
            vertex->edges[k]=t;
        }
       
        //num++;
        ret=insert(vertex->edges[k],num+1);
    }
//    printf("num ->%s\n",num);
  //  printf("k->%d\nret->%d\n",k,ret);
   // printf("vertex->end :%d\n",vertex->end);
    //printf("vertex->prfix :%d\n",vertex->prefix);
    if((vertex->end==1 && vertex->prefix==1)||ret==1)
        return 1;
    else return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    int i,ret=0;
    int k;
    for(k=0;k<t;k++)
    {
        int n;
        scanf("%d",&n);
        int j;
        ret=0;
        struct tries * t=(struct tries*)malloc(sizeof(struct tries)*10);
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                t[i].edges[j]=NULL;
            }
            t[i].end=0;
            t[i].prefix=0;
        }
        int tn;

        for(j=0;j<n;j++)
        {
            if (ret==0)
            {
                char num[11];
                scanf("%s",num);
                tn=(int)num[0]-48;
                //t[tn].end=0;
                //t[tn].prefix=1;
                ret=insert(&t[tn],num+1);
            }
            else
            {
                int ln;
                scanf("%d",&ln);
            }
        }
        if (ret==1 || (t[tn].end==1 && t[tn].prefix==1))
            printf("NO\n");
        else
            printf("YES\n");

        free(t);

    }
    return 0;
}
