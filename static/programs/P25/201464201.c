#include<stdio.h>
#include<stdlib.h>
long long int heap[100000];
int point;int rep[1000000];
typedef struct heap
{
	int v1;
	int v2;
	int w;
}h;
h *heaparr[1000000];
void insert(int a,int b,int c)
{
	point++;
	heaparr[point]=malloc(sizeof(h));
	heaparr[point]->v1=a;
	heaparr[point]->v2=b;
	heaparr[point]->w=c;
	int index=point;
	while(index>1)
	{
		if(heaparr[index]->w<heaparr[index/2]->w)
		{
			int temp=heaparr[index]->w;
			heaparr[index]->w=heaparr[index/2]->w;
			heaparr[index/2]->w=temp;
			temp=heaparr[index]->v1;
			heaparr[index]->v1=heaparr[index/2]->v1;
			heaparr[index/2]->v1=temp;
			temp=heaparr[index]->v2;
			heaparr[index]->v2=heaparr[index/2]->v2;
			heaparr[index/2]->v2=temp;
		}
		index=index/2;
	}
}
void delete()
{

	heaparr[1]->w=heaparr[point]->w;
	heaparr[point]->w='\0';
	heaparr[1]->v1=heaparr[point]->v1;
	heaparr[1]->v2=heaparr[point]->v2;
	point--;
	int index=1;
	if(index>point)
		return;
	while(1)
	{

		int maxindex=2*index;
		if(maxindex>point)
			return;
		if(heaparr[maxindex]->w>heaparr[maxindex+1]->w && maxindex+1<=point)
		{
			maxindex++;
		}
		if(heaparr[index]->w>heaparr[maxindex]->w)
		{
			int temp=heaparr[index]->w;
			heaparr[index]->w=heaparr[maxindex]->w;
			heaparr[maxindex]->w=temp;
			temp=heaparr[index]->v1;
			heaparr[index]->v1=heaparr[maxindex]->v1;
			heaparr[maxindex]->v1=temp;
			temp=heaparr[index]->v2;
			heaparr[index]->v2=heaparr[maxindex]->v2;
			heaparr[maxindex]->v2=temp;
		}
		index=maxindex;
		if(index>point)
			break;

	}
}
int max()
{
	return heap[1];
}
void print()
{
	int i;
	for(i=1;i<=point;i++)
		printf("%d ",heaparr[i]->w);
	printf("\n");
}
/*int cmpfunc (const void * a, const void * b)
  {
  return ( *(int*)a.w - *(int*)b.w );

  }*/
int main()
{
	long long int val,i,j,k,n,e,sum=0,a,b,w,count=1;
	scanf("%lld %lld", &n,&e);
	for(i=1;i<=n;i++)
	{
		rep[i]=i;
	}
	for(i=0;i<e;i++)
	{
		scanf("%lld %lld %lld", &a,&b,&w);
		insert(a,b,w);
		//	heaparr[i+1].v1=a;
		//	heaparr[i+1].v2=b;
		//	heaparr[i+1].w=w;
	}
	//	qsort(heaparr, e-1, sizeof(long long int), cmpfunc);
//	print();
	for(i=1;i<=n;i++)
	{
		rep[i]=i;
	}
	if(count>n || point<1)
	{
		printf("-1\n");
	}
	else
	{
		while(count<=n && point>=1)
		{
			a=heaparr[1]->v1;
			b=heaparr[1]->v2;
			w=heaparr[1]->w;i=a;
			while(rep[i]!=i)
			{
				i=rep[i];
			}
			j=i;
			i=b;
			while(rep[i]!=i)
			{
				i=rep[i];
			}
			if(j==i)
			{
				delete();
			}
			else
			{
				rep[i]=a;
				sum=sum+w;
				count++;
				delete();
			}
	//		printf("%lld\n",j);
			/*	if(point<1 && count<n)
				{
				printf("-1\n");
				break;
				}*/
			if(point < 1 && count==n)
			{
				printf("%lld\n", sum);
				break;
			}
			else if(point<1)
			{
				printf("-1\n");
				break;
			}
			if(count==n)
			{
				printf("%lld\n", sum);
				break;
			}
		}
	}
	return 0;
}
