#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define f(x) scanf("%lld",&x)
#define lld long long int
#define g(k,a,b) for(k=a;k<b;k++)
#define s(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
lld num1,num2,*heap1,*heap2;
void insert1(lld p)
{
    num1++;
    heap1[num1]=p;
    lld temp=num1,m;
    while(heap1[temp]<heap1[temp/2] && temp>1)
    {
        m=heap1[temp];
        heap1[temp]=heap1[temp/2];
        heap1[temp/2]=m;
        temp=temp/2;
    }
}
void insert2(lld p)
{
    num2++;
    heap2[num2]=p;
    lld temp=num2,m;
    while(heap2[temp]>heap2[temp/2] && temp>1)
    {
        m=heap2[temp];
        heap2[temp]=heap2[temp/2];
        heap2[temp/2]=m;
        temp=temp/2;
    }
}
lld delete1()
{
    lld a,b,temp;
    b=heap1[1];
    heap1[1]=heap1[num1];
    num1--;
    temp=1;
    while(2*temp<=num1)
    {
        if(2*temp==num1)
        {
            if(heap1[temp*2]<heap1[temp])
            {
                a=heap1[temp];
                heap1[temp]=heap1[2*temp];
                heap1[2*temp]=a;
            }
            break;
        }
        else if(heap1[temp]>heap1[temp*2] || heap1[temp]>heap1[2*temp+1])
        {
            if(heap1[2*temp]>heap1[2*temp+1])
            {
                a=heap1[2*temp+1];
                heap1[2*temp+1]=heap1[temp];
                heap1[temp]=a;
                temp=2*temp+1;
            }
            else
            {
                a=heap1[2*temp];
                heap1[2*temp]=heap1[temp];
                heap1[temp]=a;
                temp=2*temp;
            }
        }
        else
            break;
    }
    return b;
}
lld delete2()
{
    lld a,b,temp;
    b=heap2[1];
    heap2[1]=heap2[num2];
    num2--;
    temp=1;
    while(2*temp<=num2)
    {
        if(2*temp==num2)
        {
            if(heap2[temp*2]>heap2[temp])
            {
                a=heap2[temp];
                heap2[temp]=heap2[2*temp];
                heap2[2*temp]=a;
            }
            break;
        }
        else if(heap2[temp]<heap2[temp*2] || heap2[temp]<heap2[2*temp+1])
        {
            if(heap2[2*temp]<heap2[2*temp+1])
            {
                a=heap2[2*temp+1];
                heap2[2*temp+1]=heap2[temp];
                heap2[temp]=a;
                temp=2*temp+1;
            }
            else
            {
                a=heap2[2*temp];
                heap2[2*temp]=heap2[temp];
                heap2[temp]=a;
                temp=2*temp;
            }
        }
        else
            break;
    }
    return b;
}
int main()
{
    lld i,j,k,l,a,b,c,t,n,med=1,temp,d,ans;
    f(t);
    g(i,0,t)
    {s(a,b,c,n);
        num1=0;
        num2=0;
        heap1=(lld *)malloc(sizeof(lld)*(n+1));
        heap2=(lld *)malloc(sizeof(lld)*(n+1));
        insert2(1);
        ans=1;
        med=1;
        temp=1;
        g(k,2,n+1)
        {if((num2-num1)>1 || (temp>heap1[1]))
            {
                insert1(delete2());
            }
            if((num1-num2)>1)
                insert2(delete1());
            if(num2>=num1)
                med=heap2[1];
            else med=heap1[1];
            temp=(a*med+b*k+c)%(1000000007);
            ans=ans+temp;
            insert2(temp);

            
                
        }
        printf("%lld\n",ans);
        free(heap1);
        free(heap2);
    }
    return 0;
}


            







