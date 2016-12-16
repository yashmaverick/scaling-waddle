#include<stdio.h>
long long int mod=1000000007;

void su(int a[],int temp)
{
	if(temp/2==0) return;

	int y=a[temp/2];

	if(y<=a[temp]) return;

	a[temp/2]=a[temp];
//	b[a[temp]]=temp/2;
	a[temp]=y;
//	b[y]=temp;
	su(a,temp/2);
}

void sd(int a[],int temp,int *last)
{
	int x=2*temp;

	if(x>*last) return;
	else if(x==*last)
	{
		if(a[temp]<=a[x]) return;
		
		int y=a[x];
		a[x]=a[temp];
		//b[a[temp]]=x;
		a[temp]=y;
		//b[y]=temp;
		return;
	}
	else
	{
		int p,q;
		p=a[x];
		q=a[x+1];

		if(a[temp]<=p && a[temp]<=q) return;

		if(p<=q)
		{

			a[x]=a[temp];
		//	b[a[temp]]=x;
			a[temp]=p;
		//	b[p]=temp;
			sd(a,x,last);
		}
		else
		{
			a[x+1]=a[temp];
		//	b[a[temp]]=x+1;
			a[temp]=q;
		//	b[q]=temp;
			sd(a,x+1,last);
		}
	}

}


void insert(int a[],int x,int *last)
{
	(*last)++;
	a[*last]=x;
//	b[x]=last;
	su(a,*last);
}

void del(int a[],int *last)
{
//	b[a[1]]=0;
	a[1]=a[*last];
//	b[a[last]]=1;
	(*last)--;
	sd(a,1,last);
}

void su1(int a[],int temp)
{

	if(temp/2==0) return;

	int y=a[temp/2];

	if(y>=a[temp]) return;

	a[temp/2]=a[temp];
//	b[a[temp]]=temp/2;
	a[temp]=y;
//	b[y]=temp;
	su1(a,temp/2);
}

void sd1(int a[],int temp,int *last)
{
	int x=2*temp;

	if(x>*last) return;
	else if(x==*last)
	{
		if(a[temp]>=a[x]) return;
		
		int y=a[x];
		a[x]=a[temp];
		//b[a[temp]]=x;
		a[temp]=y;
		//b[y]=temp;
		return;
	}
	else
	{
		int p,q;
		p=a[x];
		q=a[x+1];

		if(a[temp]>=p && a[temp]>=q) return;

		if(p>=q)
		{

			a[x]=a[temp];
		//	b[a[temp]]=x;
			a[temp]=p;
		//	b[p]=temp;
			sd1(a,x,last);
		}
		else
		{
			a[x+1]=a[temp];
		//	b[a[temp]]=x+1;
			a[temp]=q;
		//	b[q]=temp;
			sd1(a,x+1,last);
		}
	}

}


void insert1(int a[],int x,int *last)
{
//	printf("$%d\n",*last);
	(*last)++;
	a[*last]=x;
//	printf("$%d\n",*last);
//	b[x]=last;
	su1(a,*last);
//	printf("$$%d\n",*last);
}

void del1(int a[],int *last)
{
//	b[a[1]]=0;
	a[1]=a[*last];
//	b[a[last]]=1;
	(*last)--;
	sd1(a,1,last);
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{

	long long int l1,l2,l3,n,i;
	scanf("%lld %lld %lld %lld",&l1,&l2,&l3,&n);

	long long int ans=1;
	int lasta=1;
	int lastb=0;
	int a[200005],b[200005];
	a[1]=1;

	for(i=2;i<=n;i++)
	{
		
		int x;
		x=(((l1*a[1])%mod)+(l2*i)%mod+l3)%mod;
		ans+=x;
		


	
	if(x<=a[1])
	{
		insert1(a,x,&lasta);
	}
	else
	{
		insert(b,x,&lastb);

	}
		
	
	if(lasta<lastb)
	{
		
		insert1(a,b[1],&lasta);
		del(b,&lastb);
	}
	else if(lasta>lastb+1)
	{
		insert(b,a[1],&lastb);	
		del1(a,&lasta);
	}
	
	

	}

	printf("%lld\n",ans);

	}
	return 0;
}
