#include<stdio.h>

long long  int mn[200004];
 long long int mx[200004];
 long long int hx,hn;
long long int f[200004];

void insertn(long long int t)
{

	hn++;
//	prlong long intf("isert min %d\n",t);
	mn[hn]=t;
	long long int i=hn,p;
	while(i>1)
	{
		p=i/2;
		if(mn[p]>mn[i])
		{
			long long int temp;
			temp = mn[p];
			mn[p] = mn[i];
			mn[i] = temp;
			i=p;
		}
		else
			break;
	}
}


void insertm(long long int t)
{
	hx++;
//	printf("isert max %d\n",t);
	mx[hx]=t;
	long long int i=hx,p;
	while(i>1)
	{
		p=i/2;
		if(mx[p]<mx[i])
		{
			long long int tmp;
			tmp = mx[p];
			mx[p]=mx[i];
			mx[i]=tmp;
			i=p;
		}
		else
			break;
	}
		
}
void chan2()
{
	long long int t=mx[1];
	insertn(t);
	mx[1]=mx[hx];
	hx--;
	long long int i=1,p;
	while(2*i<=hx)
	{
		p=2*i;
		if((2*i+1)<=hx)
		{
		if(mx[2*i]<mx[2*i+1])
			p=2*i+1;
		}
		if(mx[i]<mx[p])
		{
			long long int tmp=mx[i];
			mx[i]=mx[p];
			mx[p]=tmp;
		}
		i=p;
	}

}
void chan()
{

	long long int t=mn[1];
	insertm(t);
	mn[1]=mn[hn];
	hn--;
	long long int i=1;
	long long int p;
	while(2*i<=hn)
	{

		if(mn[2*i]<mn[2*i+1])
			p=2*i;
		else
			p=2*i+1;
//	printf("--- p %lld l %lld r %lld\n",mn[p],mn[2*i],mn[2*i+1]);
		if(mn[i]>mn[p])
		{
			long long int tmp=mn[i];
			mn[i]=mn[p];
			mn[p]=tmp;
		}
		i=p;
	}

}
//printf("hx %lld hn %lld\n",hx,hn);



long long int m()
{
//printf("me = hx %lld hn %lld\n",hx,hn);
	if(hx==hn)
		return mx[1];
	else if(hx>hn)
		return mx[1];
	else
		return mn[1];



}

void ci(long long int t)
{

//prlong long intf("m t %d hx %d hn %d\n",t,hx,hn);
//printf("top mx %lld mn %lld\n",mx[1],mn[1]);
	if(hn==0)
		insertn(t);
	else if(t<mn[1])
	insertm(t);
	else 
		insertn(t);
	if(hx-hn==2)
	{
		chan2();
	}
	else if(hn-hx==2)
	{
		chan();
	}

}

 int main()
{

	long long int t,a,b,c,n,i,k,t1,t2;
	long long int sum;
	scanf("%lld",&t);
	while(t--)
	{
		sum=1;
		hx=0;
		hn=0;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		for(k=1;k<=n;k++)
			f[k]=0;
		f[1]=1;
		ci(1);
		long long int te;

		for(k=2;k<=n;k++)
		{
			te=m();
			f[k]=((a*te)%1000000007+(b*k)%1000000007+c)%1000000007;
//			printf("k %lld f %lld  m %lld\n",k,f[k],te);
			ci(f[k]);
			sum += f[k];
/*			for(t1=1;t1<=hx;t1++)
				printf("hx-%lld ",mx[t1]);
			printf("\n");
			for(t2=1;t2<=hn;t2++)
				printf("hn-%lld ",mn[t2]);
			printf("\n");*/
		}
		printf("%lld\n",sum);
	}
return 0;
}
