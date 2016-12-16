#include<stdio.h>
#include<stdlib.h>
int min[100010],visited[100010],nmin,ans[100010];

typedef struct node
{
        int val;
        struct node *next;
}node;
node *l[100010],*r[100010];
node *createNode(int v)
{
        node *t=(node*)malloc(sizeof(node));
        t->val = v;
        t->next = NULL;
        return t;
}
void addEdgel(int x, int y)
{
        node *a=createNode(x);
        a->next = l[y];
        l[y] = a;
}
void addEdger(int x, int y)
{
        node *a=createNode(x);
        a->next = r[y];
        r[y] = a;
}
void insertMin(long long int v)
{
        long long int i,tmp;
        min[++nmin]=v;
        for(i=nmin;min[i]<min[i/2] && i>1;i/=2)
        {
                tmp=min[i];
                min[i]=min[i/2];
                min[i/2]=tmp;
        }
}
long long int delMin()
{
        long long int x=min[1],tmp;
        min[1]=min[nmin--];
        long long int i=1,j;
        while(2*i<=nmin)
        {
                if(min[2*i]<min[2*i+1])
                        j=2*i;
                else
                        j=2*i+1;
                if(min[j]<min[i])
                {
                        tmp=min[i];
                        min[i]=min[j];
                        min[j]=tmp;
                        i=j;
                }
                else
                        break;
        }
        return x;
}
int main()
{
        int n,m,i,x,y,sp=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
                scanf("%d %d",&x,&y);
                addEdgel(x,y);
                ans[y]++;
                addEdger(y,x);
        }
        for(i=1;i<=n;i++)
                if(l[i]==NULL)
                        insertMin(i);
        while(nmin != 0)
        {
                printf("%d",min[1]);
                sp++;
                node *tmp=r[min[1]];
                delMin();
                while(tmp != NULL)
                {
                        if(ans[tmp->val] != 0)
                                ans[tmp->val]--;
                        if(ans[tmp->val]==0)
                                insertMin(tmp->val);
                        tmp=tmp->next;
                }
                if(sp == n)
                        break;
                else
                        printf(" ");
        }
        printf("\n");
        return 0;
}
