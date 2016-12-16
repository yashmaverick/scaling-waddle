#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000005
#define mod 1000000007
#define INF 100000000
int size1=-1;
int size2=-1;
int a[MAX];
int b[MAX];
long long int x,y,z;
int f[MAX];
int prev;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void correct1_min(int n)
{
    if((n-1)/2>=0 && a[(n-1)/2]>a[n])
    {
        swap(&a[n],&a[(n-1)/2]);
        correct1_min((n-1)/2);
    }
}
void correct2_min(int n)
{
    if(size1<2*n+1)return;
    int x=2*n+1;
    if(a[x]>a[2*n+2])
        x=2*n+2;
    if(a[x]<a[n])
    {
        swap(&a[n],&a[x]);
        correct2_min(x);
    }
}
void insert_min(int x)
{
    size1++;
    a[size1]=x;
    correct1_min(size1);
}
int getmin()
{
    int x=a[0];
    return x;
}
int getmin2()
{
    int x=a[0];
    a[0]=a[size1];
    size1--;
    correct2_min(0);
    return x;
}
void correct1_max(int n)
{
    if((n-1)/2>=0 && b[(n-1)/2]<b[n])
    {
        swap(&b[n],&b[(n-1)/2]);
        correct1_max((n-1)/2);
    }
}
void correct2_max(int n)
{
    if(size2<2*n+1)return;
    int x=2*n+1;
    if(b[x]<b[2*n+2])
        x=2*n+2;
    if(b[x]>b[n])
    {
        swap(&b[n],&b[x]);
        correct2_max(x);
    }
}
void insert_max(int x)
{
    size2++;
    b[size2]=x;
    correct1_max(size2);
}
int getmax()
{
    int x=b[0];
    return x;
}
int getmax2()
{
    int x=b[0];
    b[0]=b[size2];
    size2--;
    correct2_max(0);
    return x;
}
int get_median()
{
    if(size1==-1 && size2==-1)return 1;
    if(size1==size2)return getmax();
    if(size1-size2==1)return getmin();
    if(size2-size1==1)return getmax();
    if(size1-size2==2){
        int x=getmin2();
        insert_max(x);
        return getmax();
    }
    if(size2-size1==2){
        int x=getmax2();
        insert_min(x);
        return getmax();
    }
}
void insert_med(int x)
{
    if(size1==-1 && size2==-1)
        insert_max(x);
    else 
    {   
        if(x <= prev)
            insert_max(x);
        else
            insert_min(x);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        size1=-1;
        size2=-1;
        long long ans=1;
        long long int i,n;
        scanf("%lld%lld%lld%lld",&x,&y,&z,&n);
        f[1]=1;
        prev=1;
        insert_med(1);
        for(i=2;i<=n;i++)
        {
            prev=get_median();
            f[i]=(x*prev + y*i + z)%mod;
            ans += f[i]%mod;
            insert_med(f[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
