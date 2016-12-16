/*
_____________________________________________
PROBLEM STATEMENT: 
TEST CASES:
COMMENTS:

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define LL long long int 
#define MOD 1000000007

LL minheap[200001];
int size_minheap;
int size_maxheap;
LL maxheap[200001];

void swap(LL arr[],int i,int j)              // swaps value at index i and j in arr[]
{
    if(i==j) return ;
    arr[i]=arr[i]+arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]=arr[i]-arr[j];
}

int max(int a , int b)                    // returns max of two numbers
{
    int c=a>b?a:b;
    return c;
}

int min(int a,int b)                     //returns min of two numbers
{
    int c=a<b?a:b;
    return c;
}
void insert_minheap(LL element)
{
    int i;
    minheap[size_minheap++]=element;
    for(i=size_minheap-1;i>0;)
    {
        if(minheap[i/2]>minheap[i])
        {
            swap(minheap,i/2,i);
            i=i/2;
        }
        else break;
    }
}

void insert_maxheap(LL element)
{
   // printf("%d-maxsize\n",size_maxheap);
    int i;
    maxheap[size_maxheap++]=element;
    for(i=size_maxheap-1;i>0;)
    {
        if(maxheap[i/2]<maxheap[i])
        {
            swap(maxheap,i/2,i);
            i=i/2;
        }
        else break;
    }
}

LL delete_minheap()
{
    int i;
    swap(minheap,1,--size_minheap);
//    size_minheap--;
    for(i=1;2*i+1<size_minheap;)
    {
        int temp=minheap[2*i]<minheap[2*i+1]?2*i:2*i+1;
        if(minheap[i]>minheap[temp])
        {
            swap(minheap,i,temp);
            i=temp;
        }
        else break;
    }
    if(2*i+1==size_minheap) if(minheap[i]>minheap[2*i]) swap(minheap,i,2*i);
    return minheap[size_minheap];
}

LL delete_maxheap()
{
    int i;
    swap(maxheap,1,--size_maxheap);
   /// size_maxheap--;
    for(i=1;2*i+1<size_maxheap;)
    {
        int temp=maxheap[2*i]>maxheap[2*i+1]?2*i:2*i+1;
        if(maxheap[i]<maxheap[temp])
        {
            swap(maxheap,i,temp);
            i=temp;
        }
        else break;
    }
    if(2*i+1==size_maxheap) if(maxheap[i]<maxheap[2*i]) swap(maxheap,i,2*i);
    return maxheap[size_maxheap];
}

void resize()
{
    int check=abs(size_minheap - size_maxheap);
    if(check ==0 || check == 1) return ;
    else
    {
        if(size_minheap-size_maxheap > 1) 
        {
            LL k=delete_minheap();
            insert_maxheap(k);
        }
        else if(size_maxheap-size_minheap > 1)
        {
            LL k=delete_maxheap();
            insert_minheap(k);
        }
    }
}

void insert(LL element)
{
        if(element>maxheap[1])    insert_minheap(element);
        else    insert_maxheap(element);            
        resize();
}

LL median()
{
    if(size_minheap>size_maxheap) return minheap[1];
    else return maxheap[1];
}
                     
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL a,b,c,n,f;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
        int k;
     //   for(k=0;k<100000;k++) {maxheap[k]=0; minheap[k]=0;}
        size_minheap=1;
        size_maxheap=1;
        minheap[0]=-1;
        maxheap[0]=2000000000000;
        LL sum=1;
        insert_maxheap(1);
        LL i=2;
        while(i<=n)
        {
        //    printf("HELLO\n");
            //int j;
            //LL f=(((a%MOD)*(median())%MOD)%MOD + ((b%MOD)*(i%MOD))%MOD + c)%MOD;
            f= (a*median() + b*i +c) %MOD;
      //      printf("for %lld cur is %lld\n",i,f);
            sum = (sum + f);
            insert(f);
            i++;
/*        printf("___________________________\n");
        printf("%lld-f %d-size_minheap %d-size_maxheap %lld-median\n",f,size_minheap,size_maxheap,median());
        printf("maxheap\n");
        for(j=1;j<20;j++) printf("%lld ",maxheap[j]);
        printf("\nminheap\n");
        for(j=1;j<20;j++) printf("%lld ",minheap[j]);
        printf("\n_______________________________\n");*/
        }
        printf("%lld\n",sum);
    }
return 0;
}
