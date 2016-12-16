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
    int a[500000],left[500000],right[500000];
    int i,n,r,l,j;
    long long int ans;
    while(1){
        ans=0;
        head=NULL;
        scanf("%d",&n);
        if(n==0){
            return 0;
        }
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++){
            if(i==0){
                push(&head,0);
                continue;
            }
            if(a[i]>a[peek(head)] && head!=NULL){
                while(1){
                    if(a[i]>a[peek(head)] && head!=NULL){
                        left[peek(head)]=i;
                        pop(&head);
                    }
                    else if(head==NULL){
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            push(&head,i);
        }
        while(head!=NULL){
            left[peek(head)]=-1;
            pop(&head);
        }
        for(i=0;i<n;i++){
                    //printf("%d ",left[i]);
            if(left[i]!=-1){
                ans+=(long long int)n-1-(long long int)left[i];
            }
        }
        //printf("\n");
        for(i=n-1;i>=0;i--){
            if(i==n-1){
                push(&head,n-1);
                continue;
            }
            if(a[i]>a[peek(head)] && head!=NULL){
                while(1){
                    if(a[i]>a[peek(head)] && head!=NULL){
                        right[peek(head)]=i;
                        pop(&head);
                    }
                    else if(head==NULL){
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            push(&head,i);
        }
        while(head!=NULL){
            right[peek(head)]=-1;
            pop(&head);
        }
        for(i=0;i<n;i++){
            //printf("%d ",right[i]);
            if(right[i]!=-1){
                ans+=(long long int)right[i];
            }
        }
        //printf("\n");
        //printf("%lld\n",ans);
        for(i=0;i<n-2;i++){
            for(j=i+2;j<n;j++){
                if(((i<left[i] && left[i]<j) && left[i]!=-1)&&((i<right[j] && right[j]<j) && right[j]!=-1)){
                    ans--;
                    //printf("i=%d j=%d left[i]=%d right[j]=%d\n",i,j,left[i],right[j]);
                }
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}










