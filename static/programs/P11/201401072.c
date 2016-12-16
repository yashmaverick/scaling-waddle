#include<stdio.h>
#include<stdlib.h>
long long int sta[10000001];
long long int head=-1;
unsigned long long int area=0;
void maxarea(long long int,long long int,long long int);
void insert(long long int *a,long long int n,long long int d)
{
 //   printf("value of head is %d and value at head is %d\n",head,a[sta[head]]);
    //case 1 the stack is empty or
    //inserted element is greater than top of stack
    if(head==-1||a[sta[head]]<=a[d])
    {
        head++;
    }
    else {
        while(!(a[sta[head]]<a[d])&&head>=0)
        {

            if(head==0)
                maxarea(a[sta[head]],0,d);
            else
                maxarea(a[sta[head]],sta[head-1],d-1);
            head--;
        }
        head++;
    }
//    printf("inserting %d at %d\n",a[d],head);
        sta[head]=d;
}

void maxarea(long long int a,long long int b,long long int c) //function to calculate area;
{
    //printf("max area called with value %d between index %d and %d\n ",a,b,c);
    unsigned long long int ar;
    ar=a*(c-b);
    if(ar>area)
   {
       // printf("previous area is %llu and new area is %llu\n",area,ar);
        area=ar;
    }

}
void poprem(long long int *a,long long int n)   //function to pop remaining elements of the array
{
 //   printf("in pop function\n");
    if(head !=-1)
    {
        while(head>=0)
        {
            if(head==0)
                maxarea(a[sta[head]],0,n);
            else
                maxarea(a[sta[head]],sta[head-1],n-1);
            head--;

        }
    }
}
int main()
{
    long long int n,i,t;

         scanf("%lld",&n);
    while(n!=0)
    {
         long long int *a=(long long int *)malloc(sizeof(long long int)*(n+1));
        long long int *b=(long long int *)malloc(sizeof(long long int)*n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            insert(a,n,i);  //putting element in the stack of elements
                            //at its position
        }
        poprem(a,n);
        printf("%llu\n",area);
        area=0;
        head=-1;
        scanf("%lld",&n);
    }
    return 0;


}
