#include<stdio.h>
#define M 1000000007
void swap(int* x, int* y)
{
        int temp=*x;
        *x=*y;
        *y=temp;
}
int minheap[1000010];
int maxheap[1000010];
int smin,smax;
void heapifymin(int i)
{
        int l=2*i;
        int r=2*i+1;
        int min=i;
        if(l<=smin&&minheap[l]<minheap[i])
                min=l;
        if(r<=smin&&minheap[r]<minheap[min])
                min=r;
        if(min!=i)
        {
                swap(&minheap[i],&minheap[min]);
                heapifymin(min);
        }
} 
void heapifymax(int i)
{
        int l=2*i;
        int r=2*i+1;
        int max=i;
        if(l<=smax&&maxheap[l]>maxheap[i])
                max=l;
        if(r<=smax&&maxheap[r]>maxheap[max])
                max=r;
        if(max!=i)
        {
                swap(&maxheap[i],&maxheap[max]);
                heapifymax(max);
        }
}
int delmin()
{
        if(smin<=0)
                return;
        if(smin==1)
        {
                smin--;
                return minheap[1];
        }
        int x=minheap[1];
        minheap[1]=minheap[smin];
        smin--;
        heapifymin(1);
        return x;
}
int delmax()
{
        if(smax<=0)
                return;
        if(smax==1)
        {
                smax--;
                return maxheap[1];
        }
        int x=maxheap[1];
        maxheap[1]=maxheap[smax];
        smax--;
        heapifymax(1);
        return x;
}
void mininsert(int r)
{
        minheap[smin+1]=r;
        smin++;
        int i=smin;
        while(i>1&&minheap[i/2]>minheap[i])
        {
                swap(&minheap[i],&minheap[i/2]);
                i/=2;
        }
}
void maxinsert(int r)
{
        maxheap[smax+1]=r;
        smax++;
        int i=smax;
        while(i>1&&maxheap[i/2]<maxheap[i])
        {
                swap(&maxheap[i],&maxheap[i/2]);
                i/=2;
        }
}
int insert(int r,int m)
{
        if(smax==smin+1)
        {
                if(r<m)
                {
                        int temp=delmax();
                        mininsert(temp);
                        maxinsert(r);
                }
                else              
                        mininsert(r); 
                m=maxheap[1];
        }
        else if(smin==smax)
        {
                if(r<m)
                {
                        maxinsert(r);
                        m=maxheap[1];
                }
                else
                {
                        mininsert(r);
                        m=minheap[1];
                }
        }
        else
        {
                if(r<m)
                        maxinsert(r);
                else
                {
                        int temp=delmin();
                        maxinsert(temp);
                        mininsert(r);
                }
                m=maxheap[1];
        }
        return m;
}
int main()
{
        int i,j,n,t;
        long long int r,a,b,c,sum;
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                int m=0;               
                sum=1;
                smax=0;
                smin=0;
                scanf("%lld%lld%lld%d",&a,&b,&c,&n);
                for(j=1;j<=n;j++)
                {
                        minheap[j]=0;
                        maxheap[j]=0;
                }
                m=insert(1,0);             
                for(j=2;j<=n;j++)
                {
                        r=((a*m)+(b*j)+c)%M;
                        sum=(sum+r);
                        m=insert(r,m);
                }
                printf("%lld\n",sum);
        }
        return 0;
}
