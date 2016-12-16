#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        int x,y,wt;
}node;
node l[1000010];
int pa[1000010];
long long int sum=0;
int parent(int i)
{
        if(pa[i]==i)
                return i;
        return parent(pa[i]);
}

/*node * createNode(int val,int wt)
{
        node *tmp=(node*)malloc(sizeof(node));
        tmp->val=val;
        tmp->wt=wt;
        tmp->next=NULL;
        return tmp;
}
void addEdge(int src,int des,int wt)
{
        node *a=createNode(src,wt);
        node *b=createNode(des,wt);
        b->next=l[src];
        l[src]=b;
        a->next=l[des];
        l[des]=a;
}*/

int comp(const void *a, const void *b)
{
        return ((node*)a)->wt - ((node*)b)->wt;
}
int main()
{
        int n,m,i=0,j,x,y,w,count=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
                scanf("%d %d %d",&l[i].x,&l[i].y,&l[i].wt);
        sum=0;
        qsort((void*)l,m,sizeof(l[0]),comp);
        for(i=1;i<=n;i++)
                pa[i]=i;
        for(i=0;i<m && count != n-1; i++)
        {
                if(parent(l[i].x) != parent(l[i].y))
                {
                        count++;
                        sum+=l[i].wt;
                        pa[parent(l[i].x)]=pa[parent(l[i].y)];
//        printf("i:%d m:%d count:%d n:%d\n",i,m,count,n);
                }
        }
        if(i>=m && count < n-1)
                printf("-1\n");
        else
                printf("%lld\n",sum);
        return 0;
}
