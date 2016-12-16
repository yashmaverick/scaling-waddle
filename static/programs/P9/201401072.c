#include<stdio.h>
int main()
{
    int n,mod,m,i,j,tmp1,tmp2,tmp3;
    scanf("%d %d",&n,&mod);
    int *a[n],*b[n];
    for(i=0;i<n;i++)
    {
     a[i]=(int *)malloc(sizeof(int)*3);
     scanf("%d",&m);
     a[i][1]=m;
     a[i][2]=i;
     a[i][0]=0;
     b[i]=(int *)malloc(sizeof(int)*m);
     for(j=0;j<m;j++)
     {
        scanf("%d",&b[i][j]);
        a[i][0]=(a[i][0]+b[i][j])%mod;
     }

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j][0]>a[j+1][0])
            {
                int *tmp;
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            /*    tmp1=a[j][0];
                tmp2=a[j][1];
                tmp3=a[j][2];
                a[j][0]=a[j+1][0];
                a[j][1]=a[j+1][1];
                a[j][2]=a[j+1][2];
                a[j+1][0]=tmp1;
                a[j+1][1]=tmp2;
                a[j+1][2]=tmp3;*/
            }

        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i][0]);
        for(j=0;j<a[i][1];j++)
        {
            printf("%d\n",b[a[i][2]][j]);
        }
        printf("\n");
    }

    return 0;
}
