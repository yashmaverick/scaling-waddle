#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define f(x) scanf("%d",&x)
typedef struct info
{
    int v;
    int l;
}info;
info cube[100000];
int start,end,prime[1000000],visit[10000],a,b,temp;
void prim()
{
    int k,j;
    for(k=2;k<=100;k++)
    {
        if(prime[k]==0)
        {
            for(j=k*k;j<=10000;j=j+k)
            {
                prime[j]=1;
            }
        }
    }
}
void push(int val,int lev)
{
if(val==b)
{
    printf("%d\n",lev);
    temp=-1;
    return ;
}
    cube[end].v=val;
    cube[end].l=lev;
        end++;

}
info pop()
{ info w;
    w=cube[start];
    start++;
    return w;
}
int create(int one,int tens,int hun,int thou,int pos,int level)
{int w,k,i;
    if(pos==1)
    {
        for(i=1;i<=9;i++)
        {if(i==thou)
            continue;
            w=1000*i+100*hun+10*tens+one;
            if(prime[w]==0 && w<10000)
            push(w,level+1);
        }
    }
    if(pos==2)
    {
        for(i=0;i<=9;i++)
        {if(i==hun)
            continue;
            w=1000*thou+100*i+10*tens+one;
            if(prime[w]==0 && w<10000)
                push(w,level+1);
        }
    }
    if(pos==3)
    {
        for(i=0;i<=9;i++)
        {if(i==tens)
            continue;
            w=1000*thou+100*hun+10*i+one;
            if(prime[w]==0 && w<10000)
                push(w,level+1);
        }
    }

    if(pos==4)
    {
        for(i=1;i<=9;i++)
        {if(i==one)
            continue;
            w=1000*thou+100*hun+10*tens+i;
            if(prime[w]==0 && w<10000)
                push(w,level+1);
        }
    }
}
int main()
{prim();
    int i,j,k,l,t,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        start=end=0;
        scanf("%d%d",&a,&b);
        push(a,0);
        temp=0;
   //     visit[]={0};
        //memset(visit,0,sizeof(visit));
        for(l=0;l<10000;l++)
            visit[l]=0;
        info w;
        int x1,x2,x3,x4,set,level;
        temp=1;
        while(start!=end && a!=b)
        {w=pop();
            set=w.v;
                level=w.l;

            if(visit[w.v]==0)
            {   visit[w.v]=1;
                x1=set%10;
                set/=10;
                x2=set%10;
                set/=10;
                x3=set%10;
                set/=10;
                x4=set%10;
            
            create(x1,x2,x3,x4,1,w.l);
            if(temp==-1)
                break;
            create(x1,x2,x3,x4,2,w.l);
            if(temp==-1)
                break;
            create(x1,x2,x3,x4,3,w.l);
            if(temp==-1)
                break;
            create(x1,x2,x3,x4,4,w.l);}
                if(temp==-1)
                    break;
        }
       // if(temp!=-1)
         //   printf("Impossible\n");
}
return 0;
    }
