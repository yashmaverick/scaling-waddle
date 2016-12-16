#include<stdio.h>

typedef struct bag
{
    int wt;
    int *a;
    int num;
}bag;

int main()
{
    int n,mod,i,j;
    scanf("%d%d",&n,&mod);
    bag B[n];
    for(i=0;i<n;i++)
    {
        int size;
        scanf("%d",&size);
        B[i].wt=0;
        B[i].num=size;
        B[i].a=(int*)malloc(sizeof(int)*size);
        for(j=0;j<size;j++)
        {
            scanf("%d",&B[i].a[j]);
            B[i].wt=(B[i].a[j]+B[i].wt)%mod;
        }
    }
    int k=n-1,c,g;
    int *temp;
    while(k--)
    {
        for(i=1;i<n;i++)
        {
            if(B[i-1].wt>B[i].wt)
            {
                c=B[i].wt;
                B[i].wt=B[i-1].wt;
                B[i-1].wt=c;
                temp=B[i].a;
                B[i].a=B[i-1].a;
                B[i-1].a=temp;
                g=B[i].num;
                B[i].num=B[i-1].num;
                B[i-1].num=g;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",B[i].wt);
        for(j=0;j<B[i].num;j++)
            printf("%d\n",B[i].a[j]);
        printf("\n");
    }
    return 0;
}
