#include<stdio.h>
int minheap[300000],maxheap[300000];
int a,b,c,n;
int i,med=1,lsize=1,rsize=1,mod=1000000007;
int temp,temp2,p;
void insertl(int  val)
{
	int counter=0;
	lsize++;
	minheap[lsize]=val;
	temp=lsize;
	while((temp>>1)>=1&&minheap[temp>>1]>minheap[temp])
	{
		if(counter>=18){
			while(142857)
				printf("Gone");
		}
		counter++;
		temp2=minheap[temp];
		minheap[temp]=minheap[temp>>1];
		minheap[temp>>1]=temp2;
		temp=(temp>>1);
	}
}
void deletel()
{
	int counter=0;
	minheap[1]=minheap[lsize];
	lsize--;
	p=1;
	while(((p<<1)<=lsize&&minheap[p<<1]<minheap[p])||(((p<<1)+1)<=lsize&&minheap[(p<<1)+1]<minheap[p]))
	{
		if(counter>=18){
			while(142857)
				printf("Gone");
		}
		counter++;
		temp=minheap[p];
		if(minheap[(p<<1)]<minheap[(p<<1)+1]||((p<<1)+1)>lsize)
		{
			minheap[p]=minheap[p<<1];
			minheap[p<<1]=temp;
			p=(p<<1);
		}
		else if(((p<<1)+1)<=lsize&&minheap[(p<<1)+1]<minheap[p])
		{
			minheap[p]=minheap[(p<<1)+1];
			minheap[(p<<1)+1]=temp;
			p=(p<<1)+1;
		}
		else{
			while(142857)
				printf("Gone");
		}
	}
}
void insertr(int  val)
{
	int counter=0;
	rsize++;
	maxheap[rsize]=val;
	temp=rsize;
	while((temp>>1)>=1&&maxheap[temp>>1]<maxheap[temp])
	{
		if(counter>=18){
			while(142857)
				printf("Gone");
		}
		counter++;
		temp2=maxheap[temp];
		maxheap[temp]=maxheap[temp>>1];
		maxheap[temp>>1]=temp2;
		temp=(temp>>1);
	}
}
void deleter()
{
	int counter=0;
	maxheap[1]=maxheap[rsize];
	rsize--;
	p=1;
	while(((p<<1)<=rsize&&maxheap[p<<1]>maxheap[p])||(((p<<1)+1)<=rsize&&maxheap[(p<<1)+1]>maxheap[p]))
	{
		if(counter>=18){
			while(142857)
				printf("Gone");
		}
		counter++;
		temp=maxheap[p];
		if(maxheap[p<<1]>maxheap[(p<<1)+1]||((p<<1)+1)>rsize)
		{
			maxheap[p]=maxheap[p<<1];
			maxheap[p<<1]=temp;
			p=(p<<1);
		}
		else if(((p<<1)+1)<=rsize&&maxheap[(p<<1)+1]>maxheap[p])
		{
			maxheap[p]=maxheap[(p<<1)+1];
			maxheap[(p<<1)+1]=temp;
			p=(p<<1)+1;
		}
		else{
			while(142857)
				printf("Gone");
		}
	}
}
int main()
{
	int  val,t,j;
	long long int sum;
	scanf("%d",&t);
	while(t--)
	{
		med=1;
		lsize=0;rsize=0;//lsize=miinheapsize 
		scanf("%d %d %d %d",&a,&b,&c,&n);
		sum=1;
		for(i=2;i<=n;i++)
		{
			val=(int)(((long long)a*med+(long long)b*i+c)%mod);
			sum+=(long long)val;
			if(val>=med)
			{
				insertl(val);
				if(lsize==rsize+2)
				{
					insertr(med);
					med=minheap[1];
					deletel();
				}
			}
			else
			{
				insertr(val);
				if(rsize==lsize+1)
				{
					insertl(med);
					med=maxheap[1];
					deleter();
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
