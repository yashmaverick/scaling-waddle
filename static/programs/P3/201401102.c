#include<stdio.h>
int main()
{
        int t,n,a[100000],i,max_diff,j,min;
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                
                scanf("%d",&n);
                for(j=0;j<n;j++)
                        scanf("%d",&a[j]);
                max_diff=a[1]-a[0];
                min=a[0];
                for(j=1;j<n-1;j++)
                {
                        if(min>a[j])
                                min=a[j];
                        if(max_diff<a[j+1]-min)
                                max_diff=a[j+1]-min;
                }
                if(max_diff<=0)
                        printf("0\n");
                else
                        printf("%d\n",max_diff);
                
                
        }
        return 0;
}
                                
                                

                
