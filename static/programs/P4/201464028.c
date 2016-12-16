#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct limit
{
    int AB;
    int AC;
}limit;

int func(const void *a,const void *b)
{
    limit *c=(limit *)a;
    limit *d=(limit *)b;
    if(c->AB==d->AB)
        return (c->AC)-(d->AC);
    else return (c->AB)-(d->AB);
}

int main()
{
    int i,j,k,l,A,B,C,count,t;
    limit *q;
    char cha;
    char s[1000005];
    scanf("%d%c",&t,&cha);
    //getchar();
    while(t--)
    {
	A=0;
        B=0;
        C=0;
        count=0;
        scanf("%s",s);
        q=(limit *)malloc(sizeof(limit)*(strlen(s)+1));
            q[0].AB=0;
            q[0].AC=0;
	    j=strlen(s);
            for(i=0;i<j;i++)
            {
            if(s[i]=='J')
            	A++;
            if(s[i]=='M')
            	B++;
            if(s[i]=='R')
            	C++;
            q[i+1].AB=A-B;
            q[i+1].AC=A-C;
            }
            qsort(q,j+1,sizeof(limit),func);
            A=q[0].AB;
            B=q[0].AC;
            C=1;
            for(i=1;i<=j;i++)
            {if(q[i].AB==A && q[i].AC==B)
            C++;
            else
            {
                count=count+(C*(C-1))/2;
                A=q[i].AB;
                B=q[i].AC;
                C=1;
            }
             //   printf("%d %d\n",q[i].AB,q[i].AC);
            }
        count=count+(C*(C-1))/2;
        printf("%d\n",count);
    }
    return 0;
}
