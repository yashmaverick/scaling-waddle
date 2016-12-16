#include<stdio.h>
int cmpfunc(const void *a,const void *b)
{
        return (*(long long int *)a-*(long long int *)b);
}
long long int a[1000000];
int main()
{
        int n;
        scanf("%d",&n);
        while(n--)
        {
                int m;
                scanf("%d",&m);
                long long int i,sum=0,count=1;
                for(i=0;i<m;i++)
                        scanf("%lld",&a[i]);
                //printf("a\n");
                qsort(a,m,sizeof(long long int),cmpfunc);
                //printf("a\n");
                for(i=0;i<m-1;i++)
                {
                     //   printf("%d ",a[i]);
                        if(a[i]==a[i+1])
                                count++;
                        else if(count!=1)
                        {
                   //             printf("%lld\n",count/2);
                                if(count%2==0)
                                        sum=sum+((count)/2)*(count-1);
                                else
                                        sum=sum+count*((count-1)/2);
                                count=1;
                        }
                }
                sum=sum+(count*(count-1))/2;
                printf("%lld\n",sum);
        }
        return 0;
}
