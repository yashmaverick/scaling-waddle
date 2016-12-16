#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10001
int *primes;
    
void sieve()
{
    long long int i,j;
    int z = 1;

    primes = malloc(sizeof(int)*LIMIT);

    for(i = 2;i < LIMIT;i++)
        primes[i] = 1;

    for(i = 2;i < 100;i++)
        if(primes[i])
            for(j = i;i * j < LIMIT;j++)
                primes[i * j]=0;
}

int conv_num(int a[])
{
    int temp = 0,k = 0;
    while(k < 4)
    {
        temp = temp*10 + a[k];
        k++;
    }
    return temp;
}

int main()
{
    int t;
    scanf("%d",&t);
    sieve();
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        int visited[10009],i,lev[10009];

        for(i = 0;i < 10009;i++)
            visited[i] = 0;

        int queue[1000001],start = 0,end = 0;
        visited[a] = 1;
        queue[end] = a;
        end++;
        lev[a]=0;
        int count = 0;


        while(start < end)
        {
            int num = queue[start];
            int num1=num;
            //printf("%d %d\n",num,lev[num]);
            int k,flag=0;
            for(k = 3;k >= 0;k--)
            {  
                num=num1;
                int digit[4],w = 3;
                while(num)
                {
                    digit[w--] = num % 10;
                    num /= 10;
                }

                int i;
                for(i = 0;i <= 9;i++)
                {
                    if(k==0 && i==0)
                        continue;
                    digit[k] = i;
                    int temp = conv_num(digit);
                    if(primes[temp] && visited[temp]==0)
                    {
                        lev[temp]=lev[num1]+1;
                        visited[temp]=1;
                        queue[end] = temp;
                        end++;
                        if(temp==b){
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
            start++;
        }
        printf("%d\n",lev[b]);
    }
    return 0;
}