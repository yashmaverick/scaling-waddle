#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
	long long int val;
	struct list *p;
}g;
long long int a[500010],size;
void insert(long long int x)
{
	long long int i,temp;
	i = size+1;
	//      printf("size=%d\n",size);
	a[i]=x;
	size++;
	while(i>1)
	{
		if(a[i]<a[i/2])
		{
			temp = a[i];
			a[i]=a[i/2];
			a[i/2]=temp;
		}
		else
		{
			break;
		}
		i = i/2;
	}
	/*for(i=1;i<=size;i++)
	  printf("%lld ",a[i]);
	  printf("\n");*/
	//return 0;
}

long long int delete()
{
	long long int temp,j,i;
	temp = a[1];
	j = a[1];
	a[1] = a[size];
	a[size]=temp;
	i = 1;
	size--;
	while(1)
	{
		if( (2*i) > size && (2*i+1) > size )
			return j;
		if(2*i==size)
		{
			if(a[i] > a[2*i])
			{
				temp = a[2*i];
				a[2*i] = a[i];
				a[i] = temp;
				i = 2*i;

			}
			else
				return j;
		}
		else if(a[i] < a[2*i+1] && a[i] < a[2*i])
			return j;
		else
		{
			if( a[2*i] < a[2*i+1] )
			{
				temp = a[2*i];
				a[2*i] = a[i];
				a[i] = temp;
				i = 2*i;
			}
			else
			{
				temp = a[2*i+1];
				a[2*i+1] = a[i];
				a[i] = temp;
				i = 2*i+1;
			}
		}
	}
	//size--;
}
int main()
{
	long long int n,m,i,u,v,ind[500010],count,x;
	g *a[500010],*temp,*y;
	scanf("%lld%lld",&n,&m);
	memset(ind,0,n);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&u,&v);
		y=malloc(sizeof(g));
		y->val=v;
		y->p=NULL;
		if( a[u] == NULL )
			a[u]=y;
		else
		{
			y->p=a[u];
			a[u]=y;
		}
		ind[v]++;
	}
	/*for(i=1;i<=n;i++)
	{
		temp =a[i];
		while(temp!=NULL)
		{
			printf("->%d",temp->val);
			temp = temp->p;
		}
		printf("\n");
	}*/
	size=0;
	for(i=1;i<=n;i++)
		if(ind[i]==0)
			insert(i);
	count=0;
	while(count<n)
	{
		count++;
		x = delete();
		temp = a[x];
		if(count==n)
			printf("%lld\n",x);
		else
			printf("%lld ",x);
		while(temp!=NULL)
		{
			ind[temp->val]--;
			if(ind[temp->val]==0)
				insert(temp->val);
			temp = temp->p;
		}
	}
	return 0;
}
