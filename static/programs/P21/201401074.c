#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000000000000000 //10^18
#define min(a,b) (a<=b)?(a):(b)
#define swap(x,y) {x+=y;y=x-y;x-=y;} 

int pos[100005],a[100005],size;
long long int d[100005];

typedef struct node{
    int data;
    long long int weight;
    struct node* next;
}node;

void insertv(node **head,int data,int weight){
    node * temp=(node *)malloc(sizeof(node));
    temp->data=data;temp->weight=weight;
    temp->next=(*head)->next;
    (*head)->next=temp;
}

void printv(node *head[],int v){
    int i;
    for(i=0;i<v;i++){
        node *temp=head[i];
        fprintf(stderr, "%d :",i+1);
        temp=temp->next;
        while(temp!=NULL){
            fprintf(stderr,"(%d,%d) ",temp->data,temp->weight);
            temp=temp->next;
        }
        fprintf(stderr, "\n");
    }
}

void print_heap(){
    int i;
    fprintf(stderr, "Heap: ");
    for(i=0;i<size;i++)
        fprintf(stderr, "(%d,pos %d,wt %lld) ",a[i],pos[a[i]-1],d[a[i]-1]);
    fprintf(stderr, "\n");
}

int parent(int i){return (i-1)>>1;}
int left(int i){return (i<<1)+1;}
int right(int i){return (i<<1)+2;}

void bubbleup(int i){
    int p,c;
    while(d[a[parent(i)]-1]>d[a[i]-1] && parent(i)>=0){
        c=i;p=parent(i);
#ifdef JOYBOND
        fprintf(stderr,"(%d,pos %d,wt %lld) shifted from %d to %d\n",a[i],pos[a[i]-1],d[a[i]-1],i,p);
#endif
        swap(pos[a[p]-1],pos[a[c]-1]);
        swap(a[p],a[c]);
        i=p;
    }
}

void bubbledown(int i){
    int p,c;
    while(1){
        p=i;
        if(left(i)>=size && right(i)>=size) break;
        else if(right(i)>=size) c=left(i);
        else  c=(d[a[left(i)]-1]<=d[a[right(i)]-1])?(left(i)):(right(i));
        if(d[a[p]-1]>d[a[c]-1]){
            swap(pos[a[p]-1],pos[a[c]-1]);
            swap(a[p],a[c]);
            i=c;
        }
        else break;
    }
}

void dijkstra(node *v[],int n,int start, int end){
    int i,u,w,edge;

    for(i=0;i<n;i++){
        d[i]=MAX;
        a[i]=i+1;
        pos[i]=i;
        size++;
    }
    d[start-1]=0;
    bubbleup(start-1);
    while(size>0){
        u=a[0];
        a[0]=a[size-1];
        pos[a[0]-1]=0;
        size--;
        bubbledown(0);
        if(u==end)
            return;
        node *temp=v[u-1]->next;
        while(temp!=NULL){
            w=temp->data;
            edge=temp->weight;
            d[w-1]=min(d[w-1],d[u-1]+edge);
            bubbleup(pos[w-1]);
            temp=temp->next;
        }
#ifdef JOYBOND
        print_heap();
#endif
    }

}

int main(){
    node *vertex[100005];
    int n,m,a,b,i,wt;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        vertex[i]=(node*)malloc(sizeof(node));
        vertex[i]->data=i+1;
        vertex[i]->next=NULL;
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&wt);
        insertv(&vertex[a-1],b,wt);
        //insertv(&vertex[b-1],a,wt);
    }
    scanf("%d%d",&a,&b);
    size=0;
#ifdef JOYBOND
    printv(vertex,n);
#endif
    dijkstra(vertex,n,a,b);
    if(d[b-1]!=MAX)
        printf("%lld\n",d[b-1]);
    else 
        printf("NO\n");
    return 0; 
}
