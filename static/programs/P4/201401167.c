#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%lld",&n)
#define sc(n) scanf("%d",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; sc(t); while(t--)
typedef long long LL;
struct triplet{
	int i,j;
};
typedef struct triplet trip;
static int cmpe(const void* a1,const void* b1)
{	trip *a=(trip *) a1;
	trip *b=(trip *) b1;
	if(a->i<b->i)
		return -1;
	else if(a->i>b->i)
		return 1;
/*	else if(a->j>b->j)
		return 1;
	else if(a->j<b->j)
		return -1;
*/	else 
		 return a->j - b->j;
}

int main()
{	
	DRT(){
		trip ar[100003];
		ar[0].i=0;ar[0].j=0;//ar[0].k=0;
		int i=-1,j,n;char a[100004];
		SET(a,0);
		scanf("%s",a);LL o=0;
//		printf("%s",a);
		while(a[++i]!='\0')
		{	if(a[i]=='J')
			{	ar[i+1].i=ar[i].i+1;ar[i+1].j=ar[i].j+1;}
			else if(a[i]=='M')
			{ar[i+1].i=ar[i].i-1;ar[i+1].j=ar[i].j;}
			else
			{	ar[i+1].j=ar[i].j-1;ar[i+1].i=ar[i].i;}
//				printf("%d %d %d\n",i,ar[i].i,ar[i].j);
//			printf("%d",ar[i].i);
		}
//		printf("\n");
		qsort(ar,i+1,sizeof(trip),cmpe);
		for(j=0;j<i;j++)
		{n=1;
			while(!cmpe(&ar[j],&ar[j+1]) && j<i)
							n++,j++;
//	printf("%d %d %d\n",n,ar[j].i,ar[j].j);	
		o+=n*(n-1)/2;
		}	printf("%lld\n",o);
	}
}
			

