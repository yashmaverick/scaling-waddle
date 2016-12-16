#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007 
long long int min[200010],max[200010],nmin=0,nmax=0;
long long int f[200010];
void insertMin(long long int v)
{
        long long int i,tmp;
        min[++nmin]=v;
        for(i=nmin;min[i]<min[i/2] && i>1;i/=2)
        {
                tmp=min[i];
                min[i]=min[i/2];
                min[i/2]=tmp;
        }
}
void insertMax(long long int v)
{
        long long int i,tmp;
        max[++nmax]=v;
        for(i=nmax;max[i]>max[i/2] && i>1;i/=2)
        {
                tmp=max[i];
                max[i]=max[i/2];
                max[i/2]=tmp;
        }
}
long long int delMin()
{
        long long int x=min[1],tmp;
        min[1]=min[nmin--];
        long long int i=1,j;
        while(2*i<=nmin)
        {
                if(min[2*i]<min[2*i+1])
                        j=2*i;
                else
                        j=2*i+1;
                if(min[j]<min[i])
                {
                        tmp=min[i];
                        min[i]=min[j];
                        min[j]=tmp;
                        i=j;
                }
                else
                        break;
        }
        return x;
}
long long int delMax()
{
        long long int x=max[1],tmp;
        max[1]=max[nmax--];
        long long int i=1,j;
        while(2*i<=nmax)
        {
                if(max[2*i]<max[2*i+1])
                        j=2*i+1;
                else
                        j=2*i;
                if(max[j]>max[i])
                {
                        tmp=max[j];
                        max[j]=max[i];
                        max[i]=tmp;
                        i=j;
                }
                else
                        break;
        }
        return x;
}
long long int med(long long int i)
{
        long long int nxt=f[i-1];
        if(i==2 || nxt < max[1])
                insertMax(nxt);
        else
                insertMin(nxt);
        if(nmax > nmin+1)
        {
                long long int t=delMax();
                insertMin(t);
        }
        else if(nmin > nmax+1)
        {
                long long int t=delMin();
                insertMax(t);
        }
        if(nmax >= nmin)
                return max[1];
        else
                return min[1];
}
int main()
{
        long long int t,a,b,c,n,i;
        long long int sum;
        scanf("%lld",&t);
        while(t--)
        {
                sum=1;
                nmin=0;nmax=0;
                scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
                f[1]=1;
                for(i=2;i<=n;i++)
                {
                        long long int median=med(i);
                        f[i]=(((a*median)) + ((b*i)) + (c) ) % MOD;
  //                      printf("a:%lld med:%lld b:%lld c:%lld f[%lld]:%lld\n",a,median,b,c,i,f[i]);
                        sum+=f[i];
                }
                printf("%lld\n",sum);
        }
        return 0;
}
