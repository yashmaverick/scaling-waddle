#include<stdio.h>
#include<stdlib.h>
struct heap{
	long long int size;
	long long int * a;
};
typedef struct heap heap;
typedef heap* hp;
void insertmin(long long int x,hp he)
{
	long long int i;
	//if(he->size==he->cap)
//	{
//		printf("cannot insert\n");
//	}
	long long int temp;
		he->size++;
		he->a[he->size]=x;
		for(i=he->size;i>1 && x<he->a[i/2];i=i/2)
		{
			temp=he->a[i];
			he->a[i]=he->a[i/2];
			he->a[i/2]=temp;
		}
	return;
}
void insertmax(long long int x,hp hem)
{
	long long int i;
	//if(hem->size==hem->cap)
//	{
//		printf("cannot insert\n");
//	}
	long long int temp;
		hem->size++;
		hem->a[hem->size]=x;
		for(i=hem->size;i>1 && x>hem->a[i/2];i=i/2)
		{
			temp=hem->a[i];
			hem->a[i]=hem->a[i/2];
			hem->a[i/2]=temp;
		}
	return;
}
long long int mi(long long int x1,long long int x2)
{
	return x1<x2?x1:x2;
}
long long int ma(long long int x1,long long int x2)
{
	return x1>x2?x1:x2;
}
long long int delmin(hp he)
{
	long long int min,i,new,last;
	min=he->a[1];
	last=he->a[he->size--];
	for(i=1;he->size>=2*i;i=new)
	{
		new=2*i;
		if(new!=he->size && he->a[new+1]<he->a[new])
		{
			new++;
		}
		if(last>he->a[new])
		{
			he->a[i]=he->a[new];
		}
		else
		{
			break;
		}
	}
	he->a[i]=last;
	return min;
}		
long long int delmax(hp hem)
{
	long long int max,i,new,last;
	max=hem->a[1];
	last=hem->a[hem->size--];
	for(i=1;hem->size>=2*i;i=new)
	{
		new=2*i;
		if(new!=hem->size && hem->a[new+1]>hem->a[new])
		{
			new++;
		}
		if(last<hem->a[new])
		{
			hem->a[i]=hem->a[new];
		}
		else
		{
			break;
		}
	}
		hem->a[i]=last;
	return max;
}		
int main()
{
	int test;
	long long int aa,bb,cc,n;
	long long int mod=1000000007;
	scanf("%d",&test);
	while(test>0)
	{
		scanf("%lld %lld %lld %lld",&aa,&bb,&cc,&n);
		int i,y,flag=0;
		long long int x,ans;
		ans=0;
		hp he,hem;
		int cntmin=0;
		int cntmax=0;
		he=(hp)malloc(sizeof(heap));
		he->size=0;
		he->a=(long long int *)malloc((n+5)*sizeof(long long int));
		hem=(hp)malloc(sizeof(heap));
		hem->size=0;
		hem->a=(long long int *)malloc((n+5)*sizeof(long long int));
		long long int* f;
		long long int* m;
		f=(long long int*)malloc((n+5)*sizeof(long long int));
		m=(long long int*)malloc((n+5)*sizeof(long long int));
		f[1]=1;m[2]=1;
		for(i=1;i<n;i++)
		{	
			x=f[i];
			if(flag==0)
			{
				insertmin(x,he);
				cntmin++;
				m[i+1]=he->a[1];
				//printf("cur med is %d\n",he->a[1]);
				flag=1;
			}
			else
			{
				if(x>=he->a[1])
				{
					insertmin(x,he);
					cntmin++;
					//printf("cntmin=%d\n cntmax=%d\n",cntmin,cntmax);
					if(cntmin>cntmax+1)
					{
						y=delmin(he);
						//printf("he->a[2]=%d\n",he->a[2]);
						cntmin--;
						insertmax(y,hem);
						//printf("%d\n",hem->a[1]);
						cntmax++;
						//printf("cntmin=%d\n cntmax=%d\n",cntmin,cntmax);
					}
					if(cntmin==cntmax)
					{
						m[i+1]=hem->a[1];
					}
					else if(cntmin==cntmax+1)
					{
						m[i+1]=he->a[1];
					}
					else
					{
						m[i+1]=hem->a[1];
					}
				}
				else
				{
					insertmax(x,hem);
					cntmax++;
					if(cntmax>cntmin+1)
					{
						y=delmax(hem);
						cntmax--;
						insertmin(y,he);
						cntmin++;
					}	
					if(cntmin==cntmax)
					{
						m[i+1]=hem->a[1];
					}
					else if(cntmin==cntmax+1)
					{
						m[i+1]=he->a[1];
					}
					else
					{
						m[i+1]=hem->a[1];
					}
				}
			}
			f[i+1]=((aa*m[i+1])%mod+(bb*(i+1))%mod+(cc)%mod)%mod;
		//	printf("%lld %lld\n",m[i+1],f[i+1]);
		}
		for(i=0;i<n;i++)
		{
			ans=ans+f[i+1];
		}
		printf("%lld\n",ans);
		test--;
	}
	return 0;
}




