// #Authored : Jaipal Singh Goud
// Part of : 
// Date :
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

void scanint(int *p);
int pop();
void push(int n);

int stack[100005];
int top = -1;

int main()
{
    int i,j,k,test,n;
    int data,temp,max=0;
    int post[100005][2];
    int array[100005];

    scanf("%d",&test);
    while(test--)
    {
        top = -1;
        max = 0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            array[i] = k;
            post[k][0] = k;
            post[array[i]][1] = 0;
        }

        post[array[i-1]][1] = 0;                         // Level Of root is 0 

        for(i=n-1;i>=0;i--)
        {
            data = array[i];                    // Reverse Traversal of tree 
            if(top == -1)
            {
                push(data);                     // Push the value.
                if(i != (n-1))
                    post[data][1] = post[array[i+1]][1] + 1;   /* changed post[i+1] to post[array[i+1]] */
            }
            else if(data > stack[top])       
            {
                push(data);                     // Push Value.

                post[data][1] = post[array[i+1]][1] + 1;    // Level update is done for continuous set by adding one to the previous value.
                /* Post[data][1] refers to the level the value data in the tree. Post[array[i-1][1] refers to immediate previous element's level; */ 
            }
            else
            {
                while(stack[top] > data)
                {
                    temp = pop();
                }
                push(data);                                 // After all elements greater than it have been popped , the smaller element will then be pushed.
                post[data][1] = post[temp][1] + 1;          // The level of this node is the 1 + the level of the node that was last popped. This is either l/r child of the previous node.
            }
        }

        for(i=0;i<n;i++)
        {
            data = array[i];
            temp = post[data][1];
            if( max < temp)
            {          
                k = data;
                max = temp;
            }
            post[data][1] = 0;
        }
        printf("%d %d\n",k,max);
    }
    return 0;
}
void push(int n)
{
    top++;
    stack[top] = n;
}

int pop()
{
    int x = top;
    top--;
    return stack[x];
}

