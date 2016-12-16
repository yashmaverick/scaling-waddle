#include<stdio.h>
#include<stdlib.h>
#define rep(i,j,n) for(i=j;i<n;i++)
int weights[1000001];
typedef struct info
{
	int weight;
	int begin;
	int end;
}info;
void in(int *address)
{
	scanf("%d",address);
}
void out(int *val)
{
	printf("%d\n",*val);
}
void newl()
{
	printf("\n");
}
info *a;
int main()
{
	int n,i,mod,k,prev=0,j=0,sum,x,size;
	in(&n);
	in(&mod);
	a=(info*)malloc(n*sizeof(info));
	rep(i,0,n)
	{
		in(&size);
		a[i].begin=j;
		sum=0;
		rep(k,0,size)
		{
			in(&weights[j]);
			sum=(sum%mod+weights[j]%mod)%mod;
			j++;
		}
		a[i].end=j;
		a[i].weight=sum%mod;
	}
	info temp;
	rep(i,1,n)
	{
		rep(j,0,n - 1) 
		{
			if (a[j].weight > a[j + 1].weight)
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	rep(i,0,n)
	{
		out(&a[i].weight);
		rep(j,a[i].begin,a[i].end) out(&weights[j]); newl();
	}
	return 0;
}
