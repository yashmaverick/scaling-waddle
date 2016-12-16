    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #define mod 1000000007
unsigned long long int power(unsigned long long int base,unsigned long long int exp,unsigned long long int mode)
{
    if (exp == 0)
        return 1;
else if (exp % 2 == 0) 
    {
        unsigned long long int mysqrt = power(base, exp/2,mode);
        return ( mysqrt * mysqrt ) % mode;
    }
    else
        return ( base* power( base, exp-1,mode)) % mode;
}
    int main()
    {
    unsigned long long int t,upper,d,m,N,i,j,k,l,a[10000],fans,pos[10000];
    scanf("%llu",&t);
    while(t>0)
    {
    scanf("%llu%llu%llu%llu",&upper,&d,&m,&N);
    memset(a,0,sizeof(unsigned long long int)*10000);
    fans=0;
    l=0;
    for(i=0;i<N;i++)
    {
    if(i<=upper%N)
      {
    a[power(i,d,N)%N]=a[power(i,d,N)%N]+upper/N+1;
      }
    else
      {
    a[power(i,d,N)%N]=a[power(i,d,N)%N]+upper/N;
      }
    }
    for(i=0;i<N;i++)
    {
    for(j=0;j<N;j++)
      {
    for(k=0;k<N;k++)
        {
    if((i+j+k)%N==m)
            {
            fans=(fans+((a[i]*a[j])%mod*a[k])%mod)%mod;
            }
        }
      }
    }
    printf("%llu\n",fans);
    t--;
    }
    return 0;
    }