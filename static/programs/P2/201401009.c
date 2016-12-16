#include<stdio.h>
#include<stdlib.h>
int main()
{
        long long int n;
        scanf("%lld",&n);
        while(n--)
        {
                long long int m,l,p,i,sum=0,j,k;
                long long int *a,*b,*c,*d;
                scanf("%lld",&m);
                a=(long long int *)malloc(m*sizeof(long long int));
                for(i=0;i<m;i++)
                        scanf("%lld",&a[i]);
                scanf("%lld",&l);
                b=(long long int *)malloc(l*sizeof(long long int));
                for(i=0;i<l;i++)
                        scanf("%lld",&b[i]);
                scanf("%lld",&p);
                c=(long long int *)malloc(p*sizeof(long long int));
                for(i=0;i<p;i++)
                        scanf("%lld",&c[i]);
                k=l+1;
                d=(long long int *)malloc(k*sizeof(long long int));
                long long int x=0,y=0;
                d[l]=0;
                /*while(x>=0)
                {
                        if(b[x]<=c[y] && y>=0 && x<=y)
                                y--;
                        else
                        {
                                d[x]=p-y-1+d[x+1];
                                //printf("%d %d %d\n",x,d[x],d[x+1]);
                                x--;
                                y=p-1;
                        }
                }*/
                while(x<l)
                {
                        if(b[x]>c[y] && y<p)
                                y++;
                        else
                        {
                                d[x]=p-y;
                                x++;
                                y=x;
                        }
                }
                x=l-1;
                while(x>=0)
                {
                        d[x]=d[x]+d[x+1];
                        x--;
                }

                x=0;
                y=0;
                while(x<m)
                {
                        if(a[x]>b[y] && y<l)
                                y++;
                        else
                        {
                               sum=sum+d[y];
                                x++;
                                y=x;
                        }
                }
                /*for(i=0;i<m;i++)
                        printf("%d ",e[i]);
                printf("\n");
                for(i=0;i<l;i++)
                        printf("%d ",d[i]);
                printf("\n");*/
               /* x=0;
                while(x<m)
                {
                        if(e[x]<=x)
                                sum=sum+d[x];
                        x++;
                }*/
                printf("%lld\n",sum);
        }
        return 0;
}
