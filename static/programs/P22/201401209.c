#include<stdio.h>
#define mod 1000000007
typedef long long int ll;
void swap(ll * a,ll* b)
{
    ll temp=*a;
    *a=*b;
    *b=temp;
}
ll f[500000]={0};
ll min[500000]={0},mini=1,maxi=1;
ll max[500000]={0},a,b,c,n;
void shuffleupmin(ll x)
{
    while(x!=1 && min[x/2]>min[x])
    {
        swap(&min[x],&min[x/2]);
        x/=2;
    }
}
void insertmin(ll x)
{
    min[mini++]=x;
    shuffleupmin(mini-1);
}
void shuffledownmin(ll x)
{
    ll ul=mini-1;
    while(1)
    {
        if(2*x>ul && 2*x+1>ul) return;
        else if(2*x<=ul && 2*x+1>ul)
        {
            if(min[2*x]<min[x]) {swap(&min[2*x],&min[x]); x*=2; } else break;;
        }
        else if(2*x<=ul && 2*x+1<=ul)
        {
            if(min[2*x]<=min[2*x+1]) 
            {
                if(min[x]>min[2*x]) { swap(&min[x],&min[2*x]); x*=2;} else break;
            }
            else if(min[2*x+1]<=min[2*x])
            {
                if(min[x]>min[2*x+1]) { swap(&min[x],&min[2*x+1]);x=2*x+1; } else break;
            }
        }
    }
}
void deletemin()
{
    swap(&min[mini-1],&min[1]);
    mini--;
    shuffledownmin(1);
}
void shuffleupmax(ll x)
{
    while(x!=1 && max[x/2]<max[x])
    {
        swap(&max[x/2],&max[x]);
        x/=2;
    }
}
void insertmax(ll x)
{
    
    max[maxi++]=x;
    shuffleupmax(maxi-1);
}
void shuffledown(ll x)
{
    ll ul=maxi-1;
    while(1)
    {
        if(2*x>ul && 2*x+1>ul) return;
        else if(2*x<=ul && 2*x+1>ul)
        {
            if(max[2*x]>max[x]) { swap(&max[x],&max[2*x]);  x=2*x; } else break;
        }
        else if(2*x<=ul && 2*x+1<=ul)
        {
            if(max[2*x]>=max[2*x+1])
            {
                if(max[2*x]>max[x]) { swap(&max[x],&max[2*x]); x=2*x;  } else break;
            }
            else if(max[2*x]<=max[2*x+1])
            {
                if(max[2*x+1]>max[x]) { swap(&max[x],&max[2*x+1]); x=2*x+1; } else break;
            }
        }
    }
}
void deletemax()
{
    swap(&max[1],&max[maxi-1]);
    maxi--;
    shuffledown(1);
}
ll median()
{
    if(mini==maxi) return max[1];
    else if(maxi>mini) return max[1];
    else return min[1];
}
int main()
{
    ll cases;
    scanf("%lld",&cases);
    while(cases--)
    {
        mini=1; maxi=1;
        min[0]=-1;
        max[0]=2000000000;
        ll ans=1,i;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
        insertmax(1);
        if(n==1){  printf("1\n"); continue;}
        for(i=2;i<=n;i++)
        {
            f[i]=(a*median()+b*i+c)%mod;
      //      printf("f-> %lld = %lld \n",i,f[i]);
            ans+=f[i];
            if(f[i]<=max[1]) insertmax(f[i]);
            else insertmin(f[i]);
            while(maxi-mini>=2) { insertmin(max[1]); deletemax();}
            while(mini-maxi>=2) { insertmax(min[1]); deletemin();  }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
