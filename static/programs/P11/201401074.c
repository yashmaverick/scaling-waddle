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

void pop(node** head){
    if(*head==NULL){
        return;
    }
    node *temp=*head;
    *head=(*head)->next;
    free(temp);

}

int peek(node* head){
    if(head==NULL){
        return -1;
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
    head=(node*)malloc(sizeof(node));
    int a[1000000],width[1000000];
    long long int ar,max;
    int i,n;
    while(1){
        head=NULL;
        max=0;
        scanf("%d",&n);
        if(n==0){
            return 0;
        }
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++){
            if(i==0){
                width[i]=1;
                //printf("%d\n",width[0]);
                push(&head,0);
                continue;
            }
            for(;;){
                if(head!=NULL){
                    if(a[peek(head)] >= a[i]){
                        pop(&head);
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(head==NULL){
                width[i]=i+1;
            }
            else{
                width[i]=i-peek(head);
            }
            push(&head,i);
        }
        //for(i=0;i<n;i++){
        //    printf("%d ",width[i]);
        //}
        //printf("\n");
        while(head!=NULL){
            pop(&head);
        }
        for(i=n-1;i>=0;i--){
            if(i==n-1){
                width[i]+=0;
                push(&head,n-1);
                continue;
            }
            for(;;){
                if(head!=NULL){
                    if(a[peek(head)] >= a[i]){
                        pop(&head);
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(head==NULL){
                width[i]+=n-1-i;
            }
            else{
                width[i]+=peek(head)-i-1;
            }
            push(&head,i);
        }
        for(i=0;i<n;i++){
            ar=(long long int)width[i]*(long long int)a[i];
            //printf("i=%d width=%d area=%lld\n",i,width[i],ar);
            if(max<ar)
                max=ar;
        }
        printf("%lld\n",max);
    }
    return 0;
}










