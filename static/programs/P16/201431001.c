#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define si(a)               scanf("%d",&a)
#define sii(a,b)            scanf("%d %d",&a,&b)
#define sl(a)               scanf("%lld",&a)
#define slu(a)              scanf("%llu",&a)
#define sf(a)               scanf("%f",&a)
#define sd(a)               scanf("%lf",&a)
#define ss(a)               scanf("%s",a)
#define pi(a)               printf("%d",a)
#define pii(a,b)            printf("%d %d",a,b)
#define pl(a)               printf("%lld",a)
#define pnl					printf("\n")

#define LL                  long long 
#define UI                  unsigned int
#define ULL                 unsigned long long
#define MOD                 1000000007
#define MAX                 1000000007000
#define forall(i,a,b)       for(i=a; i<b; i++)

#define max(a,b)    ((a) > (b) ? (a) : (b))
#define min(a,b)    ((a) < (b) ? (a) : (b))

int b_search(int A[], int l, int r, int key)
{
    int m;

    while(r - l > 1)
    {
        m = l + (r - l)/2;
 
        if(A[m] <= key)
            l = m;
        else
            r = m;
    }
    return l;
}
 
int main()
{
	int t;
	si(t);

	int data[31],i;
	data[0] = 1;
	for(i = 1; i < 31; i++)
	{
		data[i] = data[i - 1] * 2;
		//printf("%d\n",data[i]);
	}
	while(t--)
	{
		int q;
		si(q);
		int index = b_search(data, 0, 30, q);
		
		if(q < data[index] + data[index]/2)
			printf("%d\n",index * 2 - 1);
		else
			printf("%d\n",index * 2);
	}
	return 0;
}