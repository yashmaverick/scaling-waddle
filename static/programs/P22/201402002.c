#include<stdio.h>

#define MOD 1000000007

long long int min_heap[200010];         // Initial values are much bigger
long long int max_heap[200010];         // Initial values are much bigger
long long int min_store=1;
long long int max_store=1;


long long int min(long long int A,long long int B)
{
    return (A<B)?A:B;
}

long long int max(long long int A, long long int B)
{
    return (A>B)?A:B;
}


void insert_in_min_heap(long long int data)
{
    min_heap[min_store]=data;
    long long int check=min_store;
    while (min_heap[(check/2)] > min_heap[check] && check!=1)
    {
        long long int temp=min_heap[check];
        min_heap[check]=min_heap[check/2];
        min_heap[check/2]=temp;
        check/=2;
    }
    min_store++;
}

void insert_in_max_heap(long long int data)
{
    max_heap[max_store]=data;
    long long int check=max_store;
    while (max_heap[(check/2)] < max_heap[check] && check!=1)
    {
        long long int temp=max_heap[check];
        max_heap[check]=max_heap[check/2];
        max_heap[check/2]=temp;
        check/=2;
    }
    max_store++;
}


void deletemin()
{
    min_heap[1]=min_heap[min_store-1];
    long long int check=1;
    while (min(min_heap[check*2],min_heap[check*2 + 1]) < min_heap[check])
    {
        long long int MIN = (min_heap[check*2]<min_heap[check*2 + 1])?(check*2):(check*2+1);
        if (MIN>=min_store)
            break;
        long long int temp=min_heap[MIN];
        min_heap[MIN]=min_heap[MIN/2];
        min_heap[MIN/2]=temp;
        check=MIN;
    }
    min_store--;
}

void deletemax()
{
    max_heap[1]=max_heap[max_store-1];
    long long int check=1;
    while (max(max_heap[check*2],max_heap[check*2 + 1]) > max_heap[check])
    {
        long long int MAX = (max_heap[check*2]>max_heap[check*2 + 1])?(check*2):(check*2+1);
        if (MAX>=max_store)
            break;
        long long int temp=max_heap[MAX];
        max_heap[MAX]=max_heap[MAX/2];
        max_heap[MAX/2]=temp;
        check=MAX;
    }
    max_store--;
}

long long int top_min()
{
    return min_heap[1];
}

long long int top_max()
{
    return max_heap[1];
}

void move_from_min_to_max()
{
    long long int MIN=min_heap[1];
    deletemin();
    insert_in_max_heap(MIN);
}

void move_from_max_to_min()
{
    long long int MAX=max_heap[1];
    deletemax();
    insert_in_min_heap(MAX);
}
/*
void print_heap()
{
    int i=0;
    printf("MAX HEAP : ");
    for(i=1;i<max_store;i++)
        printf("%d, ",max_heap[i]);
    printf("\n");

    printf("MIN HEAP : ");
    for(i=1;i<min_store;i++)
        printf("%d, ",min_heap[i]);
    printf("\n");
}
*/
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        max_store=min_store=1;
        long long int a,b,c,n;
        scanf("%lld %lld %lld %lld",&a ,&b ,&c ,&n);

        // top of max heap is median

        long long int ANS=1;
        long long int i;
        insert_in_max_heap(1);
        for(i=2;i<=n;i++)
        {
  //          printf("NEXT ITER STARTS : =====================================\n");
  //          print_heap();
            long long int m=top_max();
//            printf("Median = %d\n",m);
            long long int temp_ans;
            temp_ans = ( (a*m)%MOD + (b*i)%MOD + c)%MOD;
            long long int ans2 = temp_ans;

 //           print_heap();
 //   printf("INSERTING ==================\n");
            if(ans2 <= m)
                insert_in_max_heap(ans2);
            else
                insert_in_min_heap(ans2);

 //           print_heap();
            long long int ELEM_Max = max_store -1;
            long long int ELEM_Min = min_store -1;

//    printf("MOVING ==================\n");
            if( (ELEM_Max - ELEM_Min) > 1)
                move_from_max_to_min();
            else if((ELEM_Min - ELEM_Max) >= 1)
                move_from_min_to_max();

//            printf("F[%d] = %d\n",i ,ans2);
 //           print_heap();
            ANS+=temp_ans;
        }
        printf("%lld\n",ANS);
    }

    return 0;
}
