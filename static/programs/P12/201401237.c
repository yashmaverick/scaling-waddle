#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int capacity;
    int size;
    int *elements;
}Stack;

long long int counter(int arr[], Stack *S,int n);
Stack *createStack(int maxElements);
void push(Stack *S,int element);
void pop(Stack *S);
int top(Stack *S);

int main()
{
    int i,n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        int arr[n];
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        Stack *root=createStack(n);
        long long int x=counter(arr,root,n);
        printf("%lld\n",x);
    }
    return 0;
}

long long int counter(int arr[], Stack *S,int n)
{
    int ma=0,i=0;
    long long count=0;
    int off,j,x;
    push(S,i);
    i++;
    int t=1;
    while(i<n-1)
    {

        x=arr[top(S)];        
        //build stack
        while(arr[i]<=x)
        {
            push(S,i);
            i++;
            x=arr[top(S)];
        }

        //possible left combinations
        if(S->size>2)
        {
            count=count+S->size-2;
            //subtract repeating heights
            int store=arr[S->elements[S->size-1]];
            //printf("STORE %d",store);
            for(j=(S->size)-2;j>0;j--)
            {
                if(arr[S->elements[j]]==store)
                    count--;
            }
            //printf("Add left %d ",S->size-2);
        }  
        off=n-i-1;
        if(off>0)
        {
            count+=off;//adding right
            //printf("Add right %d (%d -%d -1)\n",off,n,i);
        } 
        //check condition
        //printf("I %d",i);
        if(i==n)
        {
            
            while(S->size>2)
            {
                pop(S);
                count=count+S->size-2;
                //subtract repeating heights
                int store=arr[S->elements[S->size-1]];
                //printf("STORE %d",store);
                for(j=(S->size)-2;j>0;j--)
                {
                    if(arr[S->elements[j]]==store)
                        count--;
                }
                //printf("Add left");
            }  
            return count;
        }

        if(S->size==S->capacity)
            return count;
        pop(S);
        if(S->size==0)
        {
            push(S,i);
            i++;
        }
        //printf("%d\n\n",count);
    }
    return count;


}
Stack *createStack(int maxElements)
{
    Stack *S;
    S=(Stack *)malloc(sizeof(Stack));
    S->elements=(int *)malloc(sizeof(int)*maxElements);
    S->size=0;
    S->capacity=maxElements;
    return S;
}

void push(Stack *S,int element)
{
    if(S->size!=S->capacity)
        S->elements[S->size++]=element;
    return;

}
void pop(Stack *S)
{
    if(S->size==0)
    {
        printf("Stack is empty\n");
        return;
    }
    else
        S->size--;
    return;
}

int top(Stack *S)
{
    if(S->size==0)
        return;
    else
        return S->elements[S->size-1];
}
