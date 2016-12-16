#include<stdio.h>
int check(int a[],int n,int K)
{
    int j,k,l;
    int s;
    for(j=0;j<n-1;j++)
        {
            k=j+1;
            l=n-1;
            while(l>k)
            {
                s=a[j]+a[k]+a[l];
                if(s==K)
                {
                    return 1;
                }
                else if(s>K)
                    l--;
                else
                    k++;
            }
        }
    return -1;
}
void quicksort(int a[],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot]&&i<last)
                i++;
            while(a[j]>a[pivot])
                j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }

        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quicksort(a,first,j-1);
        quicksort(a,j+1,last);
    }
}
int main()
{
    int t,i,j,n,ans;
    char s[100010];
    int a[100010],K;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        ans=0;
        scanf("%d%d",&n,&K);
        for(j=0;j<n;j++)
        {
            scanf("%s%d",s,&a[j]);
        }   
        quicksort(a,0,n-1);
        ans=check(a,n,K);
        if(ans==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
