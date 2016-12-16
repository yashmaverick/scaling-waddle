#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
# define M 1000000007
long long maxcount,mincount;
void insertmin(long long int a,long long int minheap[])
{
	long long int i,parent,temp;
	mincount++;
	minheap[mincount]=a;
	i=mincount;
	while(i>1)
	{
		parent=i/2;
		if(minheap[i]<minheap[parent])
		{
			temp=minheap[i];
			minheap[i]=minheap[parent];
			minheap[parent]=temp;
			i=parent;
		}
		else return;
		
	}
	return;
}
void insertmax(long long int a,long long int maxheap[])
{
	long long int i,parent,temp;
	maxcount++;
	maxheap[maxcount]=a;
	i=maxcount;
	while(i>1)
	{
		parent=i/2;
		if(maxheap[i]>maxheap[parent])
		{
			temp=maxheap[i];
			maxheap[i]=maxheap[parent];
			maxheap[parent]=temp;
			i=parent;
		}
		else return;
	}
	return;
}
long long int deletemin(long long int minheap[])
{
	if(mincount<=0)
		return 0;

	long long int minindex,i,temp,min;
	min=minheap[1];
	minheap[1]=minheap[mincount];
	mincount--;
	i=1;
	while(((2*i)<=mincount && (minheap[i]>minheap[2*i])) || ((((2*i)+1)<=mincount) && (minheap[i]>minheap[(2*i)+1])))
	{
		if(minheap[2*i]<=minheap[(2*i)+1])
			minindex=2*i;
		else minindex=((2*i)+1);
		if(minheap[i]>minheap[minindex])
		{
			temp=minheap[i];
			minheap[i]=minheap[minindex];
			minheap[minindex]=temp;
			i=minindex;
		}
		else break;
	}
	return min;
}
long long int deletemax(long long int maxheap[])
{
	if(maxcount<=0)
		return 0;
	long long int maxindex,i,temp,max;
	max=maxheap[1];
	maxheap[1]=maxheap[maxcount];
	maxcount--;
	i=1;
	while((((2*i)<=maxcount) && maxheap[i]<maxheap[(2*i)]) || ((((2*i)+1)<=maxcount) && maxheap[i]<maxheap[(2*i)+1]))
	{
		if(maxheap[(2*i)]>=maxheap[(2*i)+1])
			maxindex=(2*i);
		else maxindex=((2*i)+1);
		if(maxheap[i]<maxheap[maxindex])
		{
			temp=maxheap[i];
			maxheap[i]=maxheap[maxindex];
			maxheap[maxindex]=temp;
			i=maxindex;
		}
		else break;
	}
	return max;
}


int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		mincount=0;
		maxcount=0;
		long long int a,b,c,n,i,j,temp1,temp2,temp,ans,maxheap[300005],minheap[300005];
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		temp=1;
		ans=1;
		minheap[0]=-INT_MAX;
		maxheap[0]=INT_MAX;
		insertmax(1,maxheap);
		for(i=2;i<=n;i++)
		{
			if(maxcount>=mincount)
			temp=((a*maxheap[1])+(b*i)+c)%M;
			else temp=((a*minheap[1])+(b*i)+c)%M;
			ans=ans+temp;
			insertmax(temp,maxheap);
			if(maxcount-mincount>1 || (mincount!=0 && maxheap[1]>minheap[1]))
			{
				temp1=deletemax(maxheap);
				insertmin(temp1,minheap);
			}
			//	if((maxcount+mincount)==0)
			//		continue;
				if(mincount-maxcount>1 && mincount!=0)
				{
					temp1=deletemin(minheap);
				//	temp2=deletemin(minheap);
				//	insertmax(temp2,maxheap);
					insertmax(temp1,maxheap);
				}
		//	insertmax(temp,maxheap);
		}
		printf("%lld\n",ans);
	}
	return 0;
}





