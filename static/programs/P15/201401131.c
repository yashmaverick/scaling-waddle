#include<stdio.h>
int main()
{
         int n,k,t,m,l,i,j,p;
        scanf("%d",&t);
        for(p=0;p<t;p++)
        {
                scanf("%d%d",&n,&k);
                int a[n],min,min1,mn[n-k+1],r;
                        for(j=0;j<n;j++)
                                scanf("%d",&a[j]);
                        min=a[0];
                        min1=a[1];
                        for(i=0;i<k;i++)
                                if(a[i] < min)
                                        min =a[i];
                                mn[0]=min;
                        for(l=1;l<=n-k;l++)
                        {
                                min1=a[l];
                                if(a[l-1]==mn[l-1])
                                {
                                        for(m=l;m<k+l;m++)
                                        {
                                                if(min1 > a[m])
                                                        min1 =a[m];
                                        }
                                        mn[l]=min1;
                                }
                                else
                                {
                                        if(a[k+l-1] < mn[l-1])
                                              mn[l]=a[k+l-1];
                                        else
                                               mn[l]=mn[l-1];
                                }
                        }
                        for(r=0;r<n-k;r++)
                        {
                                printf("%d ",mn[r]);
                        }
                        printf("%d",mn[r]);
                        printf("\n");
        }
        return 0;
}
