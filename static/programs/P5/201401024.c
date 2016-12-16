#include<stdio.h>

void merge(int a[],int l,int mid, int r)
{
    int b=mid-l+1,v=r-mid,i=0,j=0,k=l,temp[1002];
    while(b>0 && v>0)
    {
        if(a[l+i] >= a[mid+1+j])
        {
            temp[k]=a[mid+1+j];
            j++;
            v--;
        }
        else
        {
            temp[k]=a[l+i];
            i++;
            b--;
        }
        k++;
    }

    if(b<=0)
    {
        while(v>0)
        {
            temp[k]=a[mid+1+j];
            j++;
            k++;
            v--;
        }
    }
    else
    {
        while(b>0)
        {
            temp[k]=a[l+i];
            i++;
            k++;
            b--;
        }
    }

    for(i=l;i<=r;i++)
        a[i]=temp[i];
}

void mergesort(int a[],int l,int r)
{
    int mid=l+(r-l)/2;

    if(r==l)
        return;

    mergesort(a,l,mid);
    mergesort(a,mid+1,r);

    merge(a,l,mid,r);
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        char s[10000];
        long long flag=0;
        int i,j,l,n,k;
        int a[1002];
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%s%d",s,&a[i]);
        mergesort(a,0,n-1);
        for(i=0;i<n-2;i++)
        {
            j=i+1;
            l=n-1;
            while(j<l)
            {
                if((a[i]+a[j]+a[l])==k)
                {
                    flag=1;
                    break;
                }
                else if(a[i]+a[j]+a[l]>k)
                    l--;
                else
                    j++;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
        t--;
    }
    return 0;
}
