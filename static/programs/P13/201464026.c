#include<stdio.h>
#include<stdlib.h>
typedef struct ans
{
    int node;
    int depth;
}ans;
ans deptha(int *a,int start,int end,int d,int max,ans prev)
{
    if(end<start)
        return prev;
    ans final;
    final.depth=d;
    final.node=a[start];
    if(end-start==0)
    {
        final.depth;
        return final;
    }
    int temp = a[start];
    int nr = max-temp;
    int nl = end-start+1-nr;
    ans r = deptha(a,start+1,start+nr,d+1,max,final);
    ans l = deptha(a,start+nr+1,end,d+1,temp-1,final);
    if(r.depth > l.depth)
        final = r;
    else
        final = l;
    return final;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,*a,i;
        ans answer;
        scanf("%d",&n);
        a = (int *)malloc(4*n);
        for(i=0;i<n;i++)
            scanf("%d",a+n-i-1);
        answer.node=a[0];
        answer.depth=0;
        answer = deptha(a,0,n-1,0,n,answer);
        printf("%d %d\n",answer.node,answer.depth);
    }
    return 0;
}
