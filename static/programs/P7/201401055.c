#include<stdio.h>
long long int a[1000000];
void merge(long long int,long long int, long long int,long long int[]);

void partition(long long int beg,long long int end,long long int a[])
{
	long long int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		partition(beg,mid,a);
		//		printf("\n 1st part:");
		//		for(i=beg;i<=mid;i++)

		partition(mid+1,end,a);

		/*		for(i=mid+1;i<=end;i++)
				printf("%d ",a[i]);
				printf("\n");
		 */
		merge(beg,mid,end,a);
	}
}

void merge(long long int beg, long long int mid, long long int end, long long int a[])
{

	long long int l,e,m,i;
	l=beg,m=mid+1;
	i=beg;
	long long int k,c[1000000];

	while(l<=mid && m<=end)
	{
		if(a[l]<a[m])
		{
			c[i]=a[l];
			i++;l++;
		}
		else
		{
			c[i]=a[m];
			i++;m++;
		}
	}

	while(/*l>mid && */m<=end)
	{
		c[i]=a[m];
		m++;i++;
	}
	while(l<=mid /* && m<end*/)
	{
		c[i]=a[l];
		i++;l++;
	}

	for(k=beg;k<=end;k++)
	{
		a[k]=c[k];
		//		printf("%d ",a[k]);

		/*		printf("\n");
				for(k=0;k<n;k++)
				printf("%d ",a[k]);
		 */
	}
}
int main()
{
	long long int i,num,x,j,t,n,count;

	scanf("%lld",&t);
	for(j=0;j<t;j++)
	{
		num=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);

		partition(0,n-1,a);
/*		for(i=0;i<n;i++)
		printf("%lld",a[i]);
                count=0;
*/		for(i=0;i<n;)
		{
			count=0;
			x=i;
			while(a[x]==a[x+1])
			{
				count++;
				x++;
			}
			if(count>1)
			{
				count++;
				num+=(count*(count-1))/2;
			}
/*			if(count>1)
			
			num+=(count*(count-1))/2;
			else
*/				if(count==1)
					num+=1;
/*				else
					if(count>1)
						num+=(count*(count-1))/2;
			
*/			i=x+1;
		}

		printf("%lld\n",num);
	}
	return 0;
}

