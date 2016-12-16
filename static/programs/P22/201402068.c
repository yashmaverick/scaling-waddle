#include <stdio.h>
#define maxinf 1000000007
#define mininf -1
typedef long long int lli;
void insert(lli val,lli *arr);
lli delete(lli *arr);
void insert2(lli val,lli *arr);
lli delete2(lli *arr);
lli ins1,ins2;
int main()
{
	lli t;
	lli a,b,c,n;
	lli maxh[200005];
	lli minh[200005];
	lli f[200005];
	lli e1,e2;
	lli mod=1000000007;
	scanf("%lld",&t);
	f[1]=1;
	lli i;
	lli m;
	lli sum;
	while(t--)
	{
		sum=1;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		ins1=ins2=1;
		for(i=1;i<=n;i++)
		{
			maxh[i]=0;
			minh[i]=0;
		}

		e1=e2=0;
		insert2(f[1],maxh);
		e1=1;
		for(i=2;i<=n;i++)
		
		{
/*			printf("Before anything\n");
		printf("printing max heap\n");
		int j;
		for(j=1;j<ins1;j++)
			printf("%lld ",maxh[j]);
		printf("\n");
		printf("printing min heap\n");
		for(j=1;j<ins2;j++)
			printf("%lld ",minh[j]);
		printf("\n");*/
			if(ins2>ins1)
			{
				m=minh[1];
			}
			else
			{
				m=maxh[1];
			}

			f[i]=(((a%mod*m%mod)%mod+(b%mod*i%mod)%mod)%mod+c%mod)%mod;

			if(f[i]>maxh[1])//
			{
				insert(f[i],minh);
				e2++;
			}
			else
			{
				insert2(f[i],maxh);
				e1++;
			}
		//	printf("after insert\n");
	//	printf("printing max heap\n");
	/*	j;
		for(j=1;j<ins1;j++)
			printf("%lld ",maxh[j]);
		printf("\n");
		printf("printing min heap\n");
		for(j=1;j<ins2;j++)
			printf("%lld ",minh[j]);
		printf("\n");

*/
			if((ins1-ins2)>1)
			{
				lli temp=delete2(maxh);
				e1--;
				insert(temp,minh);
				e2++;
			}
			else if((ins2-ins1)>1)
			{
				lli temp=delete(minh);
				e2--;
				insert2(temp,maxh);
				e1++;
			}
  /*      printf("after rearrangement\n"); 
		printf("printing max heap\n");
		j;
		for(j=1;j<ins1;j++)
			printf("%lld ",maxh[j]);
		printf("\n");
		printf("printing min heap\n");
		for(j=1;j<ins2;j++)
			printf("%lld ",minh[j]);
		printf("\n");*/
			sum+=f[i];
		}
		printf("%lld\n",sum);
	/*	printf("%lld %lld\n",ins1,ins2);
		printf("final\n");
		printf("printing max heap\n");
		int j;
		for(j=1;j<ins1;j++)
			printf("%lld ",maxh[j]);
		printf("\n");
		printf("printing min heap\n");
		for(j=1;j<ins2;j++)
			printf("%lld ",minh[j]);
		printf("\n");
*/
	}
	return 0;
}
void insert(lli val,lli *arr)
{//printf("insert OK\n");
	arr[ins2]=val;
	ins2++;
	lli x=ins2-1;
	while(arr[x/2]>arr[x] && x>1)
	{
		lli temp=arr[x];
		arr[x]=arr[x/2];
		arr[x/2]=temp;
		x=x/2;
	}
}
lli delete(lli *arr)
{
	lli ret=arr[1];
	arr[1]=arr[--ins2];
	arr[ins2]=0;
	lli x=1;
	while((arr[x]>arr[2*x] && arr[2*x]!=0) || (arr[x]>arr[2*x+1] && arr[2*x+1]!=0) && 2*x<=(ins2-1))
	{
	//	printf("yo\n");
		if(arr[2*x+1]<arr[2*x] && arr[2*x+1]!=0)
		{
	//		printf("yo 2x+1<\n");
			lli temp=arr[x];
			arr[x]=arr[2*x+1];
			arr[2*x+1]=temp;
			x=2*x+1;
		}
		else 
		{
	//		printf("yo 2x+1>\n");
	//		printf("x %lld	2x %lld",arr[x],arr[2*x]);
			lli temp=arr[x];
			arr[x]=arr[2*x];
			arr[2*x]=temp;
			x=2*x;
		}
	}
	return ret;
}
void insert2(lli val,lli *arr)
{//printf("insert OK\n");
	arr[ins1]=val;
	ins1++;
	lli x=ins1-1;
	while(arr[x/2]<arr[x] && x>1)
	{
		lli temp=arr[x];
		arr[x]=arr[x/2];
		arr[x/2]=temp;
		x=x/2;
	}
}
lli delete2(lli *arr)
{
	lli ret=arr[1];
	arr[1]=arr[--ins1];
	arr[ins1]=0;
	lli x=1;
	while((arr[x]<arr[2*x] && arr[2*x]!=0) || (arr[x]<arr[2*x+1] && arr[2*x+1]!=0) && 2*x<=(ins1-1) )
	{
		if(arr[2*x+1]>arr[2*x] && arr[2*x+1]!=0)
		{
			lli temp=arr[x];
			arr[x]=arr[2*x+1];
			arr[2*x+1]=temp;
			x=2*x+1;
		}
		else 
		{
			lli temp=arr[x];
			arr[x]=arr[2*x];
			arr[2*x]=temp;
			x=2*x;
		}
	}
	return ret;
}
