#include<stdio.h>
#include<stdlib.h>
long long int a[100000];
long long int stack[100000];
long long int depth[100000];
long long int top=0;
int main()
{
        long long int t,i,n,j,max,deep_value;
        //int *max,*deep_value;
        //node* root=NULL;
        scanf("%lld",&t);
        //int* max=(int* )malloc(sizeof(int));
        //int* deep_value=(int* )malloc(sizeof(int));

        for(i=0;i<t;i++)
        {
                scanf("%lld",&n);
                for(j=0;j<n;j++)
                        scanf("%lld",&a[j]);
                stack[0]=n-1;
                top=0;
                depth[n-1]=0;
                for(j=n-2;j>=0;j--)
                {
                        long long int temp=top;
                        while(top>=0&&(a[j]<a[stack[top]]))
                        {
                                top--;
                        }
                        if(top==temp)
                        {
                                depth[j]=depth[stack[top]]+1;
                                stack[++top]=j;
                        }
                        else
                        {
                                depth[j]=depth[stack[++top]]+1;
                                stack[top]=j;
                        }
                }
                max=0;
                deep_value=0;
                for(j=0;j<n;j++)
                {
                        if(depth[j]>max)
                        {
                                max=depth[j];
                                deep_value=j;
                        }
                        else if(depth[j]==max&&a[j]<a[deep_value])
                        {
                                deep_value=j;
                        }
                }     
                printf("%lld %lld\n",a[deep_value],max);
        }
        return 0;
}
