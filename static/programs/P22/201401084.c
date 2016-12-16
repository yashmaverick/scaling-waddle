#include <stdio.h>

long long int minheap[200005];
long long int maxheap[200005];
long long int rear1,rear2;
long long int n;
long long int M=1000000007;

void print1()
{
    long long int i;
    for(i=1;i<=rear1;i++)
    {
        printf("minheap[%lld]=%lld ",i,minheap[i]);
    }
    printf("\n");
}

void print2()
{
    long long int i;
    for(i=1;i<=rear2;i++)
    {
        printf("maxheap[%lld]=%lld ",i,maxheap[i]);
    }
    printf("\n");
}


void minheapify();

void maxheapify();

void shuffledownminheapify(long long int i)
{
    if(rear1==0)
        return;
    long long int left=2*i;
    long long int right=2*i+1;
    long long int min=i;
    if(left<=rear1 && minheap[min]>minheap[left])
        min=left;
    if(right<=rear1 && minheap[min]>minheap[right])
        min=right;
    if(min!=i)
    {
        long long int temp=minheap[min];
        minheap[min]=minheap[i];
        minheap[i]=temp;
        shuffledownminheapify(min);
    }
    //  print1();
}

void shuffledownmaxheapify(long long int i)
{
    if(rear2==0)
        return;
    long long int left=2*i;
    long long int right=2*i+1;
    long long int min=i;
    if(left<=rear2 && maxheap[min]<maxheap[left])
        min=left;
    if(right<=rear2 && maxheap[min]<maxheap[right])
        min=right;
    if(min!=i)
    {
        long long int temp=maxheap[min];
        maxheap[min]=maxheap[i];
        maxheap[i]=temp;
        shuffledownmaxheapify(min);
    }
    // print2();
}

void delminheap()
{
    minheap[1]=minheap[rear1];
    rear1=rear1-1;
    shuffledownminheapify(1);
    // print1();
}

void delmaxheap()
{
    maxheap[1]=maxheap[rear2];
    rear2=rear2-1;
    shuffledownmaxheapify(1);
    //print2();
}

void minheapify(long long int i)
{
    if(i==1)
        return;
    long long int parent=i/2;
 //   minheapify(i/2);
    if(minheap[parent]>minheap[i])
    {
        long long int temp=minheap[parent];
        minheap[parent]=minheap[i];
        minheap[i]=temp;
                minheapify(parent);
    }
    //  minheapify(parent);
    // print1();
}

void maxheapify(long long int i)
{
    if(i==1)
        return;
    long long int parent=i/2;
  //  maxheapify(i/2);
    if(maxheap[parent]<maxheap[i])
    {
        long long int temp=maxheap[parent];
        maxheap[parent]=maxheap[i];
        maxheap[i]=temp;
                maxheapify(parent);
    }
    //  minheapify(parent);
    //print2();
}

int main()
{
    long long int t,m,a,b,c,i,n;
    long long int x;
    long long int median;
    scanf("%lld",&t);
    for(m=1;m<=t;m++)
    {
        long long int s=1;
        rear2=1;                            //size of max heap
        rear1=0;                            //size of min heap
        maxheap[rear2]=1;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
        median=1;
        for(i=2;i<=n;i++)
        {
            x=(a*median+b*i+c)%M;
            s=s+x;
            if(i<n)
            {
                if(x>maxheap[1])
                {
                    rear1++;
                    minheap[rear1]=x;
                    minheapify(rear1);
                }
                else
                {
                    rear2++;
                    maxheap[rear2]=x;
                    maxheapify(rear2);
                }
                if((rear2-rear1)>1)
                {
                    rear1++;
                    minheap[rear1]=maxheap[1];
                    delmaxheap();
                    minheapify(rear1);
                }
                else if((rear1-rear2)>1)
                {
                    rear2++;
                    maxheap[rear2]=minheap[1];
                    delminheap();
                    maxheapify(rear2);
                }
                if(rear2>=rear1)
                {
                    median=maxheap[1];
                }
                /*    else if(rear1>rear2)
                      {
                      median=minheap[1];
                      }*/
                else
                {
                    median=minheap[1];
                }
               /* printf("median=%lld\n",median);
                print1();
                print2();*/
            }
        }
        printf("%lld\n",s);
    }
    return 0;
}

