#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

long long int stack[100000],k;
long long int top=-1;
void push(int element)
{
    top++;
    stack[top]=element;
    return;
}
int pop()
{
    k= stack[top];
    top--;
    return k;
}

int main()
{
    long long int arr[100001],p,q,i,j,k,n,indexright[100001],indexleft[100001];
    long long int maxarea,area;

    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
            break;

        long long int max=0;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        push(0);

        for(i=1;i<n;i++)
        {
            if(arr[i]>=arr[stack[top]])
                push(i);
            else
            {
                while(arr[i]<arr[stack[top]])
                {    
                    if(top<0)
                        break;
                    k=pop();
                    indexright[k]=i;
                }
                push(i);
            }
        }
        while(top>=0)
        {
            k=pop();
            indexright[k]=n;
        }
        push(n-1);
        for(i=n-2;i>=0;i--)
        {
            if(arr[i]>=arr[stack[top]])
                push(i);
            else
            {
                while(arr[i]<arr[stack[top]])
                { 
                    if(top<0)
                        break;
                    k=pop();
                    indexleft[k]=i;
                }
                push(i);
            }
        }
        while(top>=0)
        {
            k=pop();
            indexleft[k]=-1;
        }
        area=0;
        maxarea=0;
//        for(i=0;i<n;i++)
  //              printf("%lld %lld\n",indexleft[i],indexright[i]);
        for(i = 0; i < n; i++)
        {
            q = (indexright[i] - indexleft[i] - 1);
            area = q * arr[i];
//            printf("%d %lld\n",i,area);
            if(area >= maxarea)
                maxarea = area;
        }
        printf("%lld\n", maxarea);
    }
    return 0;
}
