#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#include<limits.h>
#define set(ch,a) memset(ch,a,sizeof(ch))
#define ml(a) (a*)malloc(sizeof(a))
int pre[10000],in[10000];
typedef struct tree{
	int v;
	struct tree* l;struct tree* r;
}tree;
int main()
{	int i,j,m,n,in1[1000000];
	sc(n);
	tree* hd;
	f(i,0,n){sc(pre[i]);}//hd=insert(hd,pre[i]);}
	f(i,0,n){sc(in[i]);in1[in[i]]=i;}
//	inprint(hd);
	DRT()
	{
		sc(m);sc(j);
		int a=in1[m],b=in1[j];
		f(i,0,n)if((in1[pre[i]]<=a && in1[pre[i]]>=b)||(in1[pre[i]]<=b && in1[pre[i]]>=a))
		{	printf("%d\n",pre[i]);break;}
	}
return 0;
	}

