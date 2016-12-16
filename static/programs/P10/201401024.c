//=========================================================================================================================================
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//=========================================================================================================================================
#define ll long long
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define slf(n) scanf("%lf",&n)
#define pi(n) printf("%d",n)
#define pis(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define pn printf("\n")
#define psn(n) printf("%s\n",n)
#define rep(i,n) for(i=0;i<n;i++)
//=========================================================================================================================================
/*int cmpfunc (const void * a, const void * b)
  {
  return ( *(int*)a - *(int*)b );
  }*/

typedef struct inp
{
    char s[101];
}boob;

//qsort(..arrayname.., ..sizeofarray.., sizeof(..typeofarray..), cmpfunc);

//=========================================================================================================================================

int main()
{
    int i,N,rem=0,start=0;
    si(N);
    int end=N-1;
    boob a[10004];
//    int val=0;
    int count=0;
    int inter=0;
    while(1)
    {
        char x;
        sc(x);
        if(x=='A')
        {
            if(count==0)
            {
                start=0;
                end=N-1;
            }
            int n;
            si(n);
            if(count+n>N)
                count=N;
            else
                count +=n;
            int flag=0;
            rep(i,n)
            {
                end=(end+1)%N;
                ss(a[end].s);
            }
            if(count==N)
                start=(end+1)%N;
            if(count)
                inter=0;
            else
                inter=1;
        }
        else if(x=='R')
        {
            int n;
            si(n);
            count-=n;
            if(count)
                inter=0;
            else
                inter=1;
            start=(start+n)%N;
        }
        else if(x=='L')
        {
//            printf("before print : start is %d   end is %d  \n",start,end);
            if(inter==0)
            {
                for(i=start;;i=(i+1)%N)
                {
                    psn(a[i].s);
                    if(i==end)
                        break;
                }
            }
  //          printf("after print : start is %d    end is  %d  \n",start,end);
    //        printf("COUNT IS %d\n",count);
        }
        else if(x=='Q')
            break;
    }
    return 0;
}
