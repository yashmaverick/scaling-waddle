#include <stdio.h>

long long int n;
long long int a[100005][2];
long long int top;


void push(long long int x,long long int c)
{
    top=top+1;
    a[top][0]=x;
    a[top][1]=c;
}

void pop()
{
    if(top==-1)
        return;
    top=top-1;
}

void print()
{
    long long int i;
    for(i=0;i<=top;i++)
    {
        printf("a[%lld][%d]=%lld  ",i,0,a[i][0]);
        printf("a[%lld][%d]=%lld\n",i,1,a[i][1]);
    }
    printf("\n\n\n");
}


int main()
{
    long long int i,t,j,c;
    long long int maxa;
    long long int area,area1;
    long long int b[100005];
    for(;;)
    {
        maxa=0;
        scanf("%lld",&n);
        if(n==0)
            break;
        c=0;
        top=-1;
        for(i=0;i<n;i++)
        {
          //  maxa=0;
            scanf("%lld",&b[i]);
            if(top==-1)
                push(i,c);
          /*  else if(b[i]==b[a[top][0]])
            {
                //c=0;
                push(i,0);               
            }*/
            else if(b[i]>b[a[top][0]])
            {
                c=0;
                push(i,c);
            }
            else
            {
                c=0;
                //int x=a[top][0]
                while(top!=-1 && b[i]<=b[a[top][0]])
                {
                    area=(i-a[top][0]+a[top][1])*b[a[top][0]];
                    if(area>maxa)
                        maxa=area;
                    c=c+1+a[top][1];
                    pop();
            //       printf("c=%lld ",c);
                }
         //      printf("\n");
                push(i,c);
            }
       //     print();
        }
       // print();
        for(i=0;i<=top;i++)
        {
            area=(a[top][0]-a[i][0]+a[i][1]+1)*b[a[i][0]];
            if(area>maxa)
                maxa=area;
        }
        printf("%lld\n",maxa);
    }
    return 0;
}


