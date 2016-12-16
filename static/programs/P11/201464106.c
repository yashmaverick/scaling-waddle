#include<stdio.h>
long long int stack[100001],top=-1;

void push(long long int val)
{
    stack[++top]=val;
}

void pop()
{
    --top;
}

int main()
{
    long long int n,area,max=0,i,x;
    scanf("%lld",&n);
    while(n!=0)
    {
        long long int a[n],L[n],R[n],LR[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            while(top!=-1)
            {
                if(a[i]<=a[stack[top]])
                    pop();
                else
                    break;
            }
                if(top==-1)
                    x=-1;
                else
                    x=stack[top];
                L[i]=i-x-1;
                push(i);
//            printf("L %d i %d\n",L[i],i);
        }
        while(top!=-1)
            pop();
        for(i=n-1;i>=0;i--)
        {
            while(top!=-1)
            {
                if(a[i]<=a[stack[top]])
                    pop();
                else
                    break;
            }
            if(top==-1)
                x=n;
            else
                x=stack[top];
            R[i]=x-i-1;
            push(i);
  //          printf("R: %d i: %d\n",R[i],i);
        }
        max=0;
        for(i=0;i<n;i++)
        {
            LR[i]=L[i]+R[i];
            area=a[i]*(LR[i]+1);
            if(area>=max)
                max=area;
        }
        printf("%lld\n",max);
        while(top!=-1)
            pop();
        scanf("%lld",&n);
    }
    return 0;
}








