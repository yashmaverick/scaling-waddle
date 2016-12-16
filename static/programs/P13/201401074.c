#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void push(node** head,int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=*head;
    *head=temp;
}

int pop(node** head){
    if(*head==NULL){
        return -1;
    }
    int x=(*head)->data;
    node *temp=*head;
    *head=(*head)->next;
    free(temp);
    return x;
}

int peek(node* head){
    if(head==NULL){
        return ;
    }
    return head->data;
}

void print(node* head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main(){
    node* head;
    node* parent;
    head=(node*)malloc(sizeof(node));
    parent=(node*)malloc(sizeof(node));
    int n,i,a[100000],stackh,max,min,t;
    scanf("%d",&t);
    while(t--){
        head=NULL;
        parent=NULL;
        scanf("%d",&n);
        for(i=n-1;i>=0;i--){
            scanf("%d",&a[i]);
        }
        max=0;min=0;stackh=-1;
        for(i=0;i<n;i++){
            if(head==NULL){
                push(&head,a[i]);
                stackh++;
            }
            else if(a[i]>peek(head)){
                push(&parent,peek(head));
                push(&head,a[i]);
                stackh++;
            }
            else if(a[i]<=peek(head)){
                while(1){
                    if(a[i]>peek(parent) || parent==NULL)
                        break;
                    else{
                        while(peek(head)>peek(parent)){
                            pop(&head);
                            stackh--;
                        }
                        pop(&parent);
                        continue;
                    }
                }
                push(&head,a[i]);
                stackh++;
            }
            if(stackh>max){
                min=peek(head);
                max=stackh;
            }
            else if(stackh==max){
                if(peek(head)<min){
                    min=peek(head);
                }
            }
//            print(head);
  //          print(parent);
    //        printf("stack=%d max=%d min=%d\n",stackh,max,min);
      //      printf("---------------------------------------------\n");
        }
        printf("%d %d\n",min,max);
    }    
    return 0;
}
