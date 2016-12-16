
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%lld",&n)
#define sc(n) scanf("%d",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; sc(t); while(t--)
typedef long long LL;
int ar[10004],tp=0,bt;
int main()
{	int a[10004];
	DRT(){	ar[0]=-1;
		tp=1;
		bt=1;
		int n,i,k,j;
		sc(n);sc(k);
		for(i=0;i<n;i++)
			sc(a[i]);
		for(i=0;i<n;i++)
		{	if(ar[bt]<=i-k)
				bt++;
			while(a[ar[tp-1]]>=a[i] && tp>bt)
				tp--;
//			for(j=bt;j<tp;j++)
//				printf("%d\n",ar[j]);
			ar[tp++]=i;
//			printf("%d %d\n",tp,bt);
			if(i>=k-1 && i<n-1)

	printf("%d ",a[ar[bt]]);
			else if(i==n-1)
				printf("%d\n",a[ar[bt]]);
		}


	}
}
			

