#include<stdio.h>
#include<stdlib.h>
#define MAX 1000005
typedef struct node
{
	int p;
	int q;
	int r;
}node;
node a[1001];
int b[MAX];
int partition(int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		partition(l,m);
		partition(m+1,h);
		merge_sort(l,m,h);
	}
}
int merge_sort(int l,int m,int h)
{
	int  z,i,y,k;
	node t[h+1];
	i=l;
	z=l;
	y=m+1;
	while(z<=m && y<=h)
	{
		if(a[z].p<a[y].p)
		{
			t[i++]=a[z++];


		}
		else if(a[z].p>a[y].p)
		{
			t[i++]=a[y++];
		}
		else
		{
			t[i++]=a[z++];
			t[i++]=a[y++];
		}

	}
	while(z<=m)
		t[i++]=a[z++];
	while(y<=h)
		t[i++]=a[y++];
	for(k=l;k<=h;k++)
	{
		a[k]=t[k];
	}


}

int main()
{
	int n,mod,i,j,k,s,sum,m,l;
	k=0;
	scanf("%d%d",&n,&mod);
	for(j=0;j<n;j++)
	{	sum=0,l=0;
		scanf("%d",&m);
		a[j].q=k;
		for(i=k;i<(k+m);i++)
		{
			scanf("%d",&b[i]);
			l++;
			sum=(sum+b[i])%mod;
		}
		k=k+l;
		a[j].r=k;
		a[j].p=sum;
	}
	partition(0,n-1);
	for(i=0;i<n;i++){
		s=a[i].p;
		printf("%d\n",s);
		for(j=a[i].q;j<a[i].r;j++){
			printf("%d\n",b[j]);
		}
		printf("\n");
	}
	return 0;
}






