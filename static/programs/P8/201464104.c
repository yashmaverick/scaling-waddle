#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int powr(long long int a, long long int p, long long int n)
{
	long long int l;
        if(p==0)
                return 1;
        else if(p==1)
                return a%n;
        else if(a==1)
                return 1;
        l=powr(a,p/2,n);
        l*=l;
	l%=n;	
	if(p%2)
                l*=a;
        l%=n;
        return l;
}
/*int comp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}*/
int main()
{
        long long int u, d, m, n,p=1000000007,count=0,*a,l,sum, i, j, k;
        int t,str[40]={0},x,r;
        scanf("%d",&t);
        while(t--)
        {
		/*int lp[1000000];
		for(i=999999;i>=0;i--)
		{
			count=0;
			lp[i]=999999-i;
		}*/
		//qsort(lp,1000000,sizeof(int),comp);
                scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
		if(m>=n)                
			sum=m%n;
		else
			sum=m;
		l=(n-1<u)?n-1:u;
		count=0;
		a=(long long int *)malloc(sizeof(long long int)*(l+1));
		for(i=0;i<40;i++)
			str[i]=0;
                for(i=0;i<=l;i++)
                        a[i] = powr(i,d,n);
		//printf("\n\n%lld\n\n",sizeof(h));
		/*for(i=0;i<40;i++)
		printf("%d",str[i]);*/
                x = (u+1)/n;
                r = (u+1)%n;
                for(i=0;i<=l;i++)
                {
                        str[i]=x;
                        if(r>0)
                        {
                                str[i]++;
                                r--;
                        }
                }
                for(i=0;i<=l;i++)
                {
                        for(j=0;j<=l;j++)
                        {
                                for(k=0;k<=l;k++)
                                {
                                        if((a[i]+a[j]+a[k])%n == sum)
                                        {
                                                count += ((((str[i]%p)*(str[j]%p))%p*(str[k]%p))%p);
                                                if(count>=p)
                                                        count %= p;
                                        }
                                }
                        }
                }
		free(a);
                printf("%lld\n",count);
        }
        return 0;
} 
