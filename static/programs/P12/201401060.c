#include<stdio.h>
int main()
{
   long long int n;
    scanf("%lld",&n);
    while(n!=0)
    {
        int stack[500002];
        int top=-1,i;
        long long int count=0;
        int val;
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
            if(top==-1)
            {
                top++;
                stack[top]=val;
            }
            else
            {
                while(stack[top]<val && top>=0)
                {
                    top--;
                    count++;
                }
                int index=top;
                while(stack[index]==val && index>=0)
                {
                    index--;
                    count++;
                }
                if(index>=0 && stack[index]>val)
                    count++;
                top++;
                stack[top]=val;
            }
        }
        count=((n*(n-1))/2)-count;
        printf("%lld\n",count);
        scanf("%lld",&n);
    }
    return 0;
}    
