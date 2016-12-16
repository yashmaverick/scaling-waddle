#include<stdio.h>
typedef struct node
{
        long long int val;
        long long int left;
        long long int right;
}node;
long long int parent[1000000],rank[1000000],sz=1;
node lost[1000000],temp[1000000];
void insert(long long int i,long long int j,long long int wei)
{
        lost[sz].val=wei;
        lost[sz].left=i;
        lost[sz].right=j;
        sz++;
}
void mergesort(node a[],long long int st,long long int end)
{
        long long int mid=(st+end)/2,k=0;
        long long int i=st,j=mid+1;
        if(st==end)
                return;
        mergesort(a,st,mid);
        mergesort(a,mid+1,end);
        while(i<=mid || j<=end)
        {
                if(i>mid)
                        temp[k++]=a[j++];
                else if(j>end)
                        temp[k++]=a[i++];
                else
                {
                        if(a[i].val<a[j].val)
                                temp[k++]=a[i++];
                        else
                                temp[k++]=a[j++];
                }
        }
        for(i=0;i<k;i++)
                a[st+i]=temp[i];
}   
int main()
{
        long long int m,n,u,v,w,i,num=1,sum=0,l,r,count=0;
        scanf("%lld%lld",&n,&m);
        if(n==1)
                printf("0\n");
        else
        {
        if(m>0)
        {
                while(m--)
                {
                        scanf("%lld%lld%lld",&u,&v,&w);
                        insert(u,v,w);
                }
                for(i=1;i<=n;i++)
                {
                        parent[i]=i;
                        rank[i]=0;
                }
                mergesort(lost,1,sz-1);
        //        for(i=1;i<=n;i++)
          //              printf("%d ",lost[i].val); 
                for(i=1;i<sz && num<=n;i++)
                {
                        l=lost[i].left;
                        r=lost[i].right;
                        while(parent[l]!=l)
                                l=parent[l];
                        while(parent[r]!=r)
                                r=parent[r];
                        if(parent[l]!=parent[r])
                        {
                                sum=sum+lost[i].val;
                                if(rank[l]==rank[r])
                                {
                                        parent[l]=parent[r];
                                        rank[r]++;
                                }
                                else if(rank[r]<rank[l])
                                        parent[r]=parent[l];
                                else if(rank[r]>rank[l])
                                        parent[l]=parent[r];
                                num++;
                        }
                }
                for(i=1;i<=n;i++)
                {
            //            printf("%d ",lost[i].val);
                        if(parent[i]==i)
                                count++;
                }
                if(count==1)
                        printf("%lld\n",sum);
                else
                        printf("-1\n");
        }
        else
                printf("-1\n");
        }
        return 0;
}
