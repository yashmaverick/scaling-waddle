#include <stdio.h>

#include <string.h>

#include <stdlib.h>


typedef struct link
{
    int d;
    struct link *a[10];
}node;



int main()
{
    int t,n,m,x,y,j,i,k;
    scanf("%d",&t);
    for(m=1;m<=t;m++)
    {
        node *head=(node *)malloc(sizeof(node));
        int flag=0;
        for(i=0;i<10;i++)
        {
            head->a[i]=NULL;
        }
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            char s[15];
            scanf("%s",s);
            node *q=head;
            int l=strlen(s);
            for(k=0;k<l;k++)
            {
                int r=s[k]-48;
                if(q->a[r]==NULL)
                {
                    q->a[r]=(node *)malloc(sizeof(node));
                  //  printf("%d ",r);
                    for(j=0;j<10;j++)
                    {
                        q->a[r]->a[j]=NULL;
                    }
                }
                else
                {
                    int c=0;
                    for(j=0;j<10;j++)
                    {
                        if(q->a[r]->a[j]!=NULL)
                            c=1;
                    }
                    if(c==0)
                        flag=1;
                }
                q=q->a[r];
            }
          //  printf("NULL\n");
            for(j=0;j<10;j++)
            {
                if(q->a[j]!=NULL)
                {
                    flag=1;
                }
            }
        }
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
