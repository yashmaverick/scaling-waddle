#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//createstack
typedef struct Stack{
    long long int capacity;
    long long int size;
    long long int *elements;
}Stack;

Stack myStack;

void push(long long int element)
{
    myStack.elements[myStack.size++]=element;
}
void pop()
{
    if(myStack.size!=0)
        myStack.size--;
}

long long int isEmpty()
{
   if (myStack.size==0)
        return 1;
    else
        return 0;
}

long long int top()
{
   if (myStack.size==0)
        return -1;
   else
        return myStack.elements[myStack.size-1];
}


long long int  getMaxArea(long long int hist[],long long int n)
{
    long long int max_area = 0; // Init max area
    long long int topValue;  // To store top of stack
    long long int top_area; // To store area with top bar as the smallest bar

    // Run through all bars of given histogram
    long long int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
    if (isEmpty() || hist[top()] <= hist[i])
            push(i++);

        // If this bar is lower than top of stack, then calculate area of rectangle
        // with stack top as the smallest (or minimum height) bar. 'i' is
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            topValue = top();  // store the top index
            pop();  // pop the top

            // Calculate the area with hist[tp] stack as smallest bar
            top_area = hist[topValue] * (isEmpty() ? i : i - top() - 1);

            // update max area, if needed
            if (max_area < top_area)
                max_area = top_area;
        }
    }

    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (isEmpty() == 0)
    {
        topValue = top();
        pop();
        top_area = hist[topValue] * (isEmpty() ? i : i - top() - 1);

        if (max_area < top_area)
            max_area = top_area;
    }

    return max_area;
}

void createStack(int maxElements)
{
    myStack.size=0;
    myStack.capacity=maxElements;
    myStack.elements=(long long int *)malloc(sizeof(long long int)*maxElements);
}

void emptyStack()
{
    myStack.size=0;
    myStack.capacity=0;
    free(myStack.elements);
}

int main()
{
    long long int i,n;

    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
            exit(0);

        long long int arr[n];

        // Read numbers
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);


        createStack(n);

        myStack.capacity=n;

        printf("%lld\n",getMaxArea(arr,n));

        emptyStack();
    }
    return 0;
}

