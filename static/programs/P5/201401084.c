#include <stdio.h>

int n,k;
char s[100005];
int a[100005];

void qsort(int left,int right)
{
    int i;
    if(left<right)
    {
        int pindex=partition(left,right);
        qsort(left,pindex-1);
      /*  for(i=left;i<=right;i++)
            printf("%d ",a[i]);
        printf("\n");*/
        qsort(pindex+1,right);
       /* for(i=left;i<=right;i++)
            printf("%d ",a[i]);
        printf("\n");*/
    }
    else
        return;
}

void swap();

int partition(int left,int right)
{
    int i;
    int pindex=left;
    int pivot=a[right];
    for(i=left;i<=right-1;i++)
    {
        if(a[i]<pivot)
        {
            swap(&a[i],&a[pindex]);
            pindex++;
        }
    }
    swap(&a[pindex],&a[right]);
    return (pindex);
}

void swap(int *i,int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}

int main()
{
    int t,m,i;
    scanf("%d",&t);
    for(m=1;m<=t;m++)
    {
        int flag=0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            scanf("%d",&a[i]);
        }
        qsort(0,n-1);
        for(i=0;i<n-1;i++)
        {
            int p1=n-1;
            int p2=i+1;
            int s;
            while(p2<p1)
            {
                s=a[i]+a[p2]+a[p1];
                if(s==k)
                {
                    flag=1;
                    break;
                }
                else if(s>k)
                {
                    s=s-a[p1];
                    p1--;
                }
                else if(s<k)
                {
                    s=s-a[p2];
                    p2++;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

