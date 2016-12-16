#include<stdio.h>
long long int a[1000000];
void merge(long long int a[],int l,int  mid,int r)
{
        long long int c[1000000],i,j=l,k=mid+1;

        for(i=0;j<=mid&&k<=r;i++)
        {
                if(a[j]<a[k])
                {
                        c[i]=a[j];
                        j++;
                }
                else
                {
                        c[i]=a[k];
                        k++;
                }
        }
        if(j>mid)
                for(;k<=r;i++)
                        c[i]=a[k++];
        if(k>r)
                for(;j<=mid;i++)
                        c[i]=a[j++];

        for(i=l,j=0;i<=r;i++)
        {

                a[i]=c[j++];
        }

}
void mergesort(long long int a[],int l,int r)
{
        if(l<r)
        {

                int mid=l+(r-l)/2;
                mergesort(a,l,mid);
                mergesort(a,mid+1,r);
                merge(a,l,mid,r);
        }
}
int main()
{
        int t,n,j,i;
        long long int c,ans;
        //long long int b[1000001];
        //long long int sum;


        scanf("%d",&t);
        for(i=0;i<t;i++)
        {

                ans=0;
                scanf("%d",&n);
                for(j=0;j<n;j++)
                        scanf("%lld",&a[j]);
                //max=a[0];
                //min=a[0];
                /*for(j=0;j<n;j++)
                  {
                  if(max<a[j])                 
                  max=a[j];
                  if(min>a[j])
                  min=a[j];
                  }
                  for(j=0;j<=max-min;j++)
                  b[j]=0;
                  for(j=0;j<n;j++)
                  {
                  a[j]=max-a[j];
                  b[a[j]]++;
                  }
                  for(j=0;j<=(max-min);j++)
                  {                        
                  sum+=((b[j]*(b[j]-1))/2);
                  }*/
                mergesort(a,0,n-1);
                for(j=0;j<n;)
                {
                        c=1;
                        while(a[j+1]==a[j]&&j<n-1)
                        {
                                c++;

                                j++;
                        }

                        ans+=(c*(c-1))/2;

                        j++;
                }
                printf("%lld\n",ans);
        }
        return 0;
}
