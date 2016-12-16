#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
        int data;
        struct node *next;
}node;

typedef struct adj{
        node *head;
}adj;

adj arr[600000];
int d[600000],heap[600000],heapsize=-1,count=0,n;

void newedge(adj* arr,int a,int b){
        node* temp=(node *)malloc(sizeof(node));
        temp->data=b;
        temp->next=arr[a].head;
        arr[a].head=temp;
        return ;
}

void minheapify(int i){
        int p=(i-1)/2;
        if(i<=0)
                p=-1;
        if(p>=0 && heap[p]>heap[i]){
                int temp=heap[p];
                heap[p]=heap[i];
                heap[i]=temp;
                minheapify(p);
        }
}

void minheapify1(int i){
        int q,w,e,r;
        e=i;
        q=2*i+1;
        w=2*i+2;
        if(heap[q]<heap[e] && q<=heapsize){
                e=q;
        }
        if(heap[w]<heap[e] && w<=heapsize){
                e=w;
        }
        if(e!=i){
                int t=heap[i];
                heap[i]=heap[e];
                heap[e]=t;
                minheapify1(e);
        }
}

void insert(int i){
        heapsize++;
        heap[heapsize]=i;
        minheapify(heapsize);
}

void extract(void){
        int q;
        if(heapsize>-1){
                q=heap[0];
                int t=heap[0];
                heap[0]=heap[heapsize];
                heap[heapsize]=t;
                heapsize--;
                minheapify1(0);
                count++;
        }
        if(count<n)
                printf("%d ",q);
        else if(count==n){
                printf("%d\n",q);
                return ;
        }
        node* temp=(node *)malloc(sizeof(node));
        temp=arr[q].head;
        while(temp){
               // printf("%d--\n",temp->data);
                d[temp->data]--;
                if(d[temp->data]==0)
                        insert(temp->data);
                temp=temp->next;
        }
        extract();
        return ;
}

/*int isempty(int *heap){
        if(heapsize<0){
                return 1;
        }
        else
                return 0;
}*/
int main(){
        int m;
        scanf("%d %d",&n,&m);
        int i;
        //arr=(adj *)malloc((n+1)*sizeof(adj));
        //d=(int *)malloc((n+1)*sizeof(int));
        for(i=0;i<=n;i++){
                arr[i].head=NULL;
                d[i]=0;
        }
        //heap=(int *)malloc((n+1)*sizeof(int));
        for(i=0;i<=n;i++){
                heap[i]=INT_MAX;
        }
        for(i=0;i<m;i++){
                int a,b;
                scanf("%d %d",&a,&b);
                newedge(arr,a,b);
                d[b]++;
        }
        for(i=1;i<=n;i++){
                if(d[i]==0){
                        insert(i);
                        d[i]=-1;
                }
        }
        //        for(i=0;i<=heapsize;i++)
        //                printf("%d-%d ",heap[i],i);
        //        printf("\n");
        extract();
        //        printf("\n--");
        //        for(i=0;i<=heapsize;i++)
        //                printf("%d-%d ",heap[i],i);
        //        printf("\n");
        //   printf("%d\n\n",isempty(heap));
        //        while(count!=n){
        //         printf("a\n");
        //              for(i=1;i<=n;i++){
        //                    if(d[i]==0){
        //                          insert(i);
        //                     }
        //               }
        // for(i=0;i<=heapsize;i++)
        //         printf("%d ",heap[i]);
        // printf("\n");
        //        extract();
        // }
        //        free(heap);
        //        free(arr);
        //        free(d);
        return 0;
}
