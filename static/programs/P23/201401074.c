#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int dep[100003],visited[100003],time;

void insert(node **head,int data){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=(*head)->next;
    (*head)->next=temp;
}

void print(node *head){
    printf("vertex %d : ",head->data);
    head=head->next;
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void dfs(node *vertex[],int v){
    visited[v-1]=1;
    node *temp=vertex[v-1];temp=temp->next;
    while(temp!=NULL){
        if(!visited[temp->data-1]){
            dfs(vertex,temp->data);
        }
        temp=temp->next;
    }
    time++;
    //printf("time\t%d\n",time);
    dep[time-1]=v;
}

int main(){
    node *vertex[100003];
    int a,b,v,e,i;
    time=0;
    scanf("%d%d",&v,&e);
    for(i=0;i<v;i++){
        vertex[i]=(node*)malloc(sizeof(node));
        vertex[i]->data=i+1;
        vertex[i]->next=NULL;
        visited[i]=0;
    }
    for(i=0;i<e;i++){
        scanf("%d%d",&a,&b);
        insert(&vertex[a-1],b);
    }
    //for(i=0;i<v;i++){
        //print(vertex[i]);
    //}
    for(i=v-1;i>=0;i--){
        if(!visited[i]){
            dfs(vertex,i+1);
        }
    }
    for(i=v-1;i>0;i--){
        printf("%d ",dep[i]);
    }
    printf("%d\n",dep[0]);
    return 0;
}
