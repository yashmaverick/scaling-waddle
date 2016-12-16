#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int w;
	int a,b;
}node;
/*void fun(node l[],node r[],node a[],int nm)
{
	int i=0,j=0,k=0,nl,nr;
	nl=nm/2;
	nr=nm-(nm/2);
	while((i<nl)&&(j<nr))
	{
		if(l[i].w<=r[j].w)
		{
			a[k]=l[i];
			i++;
		}
		else
		{
			a[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		a[k]=l[i];
		k++;
		i++;
	}
	while(j<nr)
	{
		a[k]=r[j];
		k++;
		j++;
	}
}
void merge(node a[],int na) 
{
	int i=0,f=0,mid;
	node l[100001];
	node r[100001];
	if(na<2)
		return ;
	mid=na/2;
	while(i<mid)
	{
		l[i]=a[i];
		i++;
	}
	while(i<na)
	{
		r[f]=a[i];
		f++;
		i++;
	}
	merge(l,mid-1);
	merge(r,na-mid);
	fun(l,r,a,na);
}*/
int myComp(const void* a, const void* b)
{
	node* a1 = (node*)a;
	node* b1 = (node*)b;
	return a1->w > b1->w;
}
void minspan(node *edge,int v,int e)
{
	int i,count=0,j,k,l;
	long long int sum=0;
	int head[100001];
	for(i=1;i<=v;i++)
		head[i]=i;
	//merge(edge,e);
	qsort(edge, e, sizeof(edge[0]), myComp);
	//for(i=0;i<e;i++)
	//	printf("%lld %d %d\n",edge[i]);
	for(i=0;i<e;i++)
	{
		if(head[edge[i].a]!=head[edge[i].b])
		{
			sum+=edge[i].w;
			count++;
			k=head[edge[i].b];
			l=head[edge[i].a];
			for(j=1;j<=v;j++)
			{
				if(head[j]==k)
				{
					head[j]=l;
				}
			}
		}
		/*for(j=1;j<=v;j++)
			printf("%d ",head[j]);
		printf("\n");*/
		if(count==v-1)
			break;
	}
	//printf("%d\n",count);
	if(count==v-1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
}
int main()
{
	int N,M,i;
	scanf("%d%d",&N,&M);
	node* edge=(node*)malloc(sizeof(node)*M);
	for(i=0;i<M;i++)
	{
		scanf("%d%d%lld",&edge[i].a,&edge[i].b,&edge[i].w);
	}
	//printf("---------\n");
	minspan(edge,N,M);
	return 0;
}
