#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

ll a[1000001];

ll k,n;

int main()
{
    ll i,t,j,min=-1,minpos,next; //pi-> Previous value of 'i'

    scanf("%lld",&t);

    while(t-->0)
    {
        scanf("%lld %lld",&n,&k);

        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);

        j=-1;
        minpos=-1;
        
        for(i=0;(i+k)<=n;i++)
        {
            //min=a[i];
            if((i<=minpos && minpos<=j) && (min<=a[next]))
                min=min;
            else
            {
                min=a[i];
                for(j=i;j<=(i+k-1);j++)
                {
                    if(a[j]<min)
                    {
                        min=a[j];
                        minpos=j;
                    }
                }
            }

            printf("%lld",min);

            if((i+k)!=n)
                printf(" ");
            next=i+k;
        }
        printf("\n");
    }

    return 0;
}
