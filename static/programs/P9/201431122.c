#include<stdio.h>
#include<stdlib.h>
typedef struct bag
{
	int *we;
	int m;
}bag;
typedef struct addr{
	int w;
	int in;
}adr;

bag b[1007];
adr a[1007];
/*void merg( adr as[], int s, int e)
{
	if(s==e)
		return;
		int mid = (s+e)/2;
	 int t1=s;
	 int t2 = (s+e)/2+1;
	merg(as,s,mid);
	merg(as,t2,e);
	 adr  temp[10000];
	     int t=0;
	while(t1<=mid || t2<=e)
	{
		if(t1>mid)
		{
			temp[t].w = as[t2].w;
			temp[t].in=as[t2].in;
			t++;
			t2++;
		}
		else if(t2>e)
		{
			temp[t].w = as[t1].w;
			temp[t].in = as[t1].in;
			t1++;
			t++;
		}
		else
		{
			if(as[t1].w<as[t2].w)
			{
				temp[t].w = as[t1].w;
				temp[t].in= as[t1].in;
				t++;
				t1++;
			}
			else if (as[t1].w>as[t2].w)
			{
				temp[t].w = as[t2].w;
				temp[t].in = as[t2].in;
				t++;
				t2++;
			}
			else
			{
				temp[t].w = as[t1].w;
				temp[t].in= as[t1].in;
				t++;
				t1++;
			}
		}
	}
	 int i;
	for(i=0;i<t;i++)
	{
		as[s+i].w=temp[i].w;
		as[s+i].in=temp[i].in;
	}
}*/

int cmp(const void * p,const void * q)
{
	int l = ((adr *)p)->w;
	int r = ((adr *)q)->w;
	return (l-r);
}
int main()
{
	int s,m,t,i,j,mod;
	int n;
	scanf("%d%d",&n,&mod);
	for(i=0;i<n;i++)
		a[i].in=i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i].m);
		s=0;
		b[i].we = malloc(sizeof(int)*b[i].m);
		for(j=0;j<b[i].m;j++)
		{
			scanf("%d",&b[i].we[j]);
			s = (s%mod+b[i].we[j]%mod)%mod;
		}
		a[i].w=s;
	}
 	qsort(a,n,sizeof(adr),cmp);
//	merg(a,0,n-1);
/*	for(i=0;i<n;i++)
		printf("a %d m %d\n",a[i].in,b[a[i].in].m);
	printf("\n");*/
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i].w);
		for(j=0;j<b[a[i].in].m;j++)
			printf("%d\n",b[a[i].in].we[j]);
		printf("\n");
	}
	return 0;
}
