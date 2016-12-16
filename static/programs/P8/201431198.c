    #include<stdio.h>
    long long int n;
    /*
    long long int po(long long int a,long long int b)
    {
    if(b==0)
    return 1;
    else if(b==1)
    return a;
    else if(a==0)
    return 0;
    else
    {
    if(b%2==0)
    return po(a*a%n,b/2);
    else
    return (a%n*po(a*a%n,(b-1)/2));
    }
     
    }
    */
    long long int modulo(int a,int b,int c){
    if(a==0 && b==0){
    return 1;
    }
    if(a==0){
    return 0;
    }
    long long int x=1,y=a;
    while(b > 0){
    if(b%2 == 1){
    x=(x*y)%c;
    }
    y = (y*y)%c;
    b /= 2;
    }
    return x%c;
    }
    int main()
    {
    long long int itemp,jtemp,ktemp;
    long long int b=1000000007;
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
    long long int u,d,sol=0;
    long long int m,j,k,i;
    scanf("%lld",&u);
    scanf("%lld",&d);
    scanf("%lld",&m);
    scanf("%lld",&n);
    itemp=0;
    for(i=0;i<=(u<n?u:n-1);i++)
    {
    jtemp=0;
    for(j=0;j<=(u<n?u:n-1);j++)
    {
    ktemp=0;
    for(k=0;k<=(u<n?u:n-1);k++)
    {
    // printf("%d\n",po(i,d)%n+po(j,d)%n+po(k,d)%n);
    if((modulo(i,d,n)%n+modulo(j,d,n)%n+modulo(k,d,n)%n)%n==m)
    {
    //printf("%d %d %d\n",i,j,k);
    //sol=(sol+1+(u-i)/n+(u-j)/n+(u-k)/n)%b;
    ktemp=(ktemp+(u-k)/n +1)%b;
    }
    //tsol=sol*((u-j)/n)%b;
    }
    jtemp=(jtemp+(ktemp*((u-j)/n +1))%b)%b;
    }
    itemp=(itemp+((jtemp)*((u-i)/n+1))%b)%b;
    //sol+=itemp;
    }
    printf("%lld\n",itemp);
    }
    return(0);
    } 