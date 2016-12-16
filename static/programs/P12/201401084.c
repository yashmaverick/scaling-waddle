#include <stdio.h>

long long int n;
long long int a[500005];
long long int top;


void push(long long int x)
{
    top=top+1;
    a[top]=x;
}



void pop()
{
    if(top==-1)
        return;
    top=top-1;
}



void print()
{
    long long int j;
    for(j=0;j<=top;j++)
    {
        printf("a[%lld]=%lld\n",j,a[j]);
    }
    printf("\n\n\n");
}



int main()
{
    long long int ans,i,c;
    long long int b[500005];
    for(;;)
    {
        scanf("%lld",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&b[i]);
        }
        ans=0;
        top=-1;
        push(0);
        c=1;
        for(i=1;i<n;i++)
        {
            if(b[i]<=b[a[top]])
            {
                push(i);
            }
            else
            {
                while(top!=-1 && b[i]>b[a[top]])
                {
                    if(top>0 && b[a[top]]==b[a[top-1]])
                    {
                        c++;
                        pop();
                        continue;
                    }
                    if(top!=0)
                        ans=ans+2*c+c*(c-1)/2;
                    else
                        ans=ans+c+c*(c-1)/2;
                    c=1;
                    pop();
                 //   print();
                  //  printf("ans=%d\n",ans);
                }
                push(i);
            }
           // print();
        }
        while(top>=0)
        {
            if(top>0 && b[a[top]]==b[a[top-1]])
            {
                c++;
                pop();
                continue;
            }
            if(c==1)
            {
                if(top!=0)
                   ans=ans+1;
            }
            else
            {
                if(top!=0)
                    ans=ans+c+c*(c-1)/2;
                else
                    ans=ans+c*(c-1)/2;
            }
            c=1;
            pop();
           // print();
           // printf("ans=%d\n",ans);
        }
        ans=n*(n-1)/2-ans;
      //  printf("ans=%d\n",ans);
        printf("%lld\n",ans);
    }
    return 0;
}

