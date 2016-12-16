/* ALGORITHM:
 * Using a stack of structures which stores the value (from input array), index ( corresponding to the value from the input array) and index value 
 * of the minimum (with highest index no.) wrt to the current value, which is basically the point of division between the left subtree and right 
 * subtree considering that that element is the root at that level of the tree.
 *
 * Using a recursive function we basically simulate a tree and thus find the max. depth and the deepeest node.
 *
 * Input array -> a
 * Stack of structures -> stack
 * minpos -> array which stores the index value of the reqd. minimum wrt to the value at the corresponding index position of array, a.
 */
#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

typedef struct arstack
{
    ll value;
    ll index;
    ll minpos;
}arstack;

ll a[100000],minpos[100000];

arstack stack[100000];

ll top,n;

void push(ll value,ll index,ll minpos)
{
    if(top==n-1)
        return;
    else
    {
        stack[++top].value=value;
        stack[top].index=index;
        stack[top].minpos=minpos;
    }
}

void pop()
{
    if(top==-1)
        return;
    else
        top--;
}

ll depth=-1,node=0;

void getdepth(ll,ll,ll);

int main()
{
    ll t,i;

    scanf("%lld",&t);

    while(t-->0)
    {
        depth=-1;
        node=100001;
        scanf("%lld",&n);

        top=-1;

        /*
        if(n==1)
        {
            scanf("%lld",&i);
            printf("1 0\n");
        }
        else
        {
        */
            for(i=0;i<n;i++)
            {  minpos[i]=-1;

                scanf("%lld",&a[i]);

                if(top==-1 && i==0)
                {
                    push(a[i],i,-1);
                    minpos[i]=-1;
                }
                else if(a[i]>stack[top].value)
                {
                    push(a[i],i,stack[top].index);
                    minpos[i]=stack[top].minpos;
                }
                else if(a[i]<stack[top].value)
                {
                    while(a[i]<stack[top].value)
                        pop();
                    if(top==-1)
                        push(a[i],i,-1);
                    else
                        push(a[i],i,stack[top].index);
                    minpos[i]=stack[top].minpos;
                }
            }

            getdepth(0,n-1,0);

            if(n==1)
                printf("1 0\n");
            else
                printf("%lld %lld\n",node,depth);
       // }

        
        //printf("\n");
        /*
        for(i=0;i<n;i++)
        {
            printf("%lld-> ",minpos[i]);
        }

        printf("\n");
        */
        

        //getdepth(0,n-1,0);

        //printf("%lld %lld\n",node,depth);
    }

    return 0;
}

void getdepth(ll start,ll end,ll count)
{
    if(start==end) // current node has no child(s)
    {
        if(count>depth)// || a[start]<node)
        {
            depth=count;
            node=a[start];               
        }

        if(count == depth)
            if(node > a[start])
                node=a[start];
        
        return;
    }
    else if(end<start) // to avoid seg fault
        return;
    else if(start>end)
        return;

    if(minpos[end]==-1)
        getdepth(start,end-1,count+1);

    else if(minpos[end]==end-1)
        getdepth(start,end-1,count+1);

    else
    {
    getdepth(start,minpos[end],count+1); // to check left subtree's
    getdepth(minpos[end]+1,end-1,count+1); // to check right subtree's
    }
}

