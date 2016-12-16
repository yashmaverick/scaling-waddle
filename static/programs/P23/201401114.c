#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lint;
typedef struct node
{
        lint val;
        struct node*next;
}node;
lint indegree[500001], heap[5000001], heapsize=0;
node*arr[100001];
lint list[500001],l=0;
int count;
node*insert(lint x, node*root)
{
        node*temp=malloc(sizeof(node));
        temp->val=x;
        temp->next=root;
        return temp;
}
void insert_heap(lint x)
{
        heap[++heapsize]=x;
        lint now=heapsize;
        while(now/2>=1 && heap[now/2]>heap[now])
        {
                heap[now]=heap[now/2];
                heap[now/2]=x;
                now=now/2;
        }
}

void heapify(lint index)
{
        if(2*index>heapsize)
                return;
        else if(2*index==heapsize)
        {
                lint temp;
                if(heap[index]>heap[2*index])
                {
                        temp=heap[index];
                        heap[index]=heap[2*index];
                        heap[2*index]=temp;
                }
                else
                        return;
        }
        else
        {
                lint now=index,temp, min_index;
                while(2*now+1<=heapsize)
                {
                        if(heap[2*now]<heap[2*now+1])
                                min_index=2*now;
                        else
                                min_index=2*now+1;
                        if(heap[now]>heap[min_index])
                        {
                                temp=heap[now];
                                heap[now]=heap[min_index];
                                heap[min_index]=temp;
                                now=min_index;
                        }
                        else
                                break;
                }
        }
}
lint delmin()
{
        lint minval=heap[1];
        heap[1]=heap[heapsize--];
        heapify(1);
        return minval;
}
void topsort(lint N)
{
        lint i, u;
        for(i=1; i<=N; i++)
                if(indegree[i]==0)
                        insert_heap(i);
        while(heapsize>=1)
        {
                u=delmin();
                l++;
                if(l<N)
                printf("%lld ", u);
                else if(l==N)
                        printf("%lld\n", u);
                node*ptr=arr[u];
                while(ptr!=NULL)
                {
                        indegree[ptr->val]--;
                        if(indegree[ptr->val]==0)
                                insert_heap(ptr->val);
                        ptr=ptr->next;
                }
        }


}
int main()
{
        lint N, M,i, p,q;
        scanf("%lld %lld", &N, &M);
        memset(indegree, 0, sizeof(indegree));
        for(i=0; i<M; i++)
        {
                scanf("%lld %lld", &p, &q);
                indegree[q]++;
                arr[p]=insert(q, arr[p]);
        }
        heap[0]=LONG_MAX;       
        topsort(N);
        
        return 0;
}
