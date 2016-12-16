#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long int

ll ans;

struct node
{
    ll is[10];
    ll end;
    struct node* next[10];
};

ll reverse(ll val)
{
    ll f=0;
    while(val!=0)
    {
        f+=val%10;
        val/=10;
        f*=10;
    }
    f/=10;
    return f;
}

void insert(struct node* head,char a[])
{ 
    
    ll flag=1,i,len,j;
    //len=strlen(a);
        //for(j=0;j<len;j++)printf("%c",a[j]);
    len=strlen(a);
    
    //for(i=0;i<len;i++)printf("%c",a[i]);
    for(i=0;i<len;i++)
    {
        if(flag)
        {
            if(head->end==1){ans=1;return;}
            //if(val==0){ans=1;return;}
            if(head->is[a[i]-'0'])
            {
               // printf("%lld %lld Value found already. Moving on.\n",val%10,flag);
                head=head->next[a[i]-'0'];
                continue;
            }
            else
            {
                flag=0;   
                //printf("%lld Value not found. Inserting\n",val%10); 
                //if(val==0){head->end=1;return;}
                head->is[a[i]-'0']=1;
                head->next[a[i]-'0']=(struct node*)(malloc(sizeof(struct node)));
                head=head->next[a[i]-'0'];
                continue; 
            }
        }
        flag=0;   
        //printf("%lld Value not found. Inserting\n",val%10); 
        //if(val==0){head->end=1;return;}
        head->is[a[i]-'0']=1;
        head->next[a[i]-'0']=(struct node*)(malloc(sizeof(struct node)));
        head=head->next[a[i]-'0'];
    }
    if(flag){ans=1;return;}
    head->end=1;
    return;
}

int main()
{   
    ll n,i,j;
    
    int t;
    
    scanf("%d\n",&t);
    while(t--)
    {    
    struct node* root;
    root=(struct node*)(malloc(sizeof(struct node)));
    scanf("%lld\n",&n);
    char a[n][100];     
    for(i=0;i<n;i++)
    {
        ans=0;
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++)
    {
        ans=0;
        insert(root,a[i]);    
        if(ans)break;       
    }
    if(ans)printf("NO\n");
    else printf("YES\n");
    }
    return 0;
}
