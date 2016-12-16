#include<stdio.h>
#include<stdlib.h>
int combination(int ,int);
int main()
{
    while(1)
    {
        long long int n;
        scanf("%lld",&n);
        if(n!=0)
        {
            long long int h[n],i=0,j=0,max=0,count=0;
            for(i=0;i<n;i++)
            {
                scanf("%lld",&h[i]);
            }
            for(i=0;i<=n-2;i++)
            {
                max=h[i+1];
                j=i+2;
                for(j=i+2;j<n;j++)
                {
                    //printf("%lld\n",count);
                    if(max>h[i] && j==i+2)
                    {
                        count=count+n-i-2;
                        break;
                    }
                    else if(max>h[i])
                    {
                        count=count+n-j;
                        break;
                    }
                    else
                    {
                        if(max>h[j])
                        {
                        count++;
                        }
                        else if(max<=h[j])
                        {
                            max=h[j];
                        }
                    }
                    //printf("%lld\n",count);
                   /* if(h[j]h[i])
                    {
                        count++;
                        break;

                    }*/

                }
                //printf("%lld\n",count);
            }
            //printf("%lld\n",n*(n-1)/2-(n-1)-count);

            printf("%lld\n",count);
        }
        else
            break;

    }
    return 0;

}
int combination(int p,int c)
{
    int temp;
    temp=p*(p-1)/2;
    return temp;
}
