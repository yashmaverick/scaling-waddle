#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
        int data;
        int weight;
        struct node *next;
}node;

typedef struct adj{
        node *head;
}adj;

adj *arr;
int *visit,*dist;

void newedge(adj *arr,int a,int b,int c){
        node *temp;
        temp=(node *)malloc(sizeof(node));
        temp->data=b;
        temp->weight=c;
        temp->next=arr[a].head;
        arr[a].head=temp;
}

typedef struct hpnode{
        int dat;
        int dist;
}hpnode;

hpnode *createhpnode(int dat,int dist){
        hpnode* temp=(hpnode *)malloc(sizeof(hpnode));
        temp->dat=dat;
        temp->dist=dist;
        return temp;
}

typedef struct hp{
        int size;
        int *pos;
        hpnode **ar;
}hp;

void swapnode(hpnode **a,hpnode **b){
        hpnode* t;
        t=*a;
        *a=*b;
        *b=t;
}

hp *heap;

void heapi(hp* heap,int index){
        int s,l,r;
        s=index;
        l=2*s+1;
        r=2*s+2;
        //        printf("%d %d %d\n",s,l,r);
        if(l<heap->size+1 && heap->ar[l]->dist<heap->ar[s]->dist)
                s=l;
        if(r<heap->size+1 && heap->ar[r]->dist<heap->ar[s]->dist)
                s=r;
        if(s!=index){
                hpnode *snode=heap->ar[s],*inode=heap->ar[index];
                heap->pos[snode->dat]=index;
                heap->pos[inode->dat]=s;
                swapnode(&heap->ar[s],&heap->ar[index]);
                //              printf("%d %d\n",s,index);
                heapi(heap,s);
        }
}

hpnode *getmin(hp *heap){
        if(heap->size==0){
                return NULL;
        }
        hpnode* top=heap->ar[0];
        hpnode* last=heap->ar[heap->size];
        heap->ar[0]=last;
        heap->pos[top->dat]=heap->size;
        heap->pos[last->dat]=0;
        heap->size--;
        heapi(heap,0);
        return top;
}

void remov(hp *heap,int v,int dist){
        int i=heap->pos[v];
        //    printf("%d--\n",i);
        heap->ar[i]->dist=dist;
        //    printf("%d -- %d\n",heap->ar[i]->dist,heap->ar[(i-1)/2]->dist);
        while(i && heap->ar[i]->dist<heap->ar[(i-1)/2]->dist){
                heap->pos[heap->ar[i]->dat]=(i-1)/2;
                heap->pos[heap->ar[(i-1)/2]->dat]=i;
                swapnode(&heap->ar[i],&heap->ar[(i-1)/2]);
                i=(i-1)/2;
        }
}

int isinheap(hp *heap,int dest){
        if(heap->pos[dest]<heap->size+1){
                return 1;
        }
        return 0;
}
void print(hp *heap){
        int i;
        for(i=0;i<heap->size+1;i++){
                //             printf("%d - ",heap->ar[i]->dat);
        }
        //   printf("\n");
}

int main(){
        int v,k;
        scanf("%d %d",&v,&k);
        int i;
        arr=(adj *)malloc((v+1)*sizeof(adj));
        visit=(int *)malloc((v+1)*sizeof(int));
        dist=(int *)malloc((v+1)*sizeof(int));
        for(i=0;i<=v;i++){
                arr[i].head=NULL;
        }
        for(i=0;i<k;i++){
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                newedge(arr,a,b,c);
        }
        int s,d;
        scanf("%d %d",&s,&d);
        heap=(hp *)malloc(sizeof(hp));
        heap->pos=(int *)malloc((v+1)*sizeof(int));
        heap->size=0;
        heap->ar=(hpnode **)malloc((v+1)*sizeof(hpnode*));
        for(i=0;i<=v;i++){
                dist[i]=INT_MAX;
                heap->ar[i]=createhpnode(i,dist[i]);
                heap->pos[i]=i;
        }
        heap->ar[s]=createhpnode(s,dist[s]);
        heap->pos[s]=s;
        //  for(i=0;i<=v;i++){
        //          printf("%d-",heap->pos[i]);
        //   }
        //   printf("\n");
        //  print(heap);
        dist[s]=0;
        remov(heap,s,dist[s]);
        //     for(i=0;i<=v;i++){
        //           printf("%d-",heap->pos[i]);
        //  }
        // printf("\n");
        heap->size=v;
        while( isinheap(heap,d) || heap->size==1){
                hpnode* min=getmin(heap);
                //        for(i=0;i<=v;i++){
                //               printf("%d-",heap->pos[i]);
                //      }
                //    printf("\n");
                int ver=min->dat;
                //printf("%d--%d\n",ver,dist[ver]);
                node* temp=arr[ver].head;
                while(temp){
                        //                       // printf("%d->%d\n",temp->data,temp->next->data);
                        int dest=temp->data;
                        //                        printf("---%d---%d\n",dest,isinheap(heap,dest));
                        //                      print(heap);
                        if(isinheap(heap,dest)  && dist[ver]!=INT_MAX && temp->weight+dist[ver]<dist[dest]){
                                dist[dest]=dist[ver]+temp->weight;
                                remov(heap,dest,dist[dest]);
                                //                            for(i=0;i<=v;i++){
                                //                                  printf("%d-",heap->pos[i]);
                                //                        }
                                //                      printf("\n");
                        }
                        temp=temp->next;
                }
        }
        //       for(i=0;i<=v;i++){
        if(dist[d]!=INT_MAX)
        printf("%d\n",dist[d]);
        else
                printf("NO\n");
        //     }
        return 0;
}

