#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int t,i;

    int pow[33];
    pow[0]=1;
    for(i=1;i<33;i++)
        pow[i]=pow[i-1] << 1;

    scanf("%d",&t);
    while(t--)
    {
        int q;
        scanf("%d",&q);
        if (q==1)
            printf("0\n");
        else
        {
            i=0;
            while(i<33)
            {
                if (pow[i]>=q)
                    break;
                i++;
            }

            if (pow[i]==q)
                printf("%d\n",2*i-1);
            else
            {
                i--;
                if ((pow[i]+pow[i-1])>q)
                    printf("%d\n",2*i-1);
                else
                    printf("%d\n",2*i);
            }

        }
    }
    return 0;
}
