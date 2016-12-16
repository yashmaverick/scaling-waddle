#include<stdio.h>
long long int a[1000001], b[1000001];
long long int i,k,htopm, htopM;

void shuffleupm(long long int i)
{
	long long int tmp;
	if(i!=0)
	{
		if(a[i]<a[i/2])
		{
			tmp=a[i];
			a[i]=a[i/2];
			a[i/2]=tmp;

			shuffleupm(i/2);
		}
	}
}

void insertm(long long int x)
{
	i++;
	a[i]=x;
	shuffleupm(i);
}

void shuffledownm(long long int j)
{
	long long int temp;
	if(a[2*j]!=-1 && a[2*j+1]!=-1)
	{
		if(a[2*j]<a[j]  || a[2*j+1] < a[j])
		{
			if(a[2*j] < a[2*j+1])
			{
				temp=a[2*j];
				a[2*j]=a[j];
				a[j]=temp;
				shuffledownm(2*j);
			}
			else
			{
				temp=a[2*j+1];
				a[2*j+1]=a[j];
				a[j]=temp;
				shuffledownm(2*j+1);
			}
		}
	}
	else if(a[2*j]!=-1 && a[2*j+1]==-1)
	{
		if(a[2*j] < a[j])
		{
			temp=a[2*j];
			a[2*j]=a[j];
			a[j]=temp;
		}
	}
}

void deletemin()
{
	htopm=a[1];
	a[1]=a[i];
	a[i]=-1;
	i--;
	shuffledownm(1);
}

void displaym()
{
	long long int q;
	for(q=1;q<=i;q++)
	{
		printf("q %lld val %lld\n",q,a[q]);
	}
}

void shuffleupM(long long int k)
{
	long long int tmp;
	if(k!=0)
	{
		if(b[k] > b[k/2])
		{
			tmp=b[k];
			b[k]=b[k/2];
			b[k/2]=tmp;

			shuffleupM(k/2);
		}
	}
}

void insertM(long long int x)
{
	k++;
	b[k]=x;
	shuffleupM(k);
}

void shuffledownM(long long int j)
{
	long long int temp;
	if(b[2*j]!=-1 && b[2*j+1]!=-1)
	{
		if(b[2*j] > b[j]  || b[2*j+1] > b[j])
		{
			if(b[2*j] > b[2*j+1])
			{
				temp=b[2*j];
				b[2*j]=b[j];
				b[j]=temp;
				shuffledownM(2*j);
			}
			else
			{
				temp=b[2*j+1];
				b[2*j+1]=b[j];
				b[j]=temp;
				shuffledownM(2*j+1);
			}
		}
	}
	else if(b[2*j]!=-1 && b[2*j+1]==-1)
	{
		if(b[2*j] > b[j])
		{
			temp=b[2*j];
			b[2*j]=b[j];
			b[j]=temp;
		}
	}
}

void deletemax()
{
	htopM=b[1];
	b[1]=b[k];
	b[k]=-1;
	k--;
	shuffledownM(1);
}

void displayM()
{
	long long int q;
	for(q=1;q<=k;q++)
	{
		printf("q %lld val %lld\n",q,b[q]);
	}
}

long long int mead()
{
	if(k>=i)
		return b[1];
	else
		return a[1];
}

void balance()
{
	if(i > k+1)
	{
		deletemin();
		insertM(htopm);
	}
	else if(k > i+1)
	{
		deletemax();
		insertm(htopM);
	}
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int q;
		for(q=0;q<=1000000;q++)
		{
			a[q]=-1;
			b[q]=-1;
		}
		b[0]=1000000000000000;
		i=0;
		k=0;
		long long int x,y,z,n,f[200005], sum;
		f[1]=1;
		sum=f[1];
		scanf("%lld %lld %lld %lld",&x,&y,&z,&n);
		insertM(f[1]);
		for(q=2;q<=n;q++)
		{
			f[q]=((x*mead())%1000000007 + (y*q)%1000000007 + z%1000000007) % 1000000007;
	//		printf("f is %lld\n",f[q]);
			sum+=f[q];
			if(f[q] <= b[1] )
			{
				insertM(f[q]);
			}
			else
			{
				insertm(f[q]);
			}
			balance();
		}
		printf("%lld\n",sum);
	}
	return 0;
}
