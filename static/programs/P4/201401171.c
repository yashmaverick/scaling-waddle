#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define maxN 1000005

int cmpfunc (const void * a, const void * b)
{
    return ( *(long long int*)a - *(long long int*)b );
}

char st[maxN];
long long int arr[maxN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        scanf("%s",st);
        long long int j,i,len = strlen(st);

        void in(long long int i)
        {
            if(st[i]=='J')arr[i]+=maxN+1;
            if(st[i]=='M')arr[i]+=1;
            if(st[i]=='R')arr[i]+=-maxN-2;
        }

        for(i=0;i<len;i++)
        {
            arr[i]=arr[i-1];
            in(i);
        }

        qsort(arr,len,sizeof(long long int),cmpfunc);
        
        long long int aans=0,c=1;
        for(i=0;i<len;i++)
        {
            if(arr[i]==0)
             aans++;

            if(arr[i]==arr[i+1])
                c++;
            else
            {aans+=(c*(c-1))/2;c=1;} 

        }          
        printf("%lld\n",aans);

    }
    return (0);
}
