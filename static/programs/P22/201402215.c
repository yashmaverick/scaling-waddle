#include<stdio.h>
long long int  minheap[100002],maxheap[100002],mid[200001];
long long int end1=1,end2=1;
long long int a,b,c,n;
long long int min(long long int j)
{
	if(minheap[2*j]>minheap[2*j+1])
		return 2*j+1;
	else
		return 2*j;
}
void shuffledownminheap(long long int j)
{
	long long int temp,k;
	if(2*j+1<=end1-1)
	{
		k=min(j);
		if(minheap[j]>minheap[k])
		{
			temp=minheap[k];
			minheap[k]=minheap[j];
			minheap[j]=temp;
			shuffledownminheap(k);
		}
		else
			return ;
	}
	else if(2*j==end1-1)
	{
		if(minheap[j]>minheap[2*j])
		{
			temp=minheap[2*j];
			minheap[2*j]=minheap[j];
			minheap[j]=temp;
			shuffledownminheap(2*j);
		}
		else
			return ;

	}
	else 
		return ;
}
long long int deleteminheap()
{
	long long int j;
	minheap[1]=minheap[end1-1];
	j=1;
	end1--;
	shuffledownminheap(j);
	return end1;
}
long long int insertminheap(long long int a)
{
	minheap[end1]=a;
	long long int temp,j;
	if(end1>1)
	{
		j=end1;
		while(minheap[j/2]>minheap[j] && j>1)
		{
			temp=minheap[j];
			minheap[j]=minheap[j/2];
			minheap[j/2]=temp;
			j=j/2;
		}
	}
	return end1+1;
}
long long int max(long long int j)
{
	if(maxheap[2*j]<maxheap[2*j+1])
		return 2*j+1;
	else
		return 2*j;
}
void shuffledownmaxheap(long long int j)
{
	long long int temp,k;
	if(2*j+1<=end2-1)
	{
		k=max(j);
		if(maxheap[j]<maxheap[k])
		{
			temp=maxheap[k];
			maxheap[k]=maxheap[j];
			maxheap[j]=temp;
			shuffledownmaxheap(k);
		}
		else
			return ;
	}
	else if(2*j==end2-1)
	{
		if(maxheap[j]<maxheap[2*j])
		{
			temp=maxheap[2*j];
			maxheap[2*j]=maxheap[j];
			maxheap[j]=temp;
			shuffledownmaxheap(2*j);
		}
		else
			return ;

	}
	else 
		return ;
}
long long int deletemaxheap()
{
	long long int j;
	maxheap[1]=maxheap[end2-1];
	j=1;
	end2--;
	shuffledownmaxheap(j);
	return end2;
}
long long int insertmaxheap(long long int a)
{
	maxheap[end2]=a;
	long long int temp,j;
	if(end2>1)
	{
		j=end2;
		while(maxheap[j/2]<maxheap[j] && j>1)
		{
			temp=maxheap[j];
			maxheap[j]=maxheap[j/2];
			maxheap[j/2]=temp;
			j=j/2;
		}
	}
	return end2+1;
}
void insert(long long int a,long long int len)
{
	if(len%2==0)
	{
//		printf("1\n");
		if(a>=minheap[1])
		{
		//	printf("%lld\n",minheap[1]);
			end2=insertmaxheap(minheap[1]);
			end1=deleteminheap();
			end1=insertminheap(a);
//		printf("2\n");
		}
		else
		{	end2=insertmaxheap(a);
//			printf("3\n");
		}

	}
	else
	{
//		printf("4\n");
		if(a>=maxheap[1])
		{
//			printf("5\n");
	//		printf("%lld\n",len);
			end1=insertminheap(a);
		}
		else
		{
			end1=insertminheap(maxheap[1]);
			end2=deletemaxheap();
			end2=insertmaxheap(a);
//			printf("6\n");
		}
	}
}
long long int f(long long int i)
{
	if(i==1)
		return 1;
	else
	{
		return ((a%1000000007)*(mid[i]%1000000007)+(b%1000000007)*(i%1000000007)+c%1000000007)%1000000007;
	}
}
long long int median(long long int i)
{
	if(i==2)
	{
		mid[i]=1;
		return mid[i];
	}
//	printf("%lld\n",f(i-1));
	insert(f(i-1),i-2);
	mid[i]=minheap[1];
	return mid[i];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	long long int i,sum=1,j;
	end1=2;
	end2=1;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
	for(i=1;i<=100001;i++)
	{		minheap[i]=0;
		maxheap[i]=0;
	}
	minheap[1]=1;
			
	for(i=2;i<=n;i++)
	{

		sum+=((a%1000000007)*(median(i)%1000000007)+(b%1000000007)*(i%1000000007)+c%1000000007)%1000000007;
///		printf("after inserting f of %lld end1 is %lld and end2 is %lld\n",i-1,end1,end2);
//		printf("f of %lld is %lld\n",i,a*median(i)+b*i+c);
//		printf("median of %lld is %lld\n",i,mid[i]);
	/*	printf("min heap is\n");
		for(j=1;j<end1;j++)
			printf("%lld ",minheap[j]);
		printf("\n");
		printf("max heap is\n");
		for(j=1;j<end2;j++)
			printf("%lld ",maxheap[j]);
		printf("\n");*/
	}
	printf("%lld\n",sum);
	
	/*for(i=1;i<end1;i++)
	{
		printf("%lld ",minheap[i]);

	}
	printf("\n");
	for(i=1;i<end2;i++)
	{
		printf("%lld ",maxheap[i]);
	}
	printf("\n");*/
	}

	return 0;
}


