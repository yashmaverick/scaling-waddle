#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int k=0;
long long int *stack;
void push(long long int item)
{
    stack[k++]=item;
}
long long int pop()
{
    return stack[k--];
}
long long int top()
{
    return stack[k];
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    while(n)
    {
        long long int i,ans=0,j,start,maxtemp;
        long long int *a;
        a = (long long int *)malloc(sizeof(long long int)*n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        /*stack = (long long int *)malloc(sizeof(long long int)*n);
        for(i=0;i<n;i++)
          if(a[i]>top())
              push(a[i]);
          else
          {
              while(top()>a[i])
              {
                  ans++;
                  pop();
            }
        
          }
        */
        i = 0;
        while(i<n)
        {
            j = i+1;
            start = a[i];
            maxtemp = a[j];
            while(j<n)
            {
                if(a[j]>start)
                {
                    ans += n-(j+1);
                    break;
                }
                if(a[j]>maxtemp)
                {
                    maxtemp=a[j];
                }
                else if(a[j]<maxtemp)
                    ans++;
                j++;
            }
            i++;
        }
        printf("%lld\n",ans);
        scanf("%lld",&n);
    }
    return 0;
}
