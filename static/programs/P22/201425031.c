#include<stdio.h>
#include<stdlib.h>

long long int maxheap[200005],minheap[200005],maxheapend,minheapend;

void maxheapins(long long int element)
{
    long long int k,temp;
    maxheapend++;
    maxheap[maxheapend]=element;
    k=maxheapend;
    while(k/2>=1)
    {
        if(maxheap[k]>maxheap[k/2])
        {

            temp=maxheap[k];
            maxheap[k]=maxheap[k/2];
            maxheap[k/2]=temp;
            k=k/2;
        }
        else
            break;
    }
}

long long int maxheapdel()
{
    long long int l=maxheap[1],temp,left,right,index,max;
    maxheap[1]=maxheap[maxheapend];
  //  maxheap[maxheapend]=-1;
    maxheapend--;
    long long int u=1;
    while(2*u<=maxheapend )
    {
        left=2*u;
        right=left+1;
        max=maxheap[left];
        index=left;
        if(right<=maxheapend)
        {
            if(maxheap[right]>max)
            {
                max=maxheap[right];
                index=right;
            }
        }
        if(maxheap[u]<maxheap[index])
        {
            temp=maxheap[u];
            maxheap[u]=maxheap[index];
            maxheap[index]=temp;
            u=index;
        }
        else
            break;
    }
    return l;
}

void minheapins(long long int element)
{
    long long int w,temp;
    minheapend++;
    minheap[minheapend]=element;
    w=minheapend;
    while(w/2>=1)
    {
        if(minheap[w]<minheap[w/2])
        {
            temp=minheap[w];
            minheap[w]=minheap[w/2];
            minheap[w/2]=temp;
            w=w/2;
        }
        else
            break;
    }
}

long long int minheapdel()
{
    long long int l=minheap[1],temp,min,left,right,index;
    minheap[1]=minheap[minheapend];
//    minheap[minheapend]=1000000009;
    minheapend--;
    long long int u=1;
    while(2*u<=minheapend)
    {
        left=2*u;
        right=left+1;
        min=minheap[left];
        index=left;
        if(right<=minheapend)
        {
            if(minheap[right]<min)
            {
                min=minheap[right];
                index=right;
            }
        }
        if(minheap[u]>minheap[index])
        {
            temp=minheap[u];
            minheap[u]=minheap[index];
            minheap[index]=temp;
            u=index;
        }
        else
            break;
    }
    return l;
}


int main()
{
    long long int a,x,y,b,c,f,m,n,i,j,k,l;
    long long int sum,T;
    scanf("%lld",&T);
    while(T--)
    {

        maxheapend=0;
        minheapend=0;
//        for(i=0;i<=n;i++)
  //      {
    //        maxheap[i]=-1;
      //      minheap[i]=1000000009;
       // }
        sum=1;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
        maxheapins(1);
        for(i=2;i<=n;i++)
        {
            if(maxheapend>=minheapend)
                m=maxheap[1];
            else
                m=minheap[1];
            f=((a*m)+(b*i)+c)%1000000007;
            sum=sum+f;
            if(maxheapend==minheapend)
            {
                if(f<=maxheap[1])
                    maxheapins(f);
                else if(f>=minheap[1])
                    minheapins(f);
                else
                    maxheapins(f);
            }
            else if(maxheapend>minheapend)
            {
                if(f<=maxheap[1])
                {
                    x=maxheapdel(maxheap[1]);
                    minheapins(x);
                    maxheapins(f);
                }
                else if(f>=minheap[1])
                    minheapins(f);
                else
                    minheapins(f);
            }
            else
            {
                if(f<=maxheap[1])
                    maxheapins(f);
                else if(f>=minheap[1])
                {
                    y=minheapdel(minheap[1]);
                    maxheapins(y);
                    minheapins(f);
                }
                else
                    maxheapins(f);
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
