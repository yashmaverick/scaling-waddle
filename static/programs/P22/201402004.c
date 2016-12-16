#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long int
#define mod 1000000007

ll min_heap[1000100],min_size;

void insert_min_heap(ll val)
{
        min_size++;
        min_heap[min_size]=val;
        ll now=min_size;
        while(min_heap[now/2]>val&&now/2!=0) 
        {
                min_heap[now]=min_heap[now/2];
                now /= 2;
        }
        min_heap[now]=val;
}

ll deletemin()
{
        ll child,now,min,last;
        min=min_heap[1];
        last=min_heap[min_size];
        min_size--;
        for(now=1;now*2<=min_size ;now=child)
        {
                child=now*2;
                if(child!=min_size && min_heap[child+1]<min_heap[child] ) 
                        child++;
                if(last>min_heap[child])
                {
                        min_heap[now]=min_heap[child];        
                }
                else
                    break;
        }
        min_heap[now]=last;
        return min;
}


ll max_heap[1000100],max_size;

void insert_max_heap(ll val)
{
        max_size++;
        max_heap[max_size]=val;
        ll now=max_size;
        while(max_heap[now/2]<val&&now/2!=0) 
        {
                max_heap[now]=max_heap[now/2];
                now/=2;
        }
        max_heap[now]=val;
}

ll deletemax()
{
        ll child,now,max,last;
        max=max_heap[1];
        last=max_heap[max_size];
        max_size--;
        for(now=1;now*2<=max_size ;now=child)
        {
                child=now*2;
                if(child!=max_size && max_heap[child+1]>max_heap[child] ) 
                        child++;
                if(last<max_heap[child])
                {
                        max_heap[now]=max_heap[child];        
                }
                else
                    break;
        }
        max_heap[now]=last;
        return max;
}

int main()
{
    ll t,i,a,b,c,n,sum=0,median,f;
	scanf("%lld",&t);
	while(t--)
	{
	    scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
	    for(i=1;i<n+10;i++)min_heap[i]=max_heap[i]=0;
	    min_size=0;
	    max_size=0;
	    min_heap[0]=-1000000000000;
	    max_heap[0]=1000000000000;
        insert_max_heap(1);
        sum=1;
	 	for(i=2;i<=n;i++)
	 	{
	 		median=max_heap[1];
	 		f=a*median + b*i + c;
	 		
	 		if(f>=mod)f=f%mod;
	 		
	 		if(median>f)insert_max_heap(f);
	 		else insert_min_heap(f);
	 		
	 		while(max_size > min_size+1)
	 		{
	 			insert_min_heap(max_heap[1]); 
	 			deletemax();
	 		}
	 		while(min_size > max_size)
	 		{
	 			insert_max_heap(min_heap[1]); 
	 			deletemin();
	 		}
	 		sum+=f;
	 	}
	 	printf("%lld\n",sum);   
    }
    return 0;
}
