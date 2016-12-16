#include<stdio.h>
long long int max[200002],min[200002],f[200002],minsize,maxsize,median=1;
void insertmin(long long int a)
{
	minsize++;
	long long int r=minsize,temp;
	min[r]=a;
	while(r>1)
	{
		//printf("r %d min size %d\n",r,minsize);
		if(min[r]<min[r/2])
		{
			temp=min[r];
			min[r]=min[r/2];
			min[r/2]=temp;
			r=r/2;
		}
		else
			return ;
	}
}
void insertmax(long long int a)
{
	maxsize++;
	long long int r=maxsize,temp;
	max[r]=a;
	while(r>1)
	{
		//printf("r %d max size %d\n",r,maxsize);
		if(max[r]>max[r/2])
		{
			temp=max[r];
			max[r]=max[r/2];
			max[r/2]=temp;
		r=r/2;
		}
		else
			return ;
	}
}
int removemin()
{
	long long int o=min[1];
	min[1]=min[minsize];
	minsize--;
	long long int p=1,temp;
	while(p<=minsize/2)
	{
		//printf("in del p %d min size %d\n",p,minsize);
		if(2*p==minsize)
		{
			//printf("entered 1\n");
			if(min[p]>min[2*p])
			{
				temp=min[2*p];
				min[2*p]=min[p];
				min[p]=temp;
				p=2*p;
			}
			return o;
		}
		else if( (2*p+1<=minsize) && min[2*p]<min[p]||min[2*p+1]<min[p])
		{
			if(min[2*p]>min[2*p+1])
			{
			//printf("entered 2\n");
					temp=min[2*p+1];
					min[2*p+1]=min[p];
					min[p]=temp;
					p=2*p+1;
			}
			else
			{
			//printf("entered 3\n");
					temp=min[2*p];
					min[2*p]=min[p];
					min[p]=temp;
					p=2*p;
			}
		}
		else return o;
	}
	return o;
}
int removemax()
{
	long long int o;
	o=max[1];
	max[1]=max[maxsize];
	maxsize--;
	long long int p=1,temp;
	while(p<=maxsize/2)
	{	  
		//printf("in del p %d max size %d\n",p,maxsize);
		if (2*p==maxsize)
		{
			if(max[p]<max[2*p])
			{
				temp=max[2*p];
				max[2*p]=max[p];
				max[p]=temp;
				p=2*p;
			}
			return o;
		}	
		else if((2*p+1<=maxsize) && max[2*p]>max[p]||max[2*p+1]>max[p])
		{
			if(max[2*p]>max[2*p+1])
			{
					temp=max[2*p];
					max[2*p]=max[p];
					max[p]=temp;
					p=2*p;
			}
			else
			{
					temp=max[2*p+1];
					max[2*p+1]=max[p];
					max[p]=temp;
					p=2*p+1;
			}
		}
		else return o;
	}
	return o;
}
int main()
{
	long long int t,i;
	scanf("%lld",&t);
	while(t--)
	{
		long long int a,b,c,n,m,ans=0,r;
		median=1;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		minsize=0;
		f[1]=1;
		max[1]=1;
		maxsize=1;
		ans=1;
		median=1;
		for(i=2;i<=n;i++)
		{
			f[i]=(a*median+(b*i)+c)%1000000007;
			if(f[i]>median)
				insertmin(f[i]);
			else
				insertmax(f[i]);
			if(maxsize+1==minsize)
				median=min[1];
			else
			{
				if(maxsize+1<minsize)
					insertmax(removemin());
				else if(minsize+1<maxsize)
					insertmin(removemax());
				median=max[1];
			}
			ans+=f[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
