#include<stdio.h>
typedef long long int lli;
lli length=0;
lli length1=0;
lli h[10000001]={0};
lli h1[10000001]={0};
//lli med[10000001]={0};
//lli f[100000001]={0};
void shufd(lli);
void heapify(lli);
void shufd1(lli);
void heapify1(lli);
lli delmax();
lli delmin();
lli calculate(lli a,lli b,lli c,lli n)
{
	lli i=0,j=0,tmp=0,sum=1,med=1,f=0;
	for(i=2;i<=n;i++)
	{
		med=h1[1];
		f=((a*med)%1000000007+(b*i)%1000000007+(c)%1000000007)%1000000007;
		sum=(sum+f);
		if(f<med)
		{
			heapify1(f);
			length1++;
		}
		else
		{
			heapify(f);
			length++;
		}
		if((length1-length)>1)
		{
			tmp=delmax();
			heapify(tmp);
			length++;
		}
		else if((length-length1)>0)
		{
			tmp=delmin();
			heapify1(tmp);
			length1++;
		}
		//printf("length-->%lld length1-->%lld SUM-->%lld\n",length,length1,sum);
	}
	return sum;
}
int main()
{
	lli t,a,b,c,n,x;
	scanf("%lld",&t);
	while(t--)
	{
		x=0;
		length=0;
		length1=1;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		h1[1]=1;
		if(n==1)
			printf("1\n");
		else
			printf("%lld\n",calculate(a,b,c,n));
	}
	return 0;
}
void shufd(lli x)
{
	lli min=1,tmp=0;
	lli i=1;
	while(i>=1 && 2*i<=length && ((h[i]>h[2*i]) || (h[i]>h[2*i+1])))
	{
		tmp=h[i];
		if(h[2*i]<h[2*i+1])
		{
			h[i]=h[2*i];
			h[2*i]=tmp;
			min=2*i;
		}
		else
		{
			h[i]=h[2*i+1];
			h[2*i+1]=tmp;
			min=2*i+1;
		}
		i=min;
	}
	return;
}
void shufd1(lli x)
{
	lli max=1,tmp=0;
	lli i=1;
	while(i>=1 && 2*i<=length1 && ((h1[i]<h1[2*i]) || (h1[i]<h1[2*i+1])))
	{
		tmp=h1[i];
		if(h1[2*i]>h1[2*i+1])
		{
			h1[i]=h1[2*i];
			h1[2*i]=tmp;
			max=2*i;
		}
		else
		{
			h1[i]=h1[2*i+1];
			h1[2*i+1]=tmp;
			max=2*i+1;
		}
		i=max;
	}
	return;
}
void heapify(lli x)
{
	lli i=0,flag=0,par=1,tmp=0;
	h[length+1]=x;
	lli k=length+1;
	while(k>1)
	{
		par=k/2;
		if(h[par]>h[k])
		{
			tmp=h[par];
			h[par]=h[k];
			h[k]=tmp;
			k=par;
		}
		else
			break;
	}
	return;
}
void heapify1(lli x)
{
	lli i=0,flag=0,par=1,tmp=0;
	h1[length1+1]=x;
	lli k=length1+1;
	while(k>1)
	{
		par=k/2;
		if(h1[par]<h1[k])
		{
			tmp=h1[par];
			h1[par]=h1[k];
			h1[k]=tmp;
			k=par;
		}
		else
			break;
	}
	return;
}
lli delmax()
{
	lli max=h1[1];
	h1[1]=h1[length1];
	length1--;
	shufd1(h1[1]);
	return max;
}
lli delmin()
{
	lli min=h[1];
	h[1]=h[length];
	length--;
	shufd(h[1]);
	return min;
}
