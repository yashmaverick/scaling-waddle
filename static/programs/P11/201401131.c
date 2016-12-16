#include<stdio.h>
long long int push(long long int x,long long int top,long long int s[])
{
        top=top+1;
        s[top]=x;
        return top;
}
long long int pop(long long int top)
{
        if(top==-1)
                return -1;
        top=top-1;
        return top;
}
int main()
{
        long long int n,i,j,k,area;

        while(1)
        {

                scanf("%lld",&n);
                if(n==0)
                        break;
                long long int a[n];
                for(i=0;i<n;i++)
                        scanf("%lld",&a[i]);
                long long int lm[n],rm[n];
                long long int s[10000],max=0;
                long long int top1=-1;
                long long int top2=-1;
                lm[0]=-1;
                for(i=0;i<n;i++)
                {
                        while(top1!=-1 && a[s[top1]]>=a[i])
                        {
                                top1=pop(top1);
                        }
                        if(top1==-1)
                                lm[i]=-1;
                        else
                                lm[i]=s[top1];
                        top1=push(i,top1,s);
                }
                rm[n-1]=n;
                for(i=n-1;i>=0;i--)
                {
                        while(top2!=-1 && a[s[top2]]>=a[i])
                                top2=pop(top2);
                        if(top2==-1)
                                rm[i]=n;
                        else
                                rm[i]=s[top2];
                        top2=push(i,top2,s);
                }
                for(i=0;i<n;i++)
                {
                        area=(rm[i]-lm[i]-1)*a[i];
                        if(max < area)
                                max=area;
                }
                printf("%lld\n",max);
        }
        return 0;      
}
