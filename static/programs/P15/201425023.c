#include<stdio.h>
int min;
int t,n,k;
int a[100000000];

int ans=0;
int i,j;
int minimum(int l)
{       min=a[j];
        for(l=j;l<=j+k-1;l++)
        {
                if(a[l]<=min)
                {
                        min=a[l];
                }
        }
        return min;
}
int main()
{
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                scanf("%d %d",&n,&k);
                for(j=0;j<n;j++)
                        scanf("%d",&a[j]);
                for(j=0;j<=n-k;j++)
                {
                        if(j==0)
                        {
                                min=minimum(j);
                                printf("%d",min);
                        }
                        else
                        {
                                if(a[j-1]==min)
                        {
                                 min=minimum(j);
                                 printf("%d",min);
                        }
                                else
                                {
                                        if(a[j+k-1]<=min)
                                        {
                                                min=a[j+k-1];
                                                printf("%d",min);
                             
                                        }
                                        else
                                        {
                                                printf("%d",min);
                                        }
                                }
                        }

                      if(j!=n-k)
                              printf(" ");
                      else
                              printf("\n");
                }
        
        }
        return 0;
}





