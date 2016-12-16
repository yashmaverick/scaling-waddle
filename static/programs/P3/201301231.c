#include <stdio.h>

int main()
{
        int n,na,t,T,i,j;
        long long int p[100001],d,maxe,min[100001],max[100001],mine,maxp;

        scanf("%d",&T);

        for(t=1;t<=T;t++)
        {
                scanf("%d",&na);

                for(i=0;i<na;i++)
                {
                        scanf("%lld",&p[i]);
                }

                d=maxp=0;
                min[0]=mine=p[0];
                max[na-1]=maxe=p[na-1];

                for(i=1;i<na;i++)
                {
                        if(mine>p[i])
                                mine=p[i];
                        if(maxe<p[na-i-1])
                                maxe=p[na-i-1];
                        
                        max[na-i-1]=maxe;
                        min[i]=mine;
                }

                for(i=0;i<na;i++)
                {
                        d=max[i]-min[i];
                        if(maxp<d)
                                maxp=d;
                }

                printf("%lld\n",maxp);
        }

        return 0;
}
