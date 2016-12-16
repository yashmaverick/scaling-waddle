#include<stdio.h>
#include<stdlib.h>

typedef struct bag{
    long long int data;
    long long int no;
    struct bag* next;
    long long int* weights;
}bag;

bag *head=NULL;

bag *createNode(long long int n,long long int mod)
{
    long long int i,d,no,sum=0;
    //Create New Node
    bag* newNode=(bag *)malloc(sizeof(bag));
    newNode->next=NULL;

    scanf("%lld",&no);
    newNode->no=no;
    newNode->weights=(long long int *)malloc(no*sizeof(long long int));

    for(i=0;i<no;i++)
    {
        scanf("%lld",&d);
        sum+=d;
        sum%=mod;
        (newNode->weights[i])=d;
    }

    newNode->data=sum;
    return newNode;
}

bag* insert(bag *newNode)
{
    bag *previous, *temp;

    if(head==NULL)
        head=newNode;
    else if(newNode->data < head-> data)
    {
        newNode-> next = head;
        head=newNode;
    }
    else
    {
        previous = head;
        temp = head -> next;

        while((temp != NULL) && (newNode->data >= temp -> data))
        {
            previous = temp;
            temp = temp -> next;
        }

        if(temp == NULL)
            previous -> next = newNode;
        else
        {
            newNode -> next = temp;
            previous -> next = newNode;
        }
    }
    return head;
}
int main()
{
    
    bag *temp=NULL;
    long long int i,n,mod;
    scanf("%lld %lld",&n,&mod);
    for(i=0;i<n;i++)
        head=insert(createNode((i+1),mod));
    
    while (head !=NULL)
    {
        printf("%lld\n",head->data);
        for(i=0;i<head->no;i++)
            printf("%lld\n",head->weights[i]);
        
        temp=head;
        head=temp->next;
        free(temp->weights);
        free(temp);
        printf("\n");
    }

    return 0;
}

