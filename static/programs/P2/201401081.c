#include<stdio.h>
#define SIZE 100005

long int a[SIZE],b[SIZE],c[SIZE],d[SIZE],sum;
int p,q,r;
int j;

void print_arr()
{
	long int i;
	for(i=0;i<p;i++)
		printf("%ld ",a[i]);
	printf("\n");
	for(i=0;i<q;i++)
		printf("%ld ",b[i]);
	printf("\n");
	for(i=0;i<r;i++)
		printf("%ld ",c[i]);
	printf("\n");
}

int first_pos(long int key)
{
	if(a[0]>key)
		return 0;
	int beg,mid,end;
	beg=0;
	end=j;
	mid=(beg+end)/2;
	while(beg<end)
	{
		mid=(beg+end)/2;
		if(c[mid]<key)
			end=mid;
		else if(c[mid]>key)
			beg=mid+1;
		else
			return mid;
	}
	return j;
}

int third_pos(long int array[],long int key,int beg,int end)
{  
	if(array[r-1]<key)
		return r;
	int mid;
	end=end-1;

	mid=(beg+end)/2;
	while(beg<end)
	{
		mid=(beg+end)/2;
		if(array[mid]>key)
			end=mid;
		else if(array[mid]<key)
			beg=mid+1;
		else
			return mid;
	}
	return end;
}

int main()
{
	int t;
	int i,k;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&p);
		for(i=0;i<p;i++)
			scanf("%ld",&a[i]);
		scanf("%d",&q);
		for(j=0;j<q;j++)
			scanf("%ld",&b[j]);
		scanf("%d",&r);
		for(k=0;k<r;k++)
			scanf("%ld",&c[k]);
		//printf("%d %d %d\n",p,q,r);
		if(q>r)
			q=r;
		if(p>q)
			p=q;
		d[q]=0;
		for(j=q-1;j>=0;j--)
		{
			i=third_pos(b,a[j],j,q);
			k=third_pos(c,b[j],j,r);
			//printf("i=%d j=%d k=%d sum=%ld\n",i,j,k,sum);
			k=r-k;
			d[j]=d[j+1]+k;
			sum+=d[i];
		}

		printf("%ld\n",sum);
	}
	return 0;
}

