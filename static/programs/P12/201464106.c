#include<stdio.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    while(n!=0)
    {
        int a[n];
        int c=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            //   printf("in i\n");
            for(j=i+1;j<n;j++)
            {
           //     printf("in j\n");
                for(k=i+1;k<j;k++)
                {
//                    printf("%d\n",c);
                    //printf("i=%d\tj=%d\tk=%d\n",i,j,k);
                    if(a[k]>a[i] || a[k]>a[j])
                    {
                        c++;
                        break;
                    }
                }
            }
        }
        printf("%d\n",c);
        scanf("%d",&n);
    }
    return 0;
}

