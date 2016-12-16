#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define bag struct bag
bag
{
	ll *items;
	ll rOD,M;	
};
//rOD = weight

void swap(bag *a, bag *b)
{
    bag temp = *a;
    *a = *b;
    *b = temp;
}
 
void bubbleS(bag a[], ll n)
{
   int i, j;
   for (i = 0; i < n; i++)     
       for (j = 0; j < n-i-1; j++) 
           if ( a[j].rOD > a[j+1].rOD)// || (a[j].lOD==a[j+1].lOD && a[j].rOD>a[j+1].rOD))
              swap(&a[j], &a[j+1]);
}

int main()
{
	ll N,MOD,M,W,i,j;
	//bag B[100];
	scanf("%lld %lld",&N,&MOD);
	bag B[1001];
	for(i=0;i<N;i++)
	{
		scanf("%lld",&M);
		B[i].M=M;
		ll *it=(ll*)malloc(sizeof(ll)*M);
		B[i].items=it;
		/*B[i].lOD=*/B[i].rOD=0;
		for(j=0;j<M;j++)
		{
			ll item;
			scanf("%lld",&item);
			B[i].rOD=(B[i].rOD+item)%MOD;
			//B[i].lOD+=(B[i].rOD+item)/MOD;
			B[i].items[j]=item;
		}		
	}
	bubbleS(B,N);
	for(i=0;i<N;i++)
	{
		printf("%lld\n",B[i].rOD);
		for(j=0;j<B[i].M;j++)		
			printf("%lld\n",B[i].items[j]);
		printf("\n");
	}
	return 0;
}