#include<stdio.h>

int a[100000],b[100000];

void mergesort(int l,int r)
{
    int mid,i,j,k;
    if(l<r)
    {
        mid=l+(r-l)/2;
        mergesort(l,mid);
        mergesort(mid+1,r);

        for(i=l,j=mid+1,k=0;i<=mid&&j<=r&&k<=r-l;k++)
        {
            if(a[i]>=a[j])
                b[k]=a[i++];
            else
                b[k]=a[j++];
        }
        if(i>mid)
            while(j<=r)
                b[k++]=a[j++];
        else
            while(i<=mid)
                b[k++]=a[i++];
        for(i=l,k=0;k<=r-l;k++,i++)
            a[i]=b[k];
    }
}

int main()
{
    int t;
    int n,i,j,k,sum,flag;
    char junk[1000];
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d%d",&n,&sum);
        for(i=0;i<n;i++)
        {
            scanf("%s",junk);
            scanf("%d",&a[i]);
        }
        mergesort(0,n-1);
        for(i=0;i<n-2;i++)
        {
            if(flag)
                break;
            j=i+1;k=n-1;
            while(j<k)
            {
                if(a[i]+a[j]+a[k]==sum)
                {
                    printf("YES\n");
                    flag=1;
                    break; 
                }
                else if(a[i]+a[j]+a[k]<sum)
                    k--;
                else
                    j++;
            }
        }
        if(!flag)
            printf("NO\n");
    }
    return 0;
}





