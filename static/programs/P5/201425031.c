#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
        long long int T,n,temp,m,mid,l,u,arr[100001],i,j,K;
        char s[100000];
        scanf("%lld",&T);
        while(T--)
        {
                int c=0;
                scanf("%lld %lld",&n,&K);
                for(i=0;i<n;i++)
                        scanf(" %s %lld",s,&arr[i]);
                for(i=0;i<n-1;i++)
                {
                        for(j=0;j<n-1;j++)
                        {
                                if(arr[j]>arr[j+1])
                                {
                                        temp=arr[j];
                                        arr[j]=arr[j+1];
                                        arr[j+1]=temp;
                                }
                        }
                }
                for(i=0;i<n-2;i++)
                {
                        if(arr[i]<K)
                        {
                                for(j=i+1;j<n-1;j++)
                                {
                                        m=K-arr[j]-arr[i];
                                        if(m>=0)
                                        {
                                                l=j+1,u=n-1;
                                                while(l<=u)
                                                {
                                                        mid=(l+u)/2;
                                                        if(m==arr[mid])
                                                        {
                                                                c=1;
                                                                break;
                                                        }
                                                        else if(m<arr[mid])
                                                                u=mid-1;
                                                        else
                                                                l=mid+1;
                                                }
                                        }
                                        if(c==1)
                                                break;
                                }
                        }
                        if(c==1)
                                break;
                }
                if(c==1)
                        printf("YES\n");
                else
                        printf("NO\n");
        }
        return 0;
}



