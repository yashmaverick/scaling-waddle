#include<stdio.h>
#include<string.h>
#define MOD 1000000007
void swap(int A[],int x, int y)
{
	int temp=A[x];
	A[x]=A[y];
	A[y]=temp;
}
int pmin,pmax,Amin[200001],Amax[200001];
void insert_min(int x)
{
	Amin[pmin++]=x;
	int y=pmin-1;
	while(y>1 && Amin[y]<Amin[y/2])
	{
		swap(Amin,y,y/2);
		y/=2;
	}
}
void insert_max(int x)
{
	Amax[pmax++]=x;
	int y=pmax-1;
	while(y>1 && Amax[y]>Amax[y/2])
	{
		swap(Amax,y,y/2);
		y/=2;
	}
}
void delmin()
{
	Amin[1]=Amin[pmin-1];
	pmin--;
	int y=1;
	while(y<=(pmin-1)/2 && (Amin[y]>Amin[2*y] || Amin[y]>Amin[2*y+1]))
	{
		if(Amin[2*y]<Amin[2*y+1])
		{
			swap(Amin,y,2*y);
			y=2*y;
		}
		else
		{
			swap(Amin,y,2*y+1);
			y=2*y+1;
		}
	}
}
void delmax()
{
	Amax[1]=Amax[pmax-1];
	pmax--;
	int y=1;
	while(y<=(pmax-1)/2 && (Amax[y]<Amax[2*y] || Amax[y]<Amax[2*y+1]))
	{
		if(Amax[2*y]>Amax[2*y+1])
		{
			swap(Amax,y,2*y);
			y*=2;
		}
		else
		{
			swap(Amax,y,2*y+1);
			y=2*y+1;
		}
	}
}
int median()
{
	int m;
	if(pmax>=pmin)
	{
		m=Amax[1];
		//delmax();
	}
	else if(pmin>pmax)
	{
		m=Amin[1];
		//delmin();
	}
	return m;
}	
void check()
{
	if((pmax-pmin)>1)
	{
		
		insert_min(Amax[1]);
		delmax();
	}
	else if((pmin-pmax)>1)
	{
		insert_max(Amin[1]);
		delmin();
	}
}	
		
void insert(int x,int m)
{
	//if(m==-1)
	//	insert_max(x);
	if(x>m)
	{
		if(pmin>pmax)
		{
			insert_max(Amin[1]);
			delmin();
		}	
		insert_min(x);
		//check();
	}
	else if(x<m)
	{
		if(pmax>pmin)
		{
			insert_min(Amax[1]);
			delmax();
		}	
		insert_max(x);
		//check();
	}
	else
	{
		if(pmax<=pmin)
			insert_max(x);
				
			//insert_max(x);
		else 
			insert_min(x);
		//check();	
	}
	//printf("while inserting %d ;maxheap=%d minheap=%d\n",x,Amax[1],Amin[1]);
}	
int main()
{
	int t,m,i,n,f;
	long long int a,b,c,sum;
	scanf("%d",&t);
	while(t--)
	{
		pmin=1;pmax=1;sum=0;
		//insert_max(1);
		m=1000000;
		//memset(Amin,1000000008,sizeof(int)*200001);
		//memset(Amax,0,sizeof(int)*200001);
		for(i=1;i<200001;i++)
		{
			Amin[i]=1000000008;
			Amax[i]=-1;
		}	
		scanf("%lld%lld%lld%d",&a,&b,&c,&n);
		for(i=1;i<=n;i++)
		{
			if(i>1)
			{
				m=median();
				f=(a*m+b*i+c)%MOD;
			}
			else
				f=1;
			//printf("i=%d m=%d f=%d\n",i,m,f);
			insert(f,m);
			sum=sum+f;
		}
		printf("%lld\n",sum);
	}
	return 0;
}	


