#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAXSIZE 100010
#define parent(i) ((i-1)/2)
#define left(i) (2*i+1)
#define right(i) (2*i+2)
#define min(a,b) ((a<b)? a:b)
int dist[MAXSIZE],visited[MAXSIZE]={0};
int position[MAXSIZE];
//int matrix[MAXSIZE][MAXSIZE];

struct node
{
        int data;
        struct node* next;
        int weight;
};
typedef struct node node; 
struct heap
{
        int vertex;
        int w;       

};

typedef struct heap heap;
node vertices[MAXSIZE];
heap a[MAXSIZE];
void swap(heap* x, heap* y)
{
        heap temp=*x;
        *x=*y;
        *y=temp;
}
int size=0;
long long int sum=0;
void min_heapify(int i)
{
        int left_child=left(i);
        int right_child=right(i);
        int min=i;
        if(left_child<size&&a[left_child].w<a[i].w)
                min=left_child;
        if(right_child<size&&a[right_child].w<a[min].w)
                min=right_child;
        if(min!=i)
        {
                int temp=position[a[i].vertex];
                position[a[i].vertex]=position[a[min].vertex];
                position[a[min].vertex]=temp;
                swap(&a[i],&a[min]);
                min_heapify(min);
        }
} 
int remove_min()
{
        if(size<=0)
                return;
        if(size==1)
        {
                size--;
                return a[0].vertex;
        }
        int root=a[0].vertex;
        a[0].w=a[size-1].w;
        position[a[0].vertex]=size-1;
        position[a[size-1].vertex]=0;
        a[0].vertex=a[size-1].vertex;
        size--;
        min_heapify(0);
        return root;
}                        
void insert(int key,int index)
{	
        int i=size;
        size++;
        a[i].w=key;
        a[i].vertex=index;
        position[index]=i;
        while(i>0&&a[parent(i)].w>a[i].w)
        {
                int temp_pos=parent(i);
                swap(&a[i],&a[parent(i)]);
                position[index]=temp_pos;
                i=parent(i);
        }
}
void decrease_key(int i, int new_val)
{
        
        a[i].w=new_val;
        while(i>0&&a[parent(i)].w>a[i].w)
        {
                position[a[i].vertex]=parent(i);
                position[a[parent(i)].vertex]=i;
                swap(&a[i],&a[parent(i)]);
                i=parent(i);
        }
}
long long int dijkstra(int c)
{

        node* temp=vertices[remove_min()].next;
        while(size>0)
        {
                node* temp=vertices[c].next;
                while(temp!=NULL)
                {
                        int temp_min=0;
                        if(visited[temp->data]==0)
                        {
                                if(dist[temp->data]>temp->weight)
                                {
                                        dist[temp->data]=temp->weight;
                                        //new_weight[temp->data]=temp->weight;
                                        decrease_key(position[temp->data],dist[temp->data]);
                                }

                        }
                        temp=temp->next;
                }
                int nxt=remove_min();      
                if(dist[nxt]!=INT_MAX)
                        sum+=dist[nxt];
                visited[nxt]=1;
                c=nxt;
        }
        return sum;


}
int main()
{
        int flag=0,n,s,m,w,c,b,t,i,v1,v2;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {   
                vertices[i].next=NULL;

        }   
        for(i=0;i<m;i++)
        {   
                scanf("%d%d%d",&v1,&v2,&w);
                
                node* temp=(node* )malloc(sizeof(node));
                temp->data=v2;    
                temp->weight=w;
                temp->next=vertices[v1].next;
                vertices[v1].next=temp;
                node* p=(node*)malloc(sizeof(node));
                p->data=v1; 
                p->weight=w;
                p->next=vertices[v2].next;
                vertices[v2].next=p;
        }
        //scanf("%d%d",&c,&b);
        for(i=1;i<=n;i++)
        {
                dist[i]=INT_MAX;
        }
        dist[1]=0;
        visited[1]=1;
        for(i=1;i<=n;i++)		
                insert(dist[i],i);
        //for(i=0;i<=3;i++)
          //      printf("%d %d %d\n",a[i].w,a[i].vertex,position[i]);

        long long int ans=dijkstra(1);
        for(i=1;i<=n;i++)
                if(dist[i]==INT_MAX)
                {
                        flag=1;
                        break;
                }
if(flag==1)
        printf("-1\n");
else
        printf("%lld\n",ans);
        return 0;
}                                                                                                                                                                                  
