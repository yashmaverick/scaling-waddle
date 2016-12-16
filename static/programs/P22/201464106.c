#include<stdio.h>
#define N 1000000007
long long int min_heap[2000000];
long long int max_heap[2000000];

void swap(long long int *p,long long int *q)
{
    long long int hold=*p;
    *p=*q;
    *q=hold;
}

long long int sz_min=0;
long long int sz_max=0;

void ins_minheap(long long int x)
{
    sz_min++;
    long long int i=sz_min;
    min_heap[i]=x;
    while(min_heap[i]<min_heap[i/2] && i/2!=0)
    {
        swap(&min_heap[i],&min_heap[i/2]);
        i=i/2;
    }
}

void ins_maxheap(long long int x)
{
    sz_max++;
    long long int i=sz_max;
    max_heap[i]=x;
    while(max_heap[i]>max_heap[i/2] && i/2!=0)
    {
        swap(&max_heap[i],&max_heap[i/2]);
        i=i/2;
    }
}

long long int del_minheap()
{
    long long int ret=min_heap[1];
    min_heap[1]=min_heap[sz_min];
    min_heap[sz_min]='\0';
    sz_min--;
    long long int sz=sz_min;
    long long int i=1;
    while(i<=sz/2)
    {
        if((min_heap[i]>min_heap[2*i]) && (min_heap[i]>min_heap[2*i+1]) && (min_heap[2*i]!='\0') && (min_heap[2*i+1]!='\0'))
            if(min_heap[2*i]>min_heap[2*i+1])
            {
                swap(&min_heap[i],&min_heap[2*i+1]);
                i=2*i+1;
            }
            else
            {
                swap(&min_heap[i],&min_heap[2*i]);
                i=2*i;
            }
        else if(min_heap[i]>min_heap[2*i+1] && min_heap[2*i+1]!='\0')
        {
            swap(&min_heap[i],&min_heap[2*i+1]);
            i=2*i+1;
        }
        else if(min_heap[i]>min_heap[2*i] && min_heap[2*i]!='\0')
        {
            swap(&min_heap[i],&min_heap[2*i]);
            i=2*i;
        }
        else
            break;
    }
    return ret;
}


long long int del_maxheap()
{
    long long int ret=max_heap[1];
    max_heap[1]=max_heap[sz_max];
    max_heap[sz_max]='\0';
    sz_max--;
    long long int sz=sz_max;
    long long int i=1;
    while(i<=sz/2)
    {
        if((max_heap[i]<max_heap[2*i]) && (max_heap[i]<max_heap[2*i+1]) && (max_heap[2*i]!='\0') && (max_heap[2*i+1]!='\0'))
        {
            if(max_heap[2*i]>max_heap[2*i+1])
            {
                swap(&max_heap[i],&max_heap[2*i]);
                i=2*i;
            }
            else
            {
                swap(&max_heap[i],&max_heap[2*i+1]);
                i=2*i+1;
            }
        }
        else if(max_heap[i]<max_heap[2*i] && max_heap[2*i]!='\0')
        {
            swap(&max_heap[i],&max_heap[2*i]);
            i=2*i;
        }
        else if(max_heap[i]<max_heap[2*i+1] && max_heap[2*i+1]!='\0')
        {
            swap(&max_heap[i],&max_heap[2*i+1]);
            i=2*i+1;
        }
        else
            break;
    }
    return ret;
}


int main()
{
    int t;
    for(scanf("%d",&t);t--;)
    {
        long long int a,b,c,n,i,s;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
        for(i=1;i<=n;i++)
        {
            max_heap[i]=0;
            min_heap[i]=0;
        }
        long long int f[n+1],m;
      //  f[0]='\0';
         f[1]=1;
      //  f[2]=(a+(2*b)+c)%N;
      //  f[3]=(a+(3*b)+c)%N;
      //  s=f[1]+f[2]+f[3];
        ins_maxheap(f[1]);
        s=1;
      //  ins_maxheap(f[2]);
      //  ins_minheap(f[3]);
            for(i=2;i<=n;i++)
            {
             //   m=max_heap[1];
                if(sz_max>=sz_min)
                {
                    m=max_heap[1];
                }
                else
                {
                    m=min_heap[1];
                }
                f[i]=((a*m)+(b*i)+c)%N;
                s+=f[i];
                ins_maxheap(f[i]);
                if(sz_max-sz_min>1 || (sz_min!=0 && max_heap[1]>min_heap[1]))
                {
                    long long int x;
                    x=del_maxheap();
                    ins_minheap(x);

                }
                if(sz_min-sz_max>1)
                {
                    long long int x;
                    x=del_minheap();
                    ins_maxheap(x);
                }
            }
            printf("%lld\n",s);
        sz_min=sz_max=0;
    }
    return 0;
}
