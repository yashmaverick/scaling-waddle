#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int color[1000000],d[1000000],end;

void enq(node **head,node **tail,int val){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    if(*head==NULL && *tail==NULL){   
        *head=temp;
        *tail=*head;
        return;
    }
    (*tail)->next=temp;
    *tail=(*tail)->next;
}

int deq(node **head,node **tail){
    int x=(*head)->data;
    if(*head==*tail){
        *head=NULL;
        *tail=NULL;
    }
    else{
        node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    return x;
}

int peek(node *head){
    if(head==NULL){
        return -1;
    }
    return head->data;
}

int bfs(node *v[],int n,int start){
    int i,max=0;
    node *head = (node*)malloc(sizeof(node));
    node *tail = (node*)malloc(sizeof(node));
    head = NULL;
    tail = NULL;

    for(i=0;i<n;i++){
        color[i] = 0;
        d[i] = INT_MAX;
    }

    d[start-1]=0;
    color[start-1]=1;
    enq(&head,&tail,start);

    while(head != NULL){
        int u = peek(head);
        //if(v[u-1]==NULL)
        //printf("bad\n");
        // printf("u=%d\n",u);
        node *temp = v[u-1]->next;
        while(temp != NULL){
            if(color[temp->data-1] == 0){
                color[temp->data-1] = 1;
                d[temp->data-1] = d[u-1]+1;
                if(max<d[temp->data-1]){
                    end = temp->data;
                    max = d[temp->data-1];
                }
                enq(&head,&tail,temp->data);
            }
            temp = temp->next;
        }
        color[u-1] = 2;
        deq(&head,&tail);
    }
    //printf("done\n");
    return max;    
}

void insert(node **head,int val){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    node *temp=(*head)->next;
    (*head)->next=newnode;
    newnode->next=temp;
}

int main(){
    int v,a,b,i,diameter,t;
    node *vertex[1000000];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&v);
        for(i=0;i<v;i++){
            vertex[i] = (node*)malloc(sizeof(node));
            vertex[i]->data = i+1;
            vertex[i]->next = NULL;
        }
        for(i=0;i<v-1;i++){
            scanf("%d%d",&a,&b);
            insert(&vertex[a-1],b);
            insert(&vertex[b-1],a);
        }
        //for(i=0;i<v;i++){
        //    print(vertex[i]);
        //}
        bfs(vertex,v,1);
        diameter = bfs(vertex,v,end);
        printf("%d\n",diameter+1);
    }
    return 0;
}
