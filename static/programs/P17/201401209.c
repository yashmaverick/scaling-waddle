#include<stdio.h>
int ans=-1;
int pre[100000],prei[100001],ini[100001];
void check(int root,int x,int y,int ll,int ul)
{
//    printf("%d\n",root);
    if(x==root || y==root) {ans=root; return;}
    else if((ini[x]>ini[root] && ini[y]<ini[root]) || ( ini[x]<ini[root] && ini[y]>ini[root] )   ) { ans=root; return;  }
    else if(ini[x]<ini[root] && ini[y]<ini[root]) check(pre[prei[root]+1],x,y,ll,ini[root]-1);
    else if(ini[x]>ini[root] && ini[y]>ini[root]) check(pre[prei[root]+ini[root]+1-ll],x,y,ini[root]+1,ul);
}
int main()
{
    int x,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&pre[i]);
//    for(i=0;i<n;i++) scanf("%d",&in[i]);
    for(i=0;i<n;i++) { prei[pre[i]]=i;  }
    for(i=0;i<n;i++) { scanf("%d",&x); ini[x]=i;  }
   //for(i=1;i<n+1;i++) printf("%d ",prei[i]); printf("\n");
     //for(i=1;i<n+1;i++) printf("%d ",ini[i]); printf("\n");
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==y) { printf("%d\n",x); continue;  }
        check(pre[0],x,y,0,n-1);
        printf("%d\n",ans);
        ans=-1;
    }
    return 0;
}
