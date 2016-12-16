#include<stdio.h>
long long int stack[1000001],top=-1;
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
    long long int t,n,i;
    scanf("%lld",&t);
    while(t--)
    {
        top=-1;
        long long int flag=0;
        scanf("%lld",&n);
        long long int a[n],depth[n+1];
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<=n;i++)
            depth[i]=0;
        push(n);
        depth[a[stack[top]]]=0;
        long long int max=0;
        long long int temp_depth;
        for(i=n-1;i>=1;i--)
        {
            flag=0;
            while(top!=-1)
            {
                if(a[i]<a[stack[top]])
                {
                    flag=1;
                    temp_depth=depth[a[stack[top]]];
                    pop();
                }
                else
                    break;
            }
            if(flag==0)
            {
                push(i);
                depth[a[stack[top]]]=depth[a[stack[top-1]]]+1;
            }
            else
            {
                push(i);
                depth[a[stack[top]]]=temp_depth+1;
            }
        }
//        for(i=1;i<=n;i++)
  //          printf("depth of %lld= %lld\n",i,depth[i]);
       // printf("\n");
        long long int node_val;
        max=0;
        if(n==1)
            printf("%lld 0\n",a[1]);
        else
        {
            for(i=1;i<=n;i++)
            {
                if(depth[i]>max)
                {
                    max=depth[i];
                    node_val=i;
                }
            }
            printf("%lld %lld\n",node_val,max);
        }
        //        printf("\n");
    }
    return 0;
}



