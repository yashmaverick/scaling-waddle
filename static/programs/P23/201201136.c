#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
#define MAXN 100000
int indeg[MAXN+10];
VI deg[MAXN+10];
int main()
{
    int n,m,u,v;
    priority_queue <int, vector<int>, greater<int> > myq;
    sd(n),sd(m);
    for(int i=0; i<m; i++){
        sd(u),sd(v);
        indeg[v]++;
        deg[u].pb(v);
    }
    for(int i=1; i<=n; i++)
        if(indeg[i]==0)myq.push(i);
    int cnt=0;
    while(not myq.empty()){
        int p=myq.top();
        myq.pop();
        printf("%d",p);
        if(cnt<n-1)
            printf(" ");
        cnt++;
        for(VI::iterator it=deg[p].begin(); it!=deg[p].end(); it++){
            indeg[*it]--;
            if(indeg[*it]==0)
                myq.push(*it);
        }
    }
    printf("\n");
    return 0;
}
