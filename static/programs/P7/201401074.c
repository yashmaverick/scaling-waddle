#include<stdio.h>

int a[1000001],b[1000000];

void merge(int p,int m,int q,int n)
{
    int i,j,k;
    if(n-p==0)
        return;
    i=p;j=q;
    for(k=0;k<=n-p&&j<=n&&i<=m;k++)
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            i++;
        }
    }
    if(i>m)                 
        while(j<=n)         
            b[k++]=a[j++];  
    else                     
        while(i<=m)         
            b[k++]=a[i++];  
    i=p;                    
    for(k=0;k<=n-p;k++)     
    {                        
        a[i++]=b[k];           
    }                       
    return;                 
}

void mergesort(int l,int r)
{
    int mid;
    if(l<r)
    {
        mid=l+(r-l)/2;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,mid+1,r);
    }
    return;
}

unsigned long long int pairs(unsigned long long int num)
{
    if(num<2) return 0;
    if(num&1)
        return ((num-1)/2)*num;
    else
        return (num/2)*(num-1);
}

int main()
{
    int n,i;
    unsigned long long int count,ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        mergesort(0,n-1);
        //  for(i=0;i<n;i++)
        //  {
        //      printf("%d ",a[i]);
        //  }
        //  printf("\n");
        a[n]=a[n-2];
        count=1;
        for(i=0;i<n;i++)
        {
            //      printf("count=%d\n",count);
            if(a[i]!=a[i+1] || i==n-1)
            {
                ans+=pairs(count);
                count=1;
            }
            else
                count++;
        }
        printf("%llu\n",ans);
    }
    return 0;
}


