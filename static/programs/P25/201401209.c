#include<stdio.h>
#include<stdlib.h>
typedef long long  int ll;
typedef struct a
{
    ll node1;
    ll node2;
    ll weight;
}a;
int cmpfunc(const void* b,const void* c)
{
    a* temp=(a*)b;
    a* temp1=(a*)c;
    return (temp->weight-temp1->weight);
}
ll parent(ll x,ll* pa)
{
    if(pa[x]==x) return x;
    else 
    {
        pa[x]=parent(pa[x],pa);
        return pa[x];
    }
}
a e[1000000];
int main()
{
    ll n,ed,i,ans=0,count=0;
    scanf("%lld %lld",&n,&ed);
    for(i=0;i<ed;i++)
    {
        scanf("%lld %lld %lld",&e[i].node1,&e[i].node2,&e[i].weight);
    }
    qsort(e,ed,sizeof(a),cmpfunc);
    ll p[n+1];
    for(i=0;i<n+1;i++) p[i]=i;
    for(i=0;i<ed;i++)
    {
        ll temp1=parent(e[i].node1,p);
        ll temp2=parent(e[i].node2,p);
        if(temp1==temp2) continue;
        else 
        {
            count++;
            ans+=e[i].weight;
            p[temp1]=temp2;
        }
    }
    if(count+1!=n) {  printf("-1\n"); return 0; }
    printf("%lld\n",ans);
    return 0;
}
