#include<stdio.h>
long long int minsize=0;
long long int maxsize=0;
long long int minheap[1000001],maxheap[1000001];
long long int kk,ll,mm,ii;
long long int mdn[1000001],ind;
long long int sum[1000001];
long long int ans=0;
#define CONST 1000000007
void insertmin(long long int m)
{
	minsize++;
	minheap[minsize]=m;
	long long int jj,temp;
	jj=minsize;
	while(jj!=1 && minheap[jj] < minheap[jj>>1])
	{
		temp=minheap[jj];
		minheap[jj]=minheap[jj>>1];
		minheap[jj>>1]=temp;
		jj=jj>>1;
	}
}
long long int deletemin()
{
	long long int last,kk;
	kk=minheap[1];
	minheap[1]=minheap[minsize];
	minsize--;
	last=minsize;
	long long int j,k,l;
	for(j=1;2*j<=last;j=k)
	{
		k=2*j;
		if(k<last && minheap[k]>minheap[k+1])
			k++;
		if(minheap[j]>minheap[k])
		{
			minheap[j]=minheap[k]+minheap[j]-(minheap[k]=minheap[j]);
		}
	}
	return kk;

}
long long int mintop()
{
	if(minsize==0)
		return -1;
	return minheap[1];
}
long long int maxtop()
{
	if(maxsize==0)
		return -1;
	return maxheap[1];
}
void insertmax(long long int m)
{
	maxsize++;
	maxheap[maxsize]=m;
	long long int jj=maxsize;
	long long int temp;
	while(jj!=1 && maxheap[jj] > maxheap[jj>>1])
	{
		temp=maxheap[jj];
		maxheap[jj]=maxheap[jj>>1];
		maxheap[jj>>1]=temp;
		jj=jj>>1;
	}
}
long long int deletemax()
{
	long long int last,fg;
	fg=maxheap[1];
	maxheap[1]=maxheap[maxsize];
	(maxsize)--;
	last=(maxsize);
	long long int j,k,l;
	for(j=1;2*j<=last;j=k)
	{
		k=2*j;
		if(k < last && maxheap[k] < maxheap[k+1])
			k++;
		if(maxheap[j] < maxheap[k])
		{
			maxheap[j]=maxheap[k]+maxheap[j]-(maxheap[k]=maxheap[j]);
		}
	}
	return fg;
}
void compute()
{
	long long int l,k,j,m,n,g;
	sum[1]=1;
	ind=1;
	ans=1;
	while(ind<ii)
	{
		l=(minsize-maxsize);
		if(minsize==0 && maxsize==0)
			insertmin(1);
		else
		{
			g=sum[ind];
			switch(l)
			{
				case 0 :
					k=mintop();
					if(g < k)
					{
						insertmax(g);
					}
					else
					{
						insertmin(g);
					}
					break;
				case 1 :
					k=mintop();
					if(g < k)
						insertmax(g);
					else
					{
						n=deletemin();
						insertmin(g);
						insertmax(n);
					}
					break;
				case -1 :
					k=maxtop();
					if(g < k)
					{
						n=deletemax();
						insertmax(g);
						insertmin(n);
					}
					else
						insertmin(g);
					break;
			}
		}
		ind++;
		l=(minsize-maxsize);
		if(l==1)
			mdn[ind]=minheap[1];
		else
			mdn[ind]=maxheap[1];
		sum[ind] = ((((kk*mdn[ind])%CONST)+((ll*ind)%CONST)+(mm))%CONST);
		//	printf("mdn[ind]:%d sum[ind[:%d\n",mdn[ind],sum[ind]);
		ans+=sum[ind];
		j++;
	}
	maxsize=0;
	minsize=0;
	return ; 
}
int main()
{
	long long int j,k,l,m,i,c,v;
	scanf("%lld",&v);
	while(v>0)
	{
		scanf("%lld %lld %lld %lld",&kk,&ll,&mm,&ii);
		compute();
		printf("%lld\n",ans);
		v--;
	}
	return 0;
}


