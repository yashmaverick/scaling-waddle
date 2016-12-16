#include<stdio.h>
long long int a[1001000],b[1001000],c[1001000],n1,n,rana,maxa,left,right,count;
void push(long long int var,long long int var2 )
{
    n1++;
    b[n1]=var;
    c[n1]=var2;
    count++;
}
void pop(long long int var,long long int var2)
{
    long long int temp,temp1;
    temp=b[n1];
    if(n1==0)
        left=-1;
    else
        left=c[n1-1];
    right=var2;    
    rana=(right-left-1)*temp;
    if(rana>=maxa)
        maxa=rana;
    n1--;
    if(n1<0)
    {
        push(var,var2);
    }
    else if(var>=b[n1])
    {
        push(var,var2);
    }
    else
        pop(var,var2);
}
int main()
{
    long long int i;
    while(1)
    {
        count=0;
        scanf("%lld",&n);
        if(n!=0)
        {
            for(i=0;i<n;i++)
                scanf("%lld",&a[i]);
            b[0]=a[0];c[0]=0;n1=0;i=1;maxa=0;
            while(i<n)
            {
         //       if(i==n-1)
            //       printf("a[i]==%lld  b[i]===%lld\n",a[i],b[n1]);
                if(a[i]>=b[n1])
                    push(a[i],i);
                else
                    pop(a[i],i);
                i++;
            }
           // printf("i==%lld\n",i);
       /*     for(i=0;i<=n1;i++)
                printf("%lld ",b[i]);
                printf("\n");*/
           for(i=0;i<=n1;i++)
           {
               rana=b[i]*(n1+1-i);
               if(rana>=maxa)
                   maxa=rana;
           }
           long long int random=b[n1];
           long long int indexdd=n1;
           for(i=n1;i>=0;i--)
           {
               if(b[i]!=random)
               {
                   rana=random*(c[n1]-c[i]);
                   if(rana>=maxa)
                       maxa=rana;
                    random=b[i];
                    indexdd=i;

               }

           }
           
           rana=b[0]*n;
           if(rana>=maxa)
               maxa=rana;
           
            printf("%lld\n",maxa);
        }
        else
            break;
    }
    return 0;
}
