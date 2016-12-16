#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%lld",&n)
#define sc(n) scanf("%d",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; sc(t); while(t--)
typedef long long LL;
static int cmpr(const void *a,const void *b)
{	int *a1,*b1;
	a1=(int*)a;b1=(int*)b;
	return *a1 - *b1;
}

int main()
{	
	DRT(){
		int k,ar[1009];
		int i=-1,j,n;char a[1000];
		sc(n);sc(k);int k1=k;
		while(++i<n){
		scanf("%s",a);sc(ar[i]);}
		qsort(ar,i,sizeof(int),cmpr);
		for(j=0;j<i;j++)
		{	k1=k-ar[j];
			int b,e,m;
			for(b=j+1,e=i-1;b<e;)
				if(k1>ar[b]+ar[e])
					b++;
				else if(k1==ar[b]+ar[e])
				{i=-1;break;}
				else
					e--;
		}
		if(i>-1)
		printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
			

