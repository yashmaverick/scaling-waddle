#include<stdio.h>
long long int MIN[1000000],MAX[1000000],k=1,n,a,b,c,q=1;
long long int M[1000000],F[1000000];
long long int mod=1000000007;
void shuffleupmin(long long int p)
{
	long long int temp;
	if(p>1)
	{
		if(MIN[p]>=MIN[p/2])
		{
			return ;
		}
		else
		{
			temp=MIN[p];
			MIN[p]=MIN[p/2];
			MIN[p/2]=temp;
			p=p/2;
			shuffleupmin(p);
		}
	}
}
void shuffleupmax(long long int p)
{
	long long int temp;
	if(p>1)
	{
		if(MAX[p]<=MAX[p/2])
		{
			return ;
		}
		else
		{
			temp=MAX[p];
			MAX[p]=MAX[p/2];
			MAX[p/2]=temp;
			p=p/2;
			shuffleupmax(p);
		}
	}
}
void insertmin(long long int m)
{
	if(k==1)
	{
		MIN[k]=m;
		k=k+1;
	}
	else
	{
		MIN[k]=m;
		shuffleupmin(k);
		k=k+1;
	}
}
void insertmax(long long int m)
{
	if(q==1)
	{
		MAX[q]=m;
		q=q+1;
	}
	else
	{
		MAX[q]=m;
		shuffleupmax(q);
		q=q+1;
	}
}
long long int deletemin()
{
	long long int i=1,j,ret=MIN[1];
	MIN[1]=MIN[k-1];
	k--;
	while(2*i<=(k-1))
	{
		if(2*i==k-1)
			j=2*i;
		else if(MIN[2*i+1]>MIN[2*i])
			j=2*i;
		else
			j=2*i+1;
		if(MIN[i]>MIN[j])
		{
			long long int t;
			t=MIN[i];
			MIN[i]=MIN[j];
			MIN[j]=t;
			i=j;
		}
		else
			break;
	}
	return ret;
}
long long int deletemax()
{
	long long int i=1,j,ret=MAX[1];
	MAX[1]=MAX[q-1];
	q--;
	while(2*i<=(q-1))
	{
		if(2*i==q-1)
			j=2*i;
		else if(MAX[2*i+1]<MAX[2*i])
			j=2*i;
		else
			j=2*i+1;
		if(MAX[i]<MAX[j])
		{
			long long int t;
			t=MAX[i];
			MAX[i]=MAX[j];
			MAX[j]=t;
			i=j;
		}
		else
			break;
	}
	return ret;
}
long long int cal(long long int i)
{
	long long int temp;
	temp=((((a*M[i])%mod)+(b*i))%mod+c)%mod;
	return temp;
}
long long int update(long long int i,long long int median)
{
	long long int temp;
	if(F[i]>M[i])
		insertmin(F[i]);
	else
		insertmax(F[i]);
	if(q-k>0)
	{
		temp=deletemax();
		insertmin(M[i]);
		median=temp;
	}
	else if(q-k<-1)
	{
		temp=deletemin();
		insertmax(M[i]);
		median=temp;
	}
	return median;
}
int main()
{
	long long int d,i,m,t,u;
	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		F[1]=1;
		M[2]=1;
		for(i=2;i<=n;i++)
		{
			F[i]=cal(i);
	//		printf("F[%lld]=%lld ",i,F[i]);
			M[i+1]=update(i,M[i]);
	//		printf("M[%lld]=%lld",i,M[i]);
	//		printf("\n");
		}
		long long int ans=0;
		for(i=1;i<=n;i++)
			ans=(ans+F[i]);
		printf("%lld\n",ans);
		for(i=1;i<=n;i++)
		{
			MIN[i]=0;
			MAX[i]=0;
			M[i]=0;
			F[i]=0;
		}
		k=1;
		q=1;
	}
	return 0;
}
