#include<stdio.h>
typedef long long int lle;
lle n,a[500010],b[500010],n1,count;
void push(int num)
{
 n1++;
 b[n1]=num;
}
void pop()
{
n1--;
}
void bottompop(int num1)
{
 lle j;
 if(num1==0)
 {
     n1=n1+1;
     for(j=n1+1;j>0;j--)
         {
             b[j]=b[j-1];
         }
 }
 else
 {
 for(j=num1;j<=n1;j++)
 {
     b[j-num1+1]=b[j];
 }
 n1=n1-count+1;
 }
}
int main()
{
    lle i,j,k,sum,t,t1;
    while(1)
    {
    scanf("%lld",&n);
    if(n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
         b[0]=a[0];n1=0;count=0;sum=0;

        for(i=1;i<n;i++)
        {
            if(a[i]<=b[n1])
            {
                t=n1;
                while(a[i]<=b[t]&&t>=0)
                {
                 t--;
                }
                count=t+1;
               // printf("fsum==%lld\n",count*(n-i-1));
                sum=sum+count*(n-i-1);
                bottompop(count);
                b[0]=a[i];
                t1=0;
                while(b[t1]<=a[i]&&t1<=n1)
                {
                    t1++;
                }
                if(n1-t1>=0)
                sum=sum+n1-t1;
               // printf("n1-t1==%lld\n",n1-t1);
                count=0;
            }
            else
            {
               // printf("2sum==%lld\n",(n1+1)*(n-i-1));
                sum=sum+(n1+1)*(n-i-1);
                n1=-1;
                push(a[i]);
            }

        }
        printf("%lld\n",sum);
    }
    else
        break;
    }
    return 0;
}
