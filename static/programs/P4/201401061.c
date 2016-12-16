#include<stdio.h>
#include<string.h>
void insertionsort(int *d,int);
void swap(int *c,int *b);
//void quicksort(int [],int,int);
int median(int [],int,int);
void qsort(int [],int,int);
int main()
{
        int t,i,a[100000],j=0,sum,n,count,x;
	char s[100001];
	scanf("%d",&t);
	while(j<t)
	{
		sum=0;
		scanf("%s",s);
		n=strlen(s);
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='J')
			{
				sum+=100005;
				a[i]=sum;
				//printf("%d",a[i]);
			}
			else if(s[i]=='M')
			{
				sum+=(-5);
				a[i]=sum;
				//printf("%d",a[i]);
			}
			else
			{
				sum+=(-100000);
				a[i]=sum;
				//printf("%d",a[i]);
			}
		}
		sum=0;
		qsort(a,0,n-1);
		for(i=0;i<n;)
		{
		        count=1;
		        x=i;
		        while(a[x]==a[x+1]&&x<n-1)
		        {
		              count++;
		              x++;
		        }
		        /*if(count>0)
		                count++;*/
			sum+=((count*(count-1))/2);
			if(a[i]==0)
				sum+=count;
		        i=x+1;
		}
			
        printf("%d\n",sum);
		
	j++;
	}
	return 0;
}

void swap(int *c,int *b)
{
	int temp;
	temp=*c;
	*c=*b;
	*b=temp;
}

/*void quicksort(int a[100],int n,int k)
{
	qsort(a,0,n-1,k);
}*/

int median(int a[100],int l,int r)
{
	int mid=(l+r)/2;
	if(a[l]>a[mid])
		swap(&a[l],&a[mid]);
	if(a[l]>a[r])
		swap(&a[l],&a[r]);
	if(a[mid]>a[r])
		swap(&a[mid],&a[r]);
	swap(&a[mid],&a[r-1]);
	return a[r-1];
}

void qsort(int a[100],int l,int r)
{
	int i,j;
	int pivot;

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

void insertionsort(int *d,int n)
{
	int j,p;
	int tmp;
	for(p=1;p<n;p++)
	{
		tmp=d[p];
		for(j=p;j>0&&d[j-1]>tmp;j--)
			d[j]=d[j-1];
		d[j]=tmp;
	}
	//return (d[k-1]);
}
