#include<stdio.h>
int merge(int a[],int l,int mid, int r)
{
        int c[1000],i,j=l,k=mid+1;

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
void mergesort(int a[],int l,int r)
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
        int t,i,j,k,n,K,start,end,flag;
        int a[1000];
        char s[100];
        scanf("%d",&t);

        for(i=0;i<t;i++)
        {flag=0;

                scanf("%d%d",&n,&K);
                for(j=0;j<n;j++)
                {
                        for(k=0;;k++)
                        {
                                scanf("%c",&s[k]);
                                if(s[k]==' ')
                                        break;
                        }
                        scanf("%d",&a[j]);
                }
                mergesort(a,0,n-1);


                for(j=0;j<n-1;j++)
                {
                        start=j+1;
                        end=n-1;

                        while(start<end)
                        {
                                if(a[start]+a[end]+a[j]==K)
                                {
                                        printf("YES\n");
                                       
                                        flag=1;
                                        break;
                                }
                                else if(a[start]+a[end]+a[j]<K)
                                        start++;
                                else
                                        end--;
                        }
                        if(flag==1)
                                break;
                }
                if(flag!=1)
                printf("NO\n");

        }
        return 0;
}




