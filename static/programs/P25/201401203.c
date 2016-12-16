#include<stdio.h>
#define ll long long int
typedef struct edge
{
	int x,y;
	ll wt;
}edge;

typedef struct node
{
	int h,p;
}node;
edge a[1000001],c[1000001];
node b[100001];

void divide(int beg,int end)
{
	int mid,i,j,k;
	if(beg>=end)
		return;
	mid=(beg+end)/2;
	divide(beg,mid);
	divide(mid+1,end);
	//merge
	i=beg;j=mid+1;
	k=0;
	while(i<=mid&&j<=end)
	{
		if(a[i].wt>a[j].wt)
		{
			c[k++]=a[j];
			j++;
		}
		else
		{
			c[k++]=a[i];
			i++;
		}
	}
	while(i<=mid)
	{
		c[k++]=a[i];
		i++;
	}
	while(j<=end)
	{
		c[k++]=a[j];
		j++;
	}
	k=0;
	for(i=beg;i<=end;i++)
		a[i]=c[k++];
}

void merge(int x,int y)
{
	/*while(b[x].p!=x)
		x=b[x].p;
	while(b[y].p!=y)
		y=b[y].p;*/
	x=find(x);
	y=find(y);
	if(b[x].h>b[y].h)
	{
		b[y].p=x;
	//	printf("s\n");
	}
	else if(b[x].h<b[y].h)
	{
	//	printf("w\n");
		b[x].p=y;
	}
	else
	{
	//	printf("q\n");
		b[y].p=x,b[x].h+=1;
	}
}

int find(int x)
{
/*	if(b[x].p==x)
		return x;
	b[x].p=find(b[x].p);
*//*	while(b[x].p!=x)
		x=b[x].p;
	return x;*/
	if(b[x].p!=x)
		b[x].p=find(b[x].p);
	return b[x].p;
}

int main()
{
	int i,j,n,m,c;
	ll sum=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d %lld",&a[i].x,&a[i].y,&a[i].wt);
	divide(1,m);
	for(i=1;i<=n;i++)
	{
		b[i].h=0;
		b[i].p=i;
	}
	c=1;
	for(i=1;i<=m&&c<=n-1;i++)
	{
	//	printf("p %d %d\n",find(a[i].x),find(a[i].y));
		if(find(a[i].x)!=find(a[i].y))
		{
			merge(a[i].x,a[i].y);
/*			for(j=1;j<=n;j++)
				printf("%d %d\n",j,b[j].p);
*/			sum+=a[i].wt;
			c++;	
		}
		//printfn("p1 %d %d\n",find(a[i].x),find(a[i].y));
	}
	/*for(i=1;i<=n;i++)
		if(b[i].h==0&&b[i].p==i)
		{
			printf("-1\n");
			return 0;
		}*/
	if(c==n)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}	

