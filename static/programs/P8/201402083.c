
/*
_____________________________________________
PROBLEM STATEMENT: 

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
void storepow(int arr[],int d,int N);
int power(int i,int d,int N);
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int upper,d,ans=0;
        int N,m,i;
        scanf("%lld %lld %d %d",&upper,&d,&m,&N);
        int A,B,C;
        long long int a,b,c;
        int arr[41];
        storepow(arr,d,N);
//        for(i=0;i<N;i++)
 //           printf("%d ",arr[i]);
   //     printf("\n");
        for(A=0;A<N;A++)
            for(B=0;B<N;B++)
                for(C=0;C<N;C++)
                {
                    if((arr[A]+arr[B]+arr[C])%N==m%N)
                    {
                        if(A<=upper%N)
                            a=upper/N +1;
                        else
                            a=upper/N;
                        if(B<=upper%N)
                            b=upper/N +1 ;
                        else
                            b=upper/N;
                        if(C<=upper%N)
                            c=upper/N +1;
                        else
                            c=upper/N;
                        ans=(ans+(((a*b)%1000000007)*c)%1000000007)%1000000007;
     //                   printf("$$%lld-ans %lld-a %lld-b %lld-c$$",ans,a,b,c);
                    }
                }
        printf("%lld\n",ans);
    }
    return 0;
}

void storepow(int arr[],int d,int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        arr[i]=power(i,d,N);
    }
}

int power(int i,int d,int N)
{
    int ans=1;
    while(d!=0)
    {
        if(d%2!=0)
            ans=(ans*i)%N;
        i=i*i%N;
        d=d/2;
    }
    return ans;
}

