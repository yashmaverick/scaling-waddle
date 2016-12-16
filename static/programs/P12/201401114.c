#include<stdio.h>
typedef long long int lint;
typedef struct mount
{
    int ht;
    int index;
    int freq;
}mount;
int top,stack_total;
mount stack[1000000];
void push(lint x, int i)
{
    stack[++top].ht=x;
    stack[top].index=i;
    stack[top].freq=1;
    stack_total++;
}
void pop()
{
    stack_total-=stack[top].freq;
    top--;
}
int size()
{
    return top+1;
}
void find(int arr[], int N)
{
    int i;
    long long int count=0;
    for(i=0; i<N; i++)
    {
        if(top==-1)
            push(arr[i],i);
        else
        {
            if(arr[i]>stack[top].ht)
            {
                while(top!=-1 && arr[i]>stack[top].ht )
                {
                    count+=(lint)(stack[top].freq)*(N-i-1);
                    pop();
                }
                if(top>=0 && stack[top].ht==arr[i])
                {
                    stack[top].freq++;
                    stack_total++;
                    if(stack_total-stack[top].freq>=1)
                        count+=(lint)(stack_total-stack[top].freq-1);
                }
                else if(top>=0)
                {
                    count+=(lint)(stack_total-1);
                    push(arr[i],i);
                }
                else if(top<0)
                    push(arr[i],i);
            }
            else if(arr[i]<stack[top].ht)
            {
                push(arr[i],i);
                if(stack_total>=2)
                    count+=(lint)(stack_total-2);
            }
            else
            {
                stack[top].freq++;
                stack_total++;
                if(top>0)
                    count+=(lint)(stack_total-stack[top].freq-1);
            }
        }
    }
    printf("%lld\n", count);

}
int main()
{
    int N,i,j;
    int arr[1000000];
    while(1)
    {
        scanf("%d", &N);
        top=-1;
        stack_total=0;
        if(N==0)
            break;
        for(i=0; i<N; i++)
            scanf("%d", &arr[i]);
        find(arr,N);
    }	
    return 0;
}
