#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
ll min[100000],mini=1;
typedef struct node
{
    ll val;
    struct node* next;
}node;
void swap(ll* a,ll* b) 
{
    ll temp=*a;
    *a=*b;
    *b=temp;
}
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
node* insert(node* head,ll x)
{
    node* temp=malloc(sizeof(node));
    temp->val=x;
    temp->next=head;
    head=temp;
    return head;
}
int main()
{
    min[0]=-1;
    ll n,m;
    scanf("%lld %lld",&n,&m);
    ll count=0;
    ll a[n+1],i;
    for(i=0;i<n+1;i++) a[i]=0;
    node* list[n+1];
    for(i=0;i<n+1;i++) list[i]=NULL;
    for(i=0;i<m;i++)
    {
        ll temp1,temp2;
        scanf("%lld %lld",&temp1,&temp2);
        list[temp1]=insert(list[temp1],temp2);
        a[temp2]++;
    }
    for(i=1;i<=n;i++) if(a[i]==0)  insertmin(i);
    while(mini!=1)
    {
        node* head=list[min[1]];
        count++;
        if(count==n) { printf("%lld\n",min[1]); return;  }
        printf("%lld ",min[1]);
        deletemin();
        while(head!=NULL)
        {
            a[head->val]--;
            if(a[head->val]==0) insertmin(head->val);
            head=head->next;
        }
    }
    return 0;
}
