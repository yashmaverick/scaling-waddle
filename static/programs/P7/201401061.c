#include<stdio.h>
void insertionsort(long long int *d,long long int);
void swap(long long int *c,long long int *b);
//void quicksort(int [],int,int);
long long int median(long long int [],long long int,long long int);
void qsort(long long int [],long long int,long long int);
int main()
{
        long long int t,i,a[1000000],j=0,s,count;
	long long int x,n;
	scanf("%lld",&t);
	while(j<t)
	{
		s=0;
		scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	//quicksort(a,n,k);
	qsort(a,0,n-1);
	//for(i=0;i<n;i++)
	//	printf("%d ",a[i]);
	for(i=0;i<n;)
	{
		count=0;
		x=i;
		while(a[x]==a[x+1]&&x<n-1)
		{
			count++;
			x++;
		}
		if(count>0)
			count++;
                s+=((count*(count-1))/2);
		i=x+1;
	}
	printf("%lld\n",s);
	j++;
	}
	return 0;
}

void swap(long long int *c,long long int *b)
{
	long long int temp;
	temp=*c;
	*c=*b;
	*b=temp;
}

/*void quicksort(int a[100],int n,int k)
{
	qsort(a,0,n-1,k);
}*/

long long int median(long long int a[100],long long int l,long long int r)
{
	long long int mid=(l+r)/2;
	if(a[l]>a[mid])
		swap(&a[l],&a[mid]);
	if(a[l]>a[r])
		swap(&a[l],&a[r]);
	if(a[mid]>a[r])
		swap(&a[mid],&a[r]);
	swap(&a[mid],&a[r-1]);
	return a[r-1];
}

void qsort(long long int a[100],long long int l,long long int r)
{
	long long int i,j;
	long long int pivot;

	if(l+3<=r)
	{
		pivot=median(a,l,r);
		i=l;
		j=r-1;
		for(;;)
		{
			while(a[++i]<pivot){}
			while(a[--j]>pivot){}
			if(i<j)
				swap(&a[i],&a[j]);
			else
				break;
		}
		swap(&a[i],&a[r-1]);
		/*if(k-1==i)
			return a[pivot];*/
		//if(k-1<i)
		qsort(a,l,i-1);
		//else
		qsort(a,i+1,r);
	}
	else
		insertionsort(a+l,r-l+1);
}

void insertionsort(long long int *d,long long int n)
{
	long long int j,p;
	long long int tmp;
	for(p=1;p<n;p++)
	{
		tmp=d[p];
		for(j=p;j>0&&d[j-1]>tmp;j--)
			d[j]=d[j-1];
		d[j]=tmp;
	}
	//return (d[k-1]);
}
