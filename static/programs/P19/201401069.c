#include<stdio.h>
#include<stdlib.h>

typedef struct a{
    int v;
    struct a *A[11];
    int end;
}node;

char nu[10];
node start;
int flag;
void insert()
{
    int i,a;
    node *point;
    point=&start;
    while(nu[i]!='\0')
    {
        a=nu[i]-'0';
/*        if(a==0)
        {
            i++;
            continue; 
        }
        */
        if(point->A[a]!=NULL)
        {
            point=point->A[a];
            if(point->end==100)
            {
                flag=1;
                break;
            }
            if(nu[i+1]=='\0')
            {
                point->end=100;
                for(a=0;a<10;a++)
                {
                    if(point->A[a]!=NULL)
                    {
                        flag=1;
                        break;
                    } 
                }
            }
        }
        else
        {
            point->A[a]=malloc(sizeof(node));
            point->A[a]->v=a;
            point=point->A[a];
            if(nu[i+1]=='\0')
            {
                point->end=100;
            }
        }
        i++;
    }
}

int main()
{
    int t,n,i,a;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        for(i=0;i<=10;i++)
        {
            start.A[i]=NULL;
        }
        scanf("%d",&n);
        while(n--)
        {
            i=0;
            scanf("%s",nu);
            insert();
        }
        if(flag==1)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}
