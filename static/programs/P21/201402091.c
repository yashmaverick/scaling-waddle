#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{   
    int weight;
    int dest;
    struct node* next;
}node;
typedef struct vertex
{
    struct node* head;
}vertex;
typedef struct graph
{
    int e;
    int v;
    struct vertex* list;
}graph;
node* newnode(int dest,int weight)
{
    node* new=(node*)malloc(sizeof(node));
    new->dest=dest;
    new->next=NULL;
    new->weight=weight;
    return new;
}
graph* create(int v,int e)
{   int i;
    graph* g=(graph*)malloc(sizeof(graph));
    g->v=v;
    g->e=e;
    g->list=(vertex*)malloc((v+1)*sizeof(vertex));
    for(i=0;i<=v;i++)
        g->list[i].head=NULL;
    return g;
}
void addedge(graph* g,int s,int d,int w)
{
    node* nv=newnode(d,w);
    nv->next=g->list[s].head;
    g->list[s].head=nv;
    //nv=newnode(s,w);
    //nv->next=g->list[d].head;
    //g->list[d].head=nv;
}
typedef struct heapnode
{
    int value;
    int dist;
}heapnode;
typedef struct heap
{
    heapnode** array;
    int size;
    int* pos;
}heap;
heap* createheap(int n)
{
    heap* h=(heap*)malloc(sizeof(heap));
    h->size=1;
    h->array=(heapnode**)malloc((n+1)*sizeof(heapnode*));
    h->pos=(int*)malloc(n*sizeof(int));
    return h;
}
heapnode* addhnode(int v,int dist)
{
    heapnode* new=(heapnode*)malloc(sizeof(heapnode));
    new->value=v;
    new->dist=dist;
    return new;
}
void swap(int* a,int* b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
void swaph(heapnode* a,heapnode* b)
{
    heapnode temp=*b;
    *b=*a;
    *a=temp;
}
void inserth(heap* h,int val,int dist)
{   int i,p;
    h->pos[val]=h->size;
    h->array[h->size]=addhnode(val,dist);
    i=h->size;
    while(i>1)
    {   
        p=i/2;
        if(h->array[p]->dist > h->array[i]->dist)
        {
            swaph(h->array[p],h->array[i]);
            swap(&h->pos[h->array[p]->value],&h->pos[h->array[i]->value]);
        }
        i=p;
    }   
    h->size++;
}
void delete(heap* h)
{
    int mini=h->array[1]->dist;
    h->array[1]->dist=h->array[--h->size]->dist;
    h->array[1]->value=h->array[h->size]->value;
    int min,mindex,i=1;
    while(i<=(h->size-1)/2 && (h->array[i]->dist>h->array[2*i]->dist || h->array[i]->dist > h->array[2*i+1]->dist))
    {   
        if(h->array[2*i]->dist< h->array[2*i+1]->dist)
        {
            min=h->array[2*i]->dist;
            mindex=2*i;
        }
        else
        {
            min=h->array[2*i+1]->dist;
            mindex=2*i+1;
        }
        swaph(h->array[i],h->array[mindex]);
        swap(&h->pos[h->array[i]->value],&h->pos[h->array[mindex]->value]);
        i=mindex;
    }
}
void update(heap* h,int posi)
{
//    printf("Update\n");
    while((posi/2)>0 && h->array[posi]->dist < h->array[posi/2]->dist)
    {
        swaph(h->array[posi],h->array[posi/2]);
        swap(&h->pos[h->array[posi]->value],&h->pos[h->array[posi/2]->value]);
        posi/=2;
    }
}
/*void printgraph(graph* g)
{   
    int i;
    for(i=1;i<=g->v;i++)
    {
        printf("Adjacent vertices of %d are:",i);
        node* temp=g->list[i].head;
        while(temp)
        {
            printf("value=%d,weight=%d ",temp->dest,temp->weight);
            temp=temp->next;
        }
        printf("\n");
    }
}
void printheap(heap* h)
{   
    int i;
    printf("h->size=%d\n",h->size);
    for(i=1;i<h->size;i++)
    {
        printf("element=%d\n  ",h->array[i]->value);
        printf("dist=%d\n",h->array[i]->dist);
        printf("pos=%d\n",h->pos[h->array[i]->value]);
    }
}*/
int main()
{
    int v,e,v1,v2,wt,i,src,des;
        int* dis;
        scanf("%d%d",&v,&e);
        graph* g=create(v,e);
        heap* h=createheap(v);
        dis=(int*)malloc((v+1)*sizeof(int));
        for(i=1;i<=e;i++)
        {
            scanf("%d%d%d",&v1,&v2,&wt);
            addedge(g,v1,v2,wt);
        }
        //printgraph(g);
        scanf("%d%d",&src,&des);
        for(i=1;i<=v;i++)
        {
            if(i==src)
            {
                inserth(h,i,0);
                dis[i]=0;
            }
            else
            {
                inserth(h,i,INT_MAX);
                dis[i]=INT_MAX;
            }
        }
//        printheap(h);
        for(i=0;i<v;i++)
        {   
            //printheap(h);
            heapnode* x=h->array[1];
            if(x->dist<INT_MAX){
            node* temp=g->list[x->value].head;
  //          printf("hnode=%d\n",x->value);
    //        printf("hdist=%d\n",x->dist);
//            printf("%d\n",temp->dest);
//        if(temp==NULL) printf("HELLO\n");
            while(temp)
            {   
   //             printf("%d\n",temp->weight);
     //           printf("%d\n",temp->dest);
                int l=x->dist+temp->weight;
                int z=temp->dest;
                int w=h->pos[z];
//                printf("%d\n",w);
                int y=h->array[w]->dist;
                if(l<y)
                {   
 //                   printf("l=%d\n",l);
                    dis[temp->dest]=l;
                    h->array[h->pos[temp->dest]]->dist=l;
      //              printf("position=%d\n",h->pos[temp->dest]);
                    update(h,h->pos[temp->dest]);
                }
      //          printf("updated weight=%d\n",h->array[h->pos[temp->dest]]->dist);
                temp=temp->next;
            }
            if(x->value==des)
                break;
            delete(h);
        }
        else
            break;
        }
        if(dis[des]<INT_MAX)
            printf("%d\n",dis[des]);
        else
            printf("NO\n");
    return 0;
}
