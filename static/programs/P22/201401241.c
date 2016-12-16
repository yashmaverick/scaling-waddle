#include<stdio.h>
int a[200005]={0},b[200005]={0},count_min=0,count_max=0;
int insert_minheap(int val_min)
{
	count_min++;
	a[count_min]=val_min;
	int tc_min=count_min;
	while(tc_min>1&&a[tc_min]<a[tc_min/2])
	{
		int temp_min=a[tc_min];
		a[tc_min]=a[tc_min/2];
		a[tc_min/2]=temp_min;
		tc_min/=2;
	}
	return 0;
}
int delete_minheap()
{
	int tt;
	tt=a[1];
	int temp1_min=a[count_min];
	a[count_min]=a[1];
	a[1]=temp1_min;
	int x_min=1,min_min;
	count_min--;
	while(2*x_min<=count_min)
	{
		if(2*x_min==count_min&&a[2*x_min]<=a[x_min])
		{
			int temp2_min=a[x_min];
			a[x_min]=a[2*x_min];
			a[2*x_min]=temp2_min;
			x_min*=2;
		}
		else if( (2*x_min+1)<=count_min && a[2*x_min]>=a[2*x_min+1]&&a[x_min]>=a[2*x_min+1])
		{
			min_min=2*x_min+1;
			int temp2_min=a[x_min];
			a[x_min]=a[min_min];
			a[min_min]=temp2_min;
			x_min=x_min*2+1;
		}
		else if((2*x_min+1)<=count_min && a[2*x_min]<=a[2*x_min+1]&&a[x_min]>=a[2*x_min])
		{
			min_min=2*x_min;
			int temp2_min=a[x_min];
			a[x_min]=a[min_min];
			a[min_min]=temp2_min;
			x_min*=2;
		}
		else
		{
			break;
		}
	}
	return tt;
}
int insert_maxheap(int val_max)
{
	count_max++;
	b[count_max]=val_max;
	int tc_max=count_max;
	while(tc_max>1&&b[tc_max]>b[tc_max/2])
	{
		int temp_max=b[tc_max];
		b[tc_max]=b[tc_max/2];
		b[tc_max/2]=temp_max;
		tc_max/=2;
	}
	return 0 ;
}
int delete_maxheap()
{
	int tt;
	tt=b[1];
	int temp1_max=b[count_max];
	b[count_max]=b[1];
	b[1]=temp1_max;
	int x_max=1,max_max;
	count_max--;
	while(2*x_max<=count_max)
	{
		if(2*x_max==count_max&&b[x_max]<=b[2*x_max])
		{
			int temp2_max=b[x_max];
			b[x_max]=b[2*x_max];
			b[2*x_max]=temp2_max;
			x_max*=2;
		}
		else if((2*x_max+1)<=count_max && b[2*x_max]>=b[2*x_max+1]&&b[x_max]<=b[2*x_max])
		{
			max_max=2*x_max;
			int temp2_max=b[x_max];
			b[x_max]=b[2*x_max];
			b[max_max]=temp2_max;
			x_max=2*x_max;
		}
		else if((2*x_max+1)<=count_max && b[2*x_max]<=b[2*x_max+1]&&b[x_max]<=b[2*x_max+1])
		{
			max_max=2*x_max+1;
			int temp2_max=b[2*x_max+1];
			b[2*x_max+1]=b[x_max];
			b[x_max]=temp2_max;
			x_max=2*x_max+1;
		}
		else
		{
			break;
		}
	}
	return tt;
}
int main()
{
	long long int aa,bb,cc;
	int ne;
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%d",&aa,&bb,&cc,&n);
		long long int sum;
		ne=1;
		sum=1;
		int med=1;
		count_max=0;
		count_min=0;
		insert_maxheap(1);
		for(i=2;i<=n;i++)
		{
			ne=(((aa*med)%1000000007+(bb*i)%1000000007)%1000000007 + cc)%1000000007;
			sum+=ne;
			if(ne<=med)
				insert_maxheap(ne);
			else
				insert_minheap(ne);

			if( (count_max-count_min)>1 )
				insert_minheap(delete_maxheap());
			if(count_min-count_max>0)
				insert_maxheap(delete_minheap());
			med=b[1];
		}
		printf("%lld\n",sum);
	}
	return 0 ;
}
