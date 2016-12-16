#include<stdio.h>
#include<math.h>
#include<stdlib.h>
const int INF=2000000000;
int less(int a,int b)
{
    return a>b?b:a;
}
void prar(int *,int);
void left(int *a,int *l,int n,int k)
    {
        int min=INF,i,ind=0;
        for(i=0;i<n;i++)
        {
            if(ind==k)
            {
             ind=0;
             min=INF;
            }
            if(a[i]<min)
                min=a[i];
            l[i]=min;
            ind++;
        }
    //    prar(l,n);
    }
    void right(int *a,int *r,int n,int k)
    {

        int min=INF,ind=k-1,j,i;
        for(i=0;i+ind<n;)
        {
            if(a[i+ind]<min)
                min=a[i+ind];
            r[i+ind]=min;
            ind--;
            if(ind==-1)
            {
             ind=k-1;
             i+=k;
             min=INF;
            }
        }
   // printf("%d\n",i);
        for(j=n-1;j>=i;j--)
        {
            if(a[j]<min)
                min=a[j];
            r[j]=min;
        }
    //    prar(r,n);
    }
void prar(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void min(int *a,int *l,int *r,int n,int k)
{
    int i;
    for(i=0;i+k-1<n-1;i++)
    {
        printf("%d ",less(r[i],l[i+k-1]));
    }
    printf("%d\n",less(r[i],l[i+k-1]));
}

int main()
{
    int t,n,i,k;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&k);

        int *a;
        int *l;
        int *r;
        a=(int *)malloc(sizeof(int)*n);
        l=(int *)malloc(sizeof(int)*n);
        r=(int *)malloc(sizeof(int)*n);
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
    //    prar(a,n);
        left(a,l,n,k);
        right(a,r,n,k);
        min(a,l,r,n,k);
    }
}
