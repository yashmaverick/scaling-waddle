#include<stdio.h>
long long int tmp[1000003];
void mergesort(long long int a[],long long int s,long long int e)
{
        if(s==e)
                return ;
        long long int mid=(s+e)/2;
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);
        long long int i=s,j=(mid+1),k=0;
        while(i<=mid || j<=e)
        {
                if(i>mid)
                        tmp[k++]=a[j++];
                else if(j>e)
                        tmp[k++]=a[i++];
                else
                {
                        if(a[i]<a[j])
                                tmp[k++]=a[i++];
                        else
                                tmp[k++]=a[j++];
                }
        }
        long long int p;
        for(p=0;p<k;p++)
                a[s+p]=tmp[p];
}
int main()
{
        int m,t;
        long long int a[1000003];
        scanf("%d",&t);
        for(m=0;m<t;m++)
        {
                 long long int n,i;
                scanf("%lld",&n);
                for(i=0;i<n;i++)
                {
                        scanf("%lld",&a[i]);
                }
                mergesort(a,0,n-1);
                long long int count=1,r=0;
                for(i=0;i<(n-1);i++)
                {
                        if(a[i]==a[i+1])
                                count++;
			else
			{
                                r=r+((count*(count-1))/2);
				count=1;
			}
                }
		
                                r=r+((count*(count-1))/2);
			
                printf("%lld\n",r);
        }
        return 0;
}
