#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node*next;
}node;

int visited[100000],count;

void insert(node **head,int val){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=val;
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

int dfs(node *v[],int start){
    visited[start-1]=1;count++;
    node *temp=v[start-1];temp=temp->next;
    while(temp!=NULL){
        if(!visited[temp->data-1]){
            dfs(v,temp->data);
        }
        temp=temp->next;
    }
    return count;
}

int main(){
    node *vertex[100000],*rev_vertex[100000];
    int v,e,a,b,i,j,t,ans;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&v);
        for(i=0;i<v;i++){
            a=i+1;
            vertex[i]=(node*)malloc(sizeof(node));
            vertex[i]->data=a;
            vertex[i]->next=NULL;
            rev_vertex[i]=(node*)malloc(sizeof(node));
            rev_vertex[i]->data=a;
            rev_vertex[i]->next=NULL;
        }
        for(i=0;i<v;i++){
            a=i+1;
            scanf("%d",&e);
            for(j=0;j<e;j++){
                scanf("%d",&b);
                insert(&rev_vertex[a-1],b);
                insert(&vertex[b-1],a);
            }
        }
        //for(i=0;i<v;i++){
        //    print(vertex[i]);
        //}
        //for(i=0;i<v;i++){
        //    print(rev_vertex[i]);
        //}
        for(i=0;i<v;i++){
            count=0;
            for(j=0;j<v;j++){
                visited[j]=0;
            }
            int x=dfs(vertex,i+1);
            //printf("%d\n",x);
            if(v==x){
                ans=-1;
                break;
            }
        }
        count=0;
        for(j=0;j<v;j++){
            visited[j]=0;
        }
        if(ans==-1)ans=dfs(rev_vertex,i+1);
        printf("%d\n",ans);
    }
    return 0;
}
