#include <stdio.h>
#define MOD 1000000007
long long int maxc=0,minc=0;
long long int min[200010],max[200010];
long long int i=0,n=1;
/*long long multiple(long long a, long long b, long long c)
{
	if (b == 0)
	{
		return 0;
	}
	long long ret = multiple(a, b >> 1, c);
	ret = (ret + ret)%c;
	if (b & 1) 
	{
		ret = (ret + a) % c;
	}
	return ret;
}*/
long long int maxx(long long int a, long long int b)
{
	return (a > b) ? a: b;
}
long long int minn(long long int a, long long int b)
{
	return (a < b) ? a: b;
}
void minheap(long long int a[], long long int n)
{
	if (n == 1)
		return;
	else if (a[n] <= a[n/2])
	{
		long long int t = a[n];
		a[n] = a[n/2];
		a[n/2] = t;
		n /= 2;
		minheap(a,n);
	}
	else
		return;
}
void maxheap(long long int a[], long long int n)
{
	if (n == 1)
		return;
	else if (a[n] >= a[n/2])
	{
		long long int t = a[n];
		a[n] = a[n/2];
		a[n/2] = t;
		n /= 2;
		maxheap(a,n);
	}
	else
		return;
}
void deletemin(long long int a[], long long int *n1)
{
	long long int t = a[*n1];
	(*n1)--;
	long long int n = (*n1);
	long long int i = 1;
	while (2*i <= n)
	{
		long long int j = 2*i;
		if (j != n && a[j] >= t && a[j+1] >= t)
			break;
		else if (j == n && a[j] >= t)
			break;
		else
		{
			a[i] = minn(a[j],a[j+1]);
			if (a[j] < a[j+1])
				i = j;
			else
				i = j+1;
		}
	}
	a[i] = t;
}
void deletemax(long long int a[], long long int *n1)
{
	long long int t = a[*n1];
	(*n1)--;
	long long int n = (*n1);
	long long int i = 1;
	while (2*i <= n)
	{
		long long int j = 2*i;
		if (j != n && a[j] <= t && a[j+1] <= t)
		{
			break;
		}
		else if (j == n && a[j] <= t)
			break;
		else
		{
			a[i] = maxx(a[j],a[j+1]);
			if (a[j] > a[j+1])
				i = j;
			else
				i = j+1;
		}
	}
	a[i] = t;
}

void print(long long int a[], long long int n)
{
	long long int i;
	for (i = 1; i <= n; i++)
		printf("%lld ",a[i]);
	printf("\n");

}
long long int median(long long int a[])
{
	long long int med;
	if (i==0)
	{
		med = n;
		maxc++;
		max[maxc] = n;
		maxheap(max,maxc);
	}
	else if (n <= med)
	{
		maxc++;
		max[maxc] = n;
		maxheap(max,maxc);
		if (maxc-minc > 1)
		{
			long long int temp = max[1];
			deletemax(max,&maxc);
			minc++;
			min[minc] = temp;
			minheap(min,minc);
			med = max[1];
		}
	}
	else if (n > med)
	{
		minc++;
		min[minc] = n;
		minheap(min,minc);
		if (minc-maxc > 1)
		{
			long long int temp = min[1];
			deletemin(min,&minc);
			maxc++;
			max[maxc] = temp;
			maxheap(max,maxc);
			med = min[1];
		}
	}
	if (maxc >= minc) 
		med = max[1];
	if (minc > maxc)
		med = min[1]; 
	i++;
	return med;
}
int main()
{
	long long int t1;
	scanf("%lld",&t1);
	while(t1--)
	{
		maxc=0;minc=0;
		i=0;n=1;
		long long int n1;
		long long int a,b,c;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n1);
		long long int med;
		long long int f[200010];
		f[1]=1;
		long long int j;
		long long int sum=0;
		long long int tmp,tmp1,tmp2;
		a=a%MOD;
		b=b%MOD;
		c=c%MOD;
		for(j=2;j<=n1;j++)
		{
			if (i==0)
			{
				med = n;
				maxc++;
				max[maxc] = n;
				maxheap(max,maxc);
			}
			else if (n <= med)
			{
				maxc++;
				max[maxc] = n;
				maxheap(max,maxc);
				if (maxc-minc > 1)
				{
					long long int temp = max[1];
					deletemax(max,&maxc);
					minc++;
					min[minc] = temp;
					minheap(min,minc);
					med = max[1];
				}
			}
			else if (n > med)
			{
				minc++;
				min[minc] = n;
				minheap(min,minc);
				if (minc-maxc > 1)
				{
					long long int temp = min[1];
					deletemin(min,&minc);
					maxc++;
					max[maxc] = temp;
					maxheap(max,maxc);
					med = min[1];
				}
			}
			if (maxc >= minc) 
				med = max[1];
			if (minc > maxc)
				med = min[1]; 
			f[j]=med;
			i++;
			tmp1=(a*(f[j]%MOD))%MOD;
			tmp2=(b*(j%MOD))%MOD;
			f[j]=(tmp1+tmp2+c)%MOD;
			n=f[j];
			sum+=f[j];
		}
		sum+=1;
		printf("%lld\n",sum);
	}
	return 0;
}
