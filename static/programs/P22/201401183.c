#include<stdio.h>
#define mod 1000000007
int maxheap[1000009],minheap[1000009],max,min;
void maxshuffle(int z)
{
	int large,t,ch1,ch2;
	ch1=2*z,ch2=2*z+1;
	large=z;
	if(max>=ch1&&maxheap[z]<maxheap[ch1])
		large=ch1;
	if(max>=ch2&&maxheap[large]<maxheap[ch2])
		large=ch2;
	if(z!=large)
	{
		t=maxheap[z];
		maxheap[z]=maxheap[large];
		maxheap[large]=t;
		maxshuffle(large);
	}
}
void minshuffle(int z)
{
	int small,t,ch1,ch2;
	ch1=2*z,ch2=2*z+1;
	small=z;
	if(min>=ch1&&minheap[z]>minheap[ch1])
		small=ch1;
	if(min>=ch2&&minheap[small]>minheap[ch2])
		small=ch2;
	if(z!=small)
	{
		t=minheap[z];
		minheap[z]=minheap[small];
		minheap[small]=t;
		minshuffle(small);
	}
}
int insert(int x,int y)
{
	int t,med,i,v;
	if(max==min)
	{
		if(x<y)
		{
			maxheap[++max]=x;
			for(i=max;i>1&&maxheap[i]>maxheap[i/2];i=i/2)
			{
				t=maxheap[i];
				maxheap[i]=maxheap[i/2];
				maxheap[i/2]=t;
			}
			med=maxheap[1];
		}
		else if(x>y)
		{
			minheap[++min]=x;
			for(i=min;i>1&&minheap[i]<minheap[i/2];i=i/2)
			{
				t=minheap[i];
				minheap[i]=minheap[i/2];
				minheap[i/2]=t;
			}
				med=minheap[1];
		}
		else if(x==y)
		{
			minheap[++min]=x;
			for(i=min;i>1&&minheap[i]<minheap[i/2];i=i/2)
			{
				t=minheap[i];
				minheap[i]=minheap[i/2];
				minheap[i/2]=t;
			}
				med=minheap[1];
		}
		//med=maxheap[1];
	}
	else if(max-1==min)
	{
		if(x>y)
		{
			minheap[++min]=x;
			for(i=min;i>1&&minheap[i]<minheap[i/2];i=i/2)
			{
				t=minheap[i];
				minheap[i]=minheap[i/2];
				minheap[i/2]=t;
			}
		}
		else if(x==y)
		{
			minheap[++min]=x;
			for(i=min;i>1&&minheap[i]<minheap[i/2];i=i/2)
			{
				t=minheap[i];
				minheap[i]=minheap[i/2];
				minheap[i/2]=t;
			}
		}
		else
		{
			if(max>0)
			{
			if(max==1)
			{
				v=maxheap[1];
				max=max-1;
			}
			else
			{
				v=maxheap[1];
				maxheap[1]=maxheap[max];
				max=max-1;
				maxshuffle(1);
			}
			minheap[++min]=v;
			for(i=min;i>1&&minheap[i]<minheap[i/2];i=i/2)
			{
				t=minheap[i];
				minheap[i]=minheap[i/2];
				minheap[i/2]=t;
			}
			maxheap[++max]=x;
			for(i=max;i>1&&maxheap[i]>maxheap[i/2];i=i/2)
			{
				t=maxheap[i];
				maxheap[i]=maxheap[i/2];
				maxheap[i/2]=t;
			}
			}
		}
		med=maxheap[1];
	}
	else
	{
		if(x<y)
		{
			maxheap[++max]=x;
			for(i=max;i>1&&maxheap[i]>maxheap[i/2];i=i/2)
			{
				t=maxheap[i];
				maxheap[i]=maxheap[i/2];
				maxheap[i/2]=t;
			}
		}
		else
		{
			if(min>0)
			{
			if(min==1)
			{
				min=min-1;
				v=minheap[1];
			}
			else
			{
				v=minheap[1];
				minheap[1]=minheap[min];
				min=min-1;
				minshuffle(1);
			}
			maxheap[++max]=v;
			for(i=max;i>1&&maxheap[i]>maxheap[i/2];i=i/2)
			{
				t=maxheap[i];
				maxheap[i]=maxheap[i/2];
				maxheap[i/2]=t;
			}
			minheap[++min]=x;
			for(i=min;i>1&&minheap[i]<minheap[i/2];i=i/2)
			{
				t=minheap[i];
				minheap[i]=minheap[i/2];
				minheap[i/2]=t;
			}
			}
		}
		med=maxheap[1];
	}
	return med;
}
int main()
{
	int j,n,t,i,med;
	scanf("%d",&t);
	long long int el,sum,a,b,c;
	while(t--)
	{	
		max=0,min=0,sum=1,med=0;
		scanf("%lld%lld%lld%d",&a,&b,&c,&n);
		for(i=1;i<=n;i++)
		{
			minheap[i]=0; maxheap[i]=0;
		}
		med=insert(1,0);
		for(i=2;i<=n;i++)
		{
			el=( c+(a*med)+( b*i))%mod;
			sum+=el;
			med= insert(el,med);
		}
		printf("%lld\n", sum);
	}
	return 0;
}


