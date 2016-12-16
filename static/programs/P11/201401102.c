#include<stdio.h>
long long int a[1000000]={};
long long int stack[1000000]={};
long long int len[1000000]={};
long int top=-1;
int main()
{
        long long int n,i,min,max,area;
        while(1)
        { 
                top=0;
                                
                scanf("%lld",&n);
                if(n==0)
                        break;
                for(i=0;i<n;i++)                
                        scanf("%lld",&a[i]);
                stack[0]=0;
                for(i=1;i<n;i++)
                {
                        
                        while(a[i]<a[stack[top]]&&top>=0)
                        {
                                len[stack[top]]=i-stack[top]-1;
                                top--;
                        }
                        stack[++top]=i;
                }
                for(;top>=0;top--)
                {
                        len[stack[top]]=n-1-stack[top];
                }
/*                for(i=0;i<n;i++)
                        printf("%d ",len[i]);*/
                top=0;
                stack[0]=n-1;
                for(i=n-2;i>=0;i--)
                {
                        while(a[i]<a[stack[top]]&&top>=0)
                        {
                                len[stack[top]]+=(stack[top]-i-1);
                                top--;
                        }
                        stack[++top]=i;
                }
                for(;top>=0;top--)
                {
                        len[stack[top]]+=(stack[top]);
                }
                /*for(i=0;i<n;i++)
                        printf("%d ",len[i]);*/
                area=0;
                for(i=0;i<n;i++)
                {
                        if(area<((len[i]+1)*a[i]))
                                area=((len[i]+1)*a[i]);
                }
                printf("%lld\n",area);                
        }
        return 0;
}
