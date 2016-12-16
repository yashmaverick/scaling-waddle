#include<stdio.h>
int main()
{
        long long int n,q,distance,level,power,m,x,temp;
        long long int i,j,k;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
                scanf("%lld",&q);
                distance=0;
                level=0;
                m=0;x=0;
                temp=q;
                for(j=0;;j++)
                {
                        if(temp>1)
                                temp=temp/2;
                        else 
                                break;
                }
                //printf("%d",j);
                level=j;
                power=1;
                for(j=0;j<level;j++)
                {
                        power=power*2;
                }
//                        printf("power=%d\n",power);
                x = (power-1);
                m=q-x;
//              printf("%d\n %d ",x,m);
                if(m<=(power)/2)
                        distance = 2*level -1;
                else 
                        distance = 2*level;
                printf("%lld\n",distance);
        }
        return 0;
}

