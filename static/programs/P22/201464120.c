#include<stdio.h>
long long int H[1000010];
long long int maxh[1000010];
long long int k=0;
long long int k1=0;
void insertmin(int element)
{
	k++;
	H[k] = element; 
	
	long long int now = k;
	while(H[now/2] > element) 
	{
		H[now] = H[now/2];
		now /= 2;
	}
	H[now] = element;
}
void insertmax(int element)
{
	k1++;
	if(k1==1)
	{
		maxh[0]=10000000000000000;
		maxh[1]=element;
		return;
	}
	maxh[k1] = element; 
	
	long long int now = k1;
	while(maxh[now/2] < element) 
	{
		maxh[now] = maxh[now/2];
		now /= 2;
//		printf("%d now\t",now);
	}
	maxh[now] = element;
//	printf("%d\t",element);
	return;
}
long long int deletemin()
{
	long long int min,last,child,now;
	min=H[1];
	last=H[k--];
	for(now=1;now*2<= k;now=child)
	{
		child=now*2;
		if(child!= k && H[child+1] < H[child])
			child++;
		if(last>H[child])
			H[now]=H[child];
		else
			break;
	}
	H[now]=last;
	return min;
}
long long int deletemax()
{
	long long int max,last,child,now;
	max=maxh[1];
	last=maxh[k1--];
	for(now=1;now*2<= k1;now=child)
	{
		child=now*2;
		if(child!= k1 && maxh[child+1] > maxh[child])
			child++;
		if(last<maxh[child])
			maxh[now]=maxh[child];
		else
			break;
	}
	maxh[now]=last;
	return max;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
	k1=0;
	k=0;
	long long int n,x,i,m,f1=1,f2,f,sum=0,a,b,c;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
	f2= (a + 2*b + c)%1000000007;
	if(f1<=f2)
	{
		insertmax(f1);
		insertmin(f2);
	}
	else
	{
		insertmax(f2);
		insertmin(f1);
	}	
	sum=f1;
	if(n!=1)
		sum+=f2;
	for(i=3;i<=n;i++)
	{
		if(k1==k)
			m=maxh[1];
		else if(k1-k==1)
			m=maxh[1];
		else if(k-k1==1)
			m=H[1];
		else if(k-k1==2)
		{
			x=deletemin();
			insertmax(x);
			m=maxh[1];
		}
		else if(k1-k==2)
		{
			x=deletemax();
			insertmin(x);
			m=maxh[1];
		}
		f=(a*m+b*i+c)%1000000007;
		sum+=f;
		if(f<m)
			insertmax(f);
		else
			insertmin(f);
	}
	printf("%lld\n",sum);
	test--;
	}
	
	return 0;
}
