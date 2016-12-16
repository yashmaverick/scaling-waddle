#include<stdio.h>
typedef struct node
{
    int src;
    int des;
    int weight;
}node;
typedef struct Components
{
    int root;
    int height;
}Components;
void swap(node* a,node* b)
{
    node temp=*b;
    *b=*a;
    *a=temp;
}
int size;
void insert(node heap[],int src,int des,int wt)
{   int i,p;
    heap[++size].weight=wt;
    heap[size].src=src;
    heap[size].des=des;
    i=size;
    while(i>1)
    {   
        p=i/2;
        if(heap[p].weight>heap[i].weight)
            swap(&heap[p],&heap[i]);
        i=p;
    }   
}
node delete(node heap[])
{
    node mini=heap[1];
    heap[1]=heap[size];
    int min,mindex,i=1;
    while(i<=(size-1)/2 && (heap[i].weight>heap[2*i].weight || heap[i].weight>heap[2*i+1].weight))
    {   
        if(heap[2*i].weight<heap[2*i+1].weight)
        {
            min=heap[2*i].weight;
            mindex=2*i;
            swap(&heap[i],&heap[2*i]);
        }
        else
        {
            min=heap[2*i+1].weight;
            mindex=2*i+1;
            swap(&heap[i],&heap[2*i+1]);
        }
        i=mindex;
    }
    size--;
    return mini;
}
int find(Components parts[],int n)
{
    if(parts[n].root!=n)
        parts[n].root=find(parts,parts[n].root);
    return parts[n].root;
}
int main()
{
    int x,v,e,i,src,des,wt;
    long long int sum;
    scanf("%d%d",&v,&e);
    node heap[200005];
    Components parts[200005];
    size=0;
    for(i=1;i<=v;i++)
    {
        parts[i].root=i;
        parts[i].height=0;
    }
    for(i=0;i<e;i++)
    {   
        scanf("%d%d%d",&src,&des,&wt);
        insert(heap,src,des,wt);
    }
    i=0;
    sum=0;
    while(size)
    {   
        node x=delete(heap);
//        printf("%d\n",x.weight);
        int c1=find(parts,x.src);
        int c2=find(parts,x.des);
        if(c1!=c2)
        {   
            sum+=x.weight;
            if(parts[c1].height > parts[c2].height)
                parts[c2].root=c1;
            else if(parts[c2].height > parts[c1].height)
                parts[c1].root=c2;
            else
            {
                parts[c1].root=c2;
                parts[c2].height++;
            }
            i++;
        }
    }
    if(i==(v-1))
        printf("%lld\n",sum);
    else
        printf("-1\n");
    return 0;
}
