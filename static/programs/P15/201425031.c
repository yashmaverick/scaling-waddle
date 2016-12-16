#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    int T,n,k,p,q,r,i,j,a[10001],min,f,m,q2;
    scanf("%d",&T);
    while(T--)
    {
        a[0]=-1;
        f=0;
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<a[i-1])
                f=1;
        }
        p=n-k+1;
        if(f==0)
        {
            for(i=1;i<=p;i++)
            {
                printf("%d",a[i]);
                if(i==p)
                    break;
                else
                    printf(" ");
            }
        }
        else
        {
            min=1000000000;
            q=1+k-1;
            if(q==0 || q==1)
            {
                printf("%d",a[1]);
                min=a[1];
                j=1;
            }
            else{
            for(m=1;m<=q;m++)
            {
                if(a[m]<=min)
                {
                    min=a[m];
                    j=m;
                }
            }
            printf("%d",min);}
            if(p>1)
                printf(" ");
            
            for(i=2;i<=p;i++)
            {
             //   min=1000000000;
                q=i-1+k-1;
                q2=i+k-1;
                if(q2==0 || q2==1)
                {
                    printf("%d",a[i]);
                    min=a[i];
                    j=i;
                }
                else
                {
                    if(j==i-1)
                    {
                        min=1000000000;
                        q2=i+k-1;
                        for(m=i;m<=q2;m++)
                        {
                            if(a[m]<=min)
                            {
                                min=a[m];
                                j=m;
                            }
                        }
                    }
                    else
                    {
                        for(m=q+1;m<=q2;m++)
                        {
                            if(a[m]<=min)
                            {
                                min=a[m];
                                j=m;
                            }
                        }
                    }
                    printf("%d",min);
                }
                if(i==p)
                    break;
                else
                    printf(" ");
            }
        }   


        printf("\n");
    }
    return 0;
}
