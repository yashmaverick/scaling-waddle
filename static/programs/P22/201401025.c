#include<stdio.h>

long long int min_heap[200004],min_end=0;

void insert_min(long long int a)
{
	min_end++;
	min_heap[min_end]=a;

	long long int c,f,temp;

	c=min_end;
	f=c/2;

	while(min_heap[f]>min_heap[c])
	{
		if(f<1)
			break;

		temp=min_heap[f];
		min_heap[f]=min_heap[c];
		min_heap[c]=temp;

		c=f;
		f=c/2;
	}
}

long long int max_heap[200004],max_end=0;

void insert_max(long long int a)
{
	max_end++;
	max_heap[max_end]=a;

	long long int c,f,temp;

	c=max_end;
	f=c/2;

	while(max_heap[f]<max_heap[c])
	{
		if(f<1)
			break;

		temp=max_heap[f];
		max_heap[f]=max_heap[c];
		max_heap[c]=temp;

		c=f;
		f=c/2;
	}
}


void delete_min()
{
	min_heap[1]=min_heap[min_end];
	min_end--;

	long long int f,c1,c2,temp,small;

	f=1;
	c1=f*2;
	c2=f*2+1;

	if(c2>min_end)
		min_heap[c2]=min_heap[c1]+1;

	while(min_heap[f]>min_heap[c1] || min_heap[f]>min_heap[c2])
	{
		if(c1>min_end)
			break;

		if(min_heap[c1]>min_heap[c2])
			small=c2;
		else
			small=c1;

		temp=min_heap[f];
		min_heap[f]=min_heap[small];
		min_heap[small]=temp;

		f=small;
		c1=f*2;
		c2=f*2+1;

		if(c2>min_end)
			min_heap[c2]=min_heap[c1]+1;
	}
}

void delete_max()
{
	max_heap[1]=max_heap[max_end];
	max_end--;

	long long int f,c1,c2,temp,big;

	f=1;
	c1=f*2;
	c2=f*2+1;

	if(c2>max_end)
		max_heap[c2]=max_heap[c1];

	while(max_heap[f]<max_heap[c1] || max_heap[f]<max_heap[c2])
	{
		if(c1>max_end)
			break;

		if(max_heap[c1]>=max_heap[c2])
			big=c1;
		else
			big=c2;

		temp=max_heap[f];
		max_heap[f]=max_heap[big];
		max_heap[big]=temp;

		f=big;
		c1=f*2;
		c2=f*2+1;

		if(c2>max_end)
			max_heap[c2]=max_heap[c1];
	}
}


int main()
{
	long long int n,i,j,a[200003],m[200003];
	long long int A,B,C,t;
	long long int ans,mod=1000000007;

	scanf("%lld",&t);
	while(t>0)
	{
		t--;
		max_end=0;
		min_end=0;

		scanf("%lld%lld%lld%lld",&A,&B,&C,&n);

		a[1]=1;
		m[2]=1;
		ans=1;
		insert_max(a[1]);


		for(i=2;i<=n;i++)
		{
			a[i]=(A*m[i] + B*i + C )%mod;
			ans=ans+a[i];

			if( a[i]>m[i] )
			{
				insert_min(a[i]);
				if(min_end==max_end)
					m[i+1]=max_heap[1];
				else if(min_end==max_end+1)
					m[i+1]=min_heap[1];
				else
				{
					insert_max(min_heap[1]);
					delete_min();
					m[i+1]=max_heap[1];
				}
			}
			else
			{
				insert_max(a[i]);
				if(max_end==min_end)
					m[i+1]=max_heap[1];
				else if(max_end==min_end+1)
					m[i+1]=max_heap[1];
				else
				{
					insert_min(max_heap[1]);
					delete_max();
					m[i+1]=max_heap[1];
				}
			}
		}

		printf("%lld\n",ans);
	}
	return 0;
}
