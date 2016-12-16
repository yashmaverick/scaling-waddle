//Submitted successfully on 5 March 2015 at 1826 hrs IST
#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

ll stack[101126];
ll fence[101126];

ll top,size,n;

//#define push(x) stack[++top]=x;


void push(ll x)
{
    //if(top==size-1)
    //    return;
    //else
        stack[++top]=x;
}


ll max;

ll tp;

void pop()
{
    //if(top==-1)
    //    return;
    //else
        top--;
}


void getmaxarea();


int main()
{
    ll i; 

    while(1)
    {
        scanf("%lld",&n);

        if(n==0)
            break;

        top=-1;
        size=n;

        for(i=0;i<size;i++)
            scanf("%lld",&fence[i]);

        getmaxarea();

        printf("%lld\n",max);

        /*
        for(i=0;i<=top;i++)
        {
            printf("%d-> ",stack[i]);
        }
        */
    }

    return 0;
}



void getmaxarea()
{
    ll i=0;

    ll area=0;

    max=0;

    //for(i=0;i<n;i++)
    while(i<n)
    {

        if((top==-1) || (fence[stack[top]]<=fence[i]))
            push(i++);        
        else
        {
            tp=stack[top];
            pop();

            if(top==-1)
                area=fence[tp]*i;
            else
                area=fence[tp]*(i-stack[top]-1);

            if(area>max)
                max=area;
        }
    }

    while(top!=-1)
    {
        tp=stack[top];
        pop();

        if(top==-1)
            area=fence[tp]*i;
        else
            area=fence[tp]*(i-stack[top]-1);

        if(area>max)
            max=area;
    }
    
}

