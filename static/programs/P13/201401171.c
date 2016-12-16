#include<stdio.h>
#define maxN 100005

int arr[maxN][2],n,perm[maxN],next[maxN],map[maxN],ans1,ans2,visit[maxN];

int binsearch(int a, int start, int last)
{
    int low = start,k=-1, high = last;
    while (low <= high) 
    {
        int mid = (low + high) / 2; 
        if (perm[mid] <a) 
        {
            k=mid;
            low = mid + 1;
        }
        else 
        {
            high = mid-1;
        }
    }
    return(k);
}

void make(int root, int start, int last)
{
    if(start<0||last<0)return;
    int k=binsearch(root,start,last);
    //printf("%d %d %d %d\n",root,start,last,k);
    if(k==-1)
    {
        if(last>=start)
        {
            arr[root][1]=perm[last];
        }
        if(last>start)
        {
            make(perm[last],start,last-1);
        }
    }
    else
    {
        arr[root][0]=perm[k];
        make(perm[k],start,k-1);
        if(last!=k)
        {
            arr[root][1]=perm[last];
            make(perm[last],k+1,last-1);
        }
    }
}

void dfs(int i,int level)
{
    if(visit[i]==1)
        return;
    visit[i]=1;
    if(i==0)
        return;
    if(level>ans2)
    {
        ans2=level;
        ans1=i;
    }
    if(level==ans2)
        if(ans1>i)
            ans1=i;

    dfs(arr[i][0],level+1);
    dfs(arr[i][1],level+1);
}

int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&perm[i]);
            arr[i][0]=0;
            arr[i][1]=0;
            visit[i]=0;
            next[i]=0;
            map[perm[i]]=i;
        }
        visit[n]=0;
        arr[n][0]=0;
        arr[n][1]=0;
        next[n]=0;
        ans1=0;
        ans2=0;
        make(perm[n-1],0,n-2);
        dfs(perm[n-1],0);
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
