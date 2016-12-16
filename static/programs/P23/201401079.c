#include<stdio.h>
#include<stdlib.h>
typedef struct graph
{
	long long int  value;
	struct graph *next;
}node;
node *p[500005];
node* insert(long long int  x, node* root)
{
	node* tmp=(node*)malloc(sizeof(node));
	tmp->value=x;
	tmp->next=root;
	return tmp;
}
long long int  v=0;
int  b[500005];
void swap( int  *a , int *b)
{
	 *a=*a^*b;
	 *b=*a^*b;
	 *a=*a^*b;
}
void insertminheap ( long long int  y)

{
        long long int  k;
	v++;
	k=v;
	b[v]=y;
	while(k > 1)
	{
		if(b[k/2] > b[k])
		{
			swap(&b[k],&b[k/2]);
			k=k/2;
		}
		else
			break;
	}
}
long long int  deleteminheap()
{
	long long int  c= b[1];
	swap(&b[1],&b[v]);
	 long long int  k=1;
	b[v]=1000000008;
	v--;
	while(2*k<=v)
	{
		if(b[2*k] < b[2*k+1])
		{
			if(b[2*k] < b[k])
			{
				swap(&b[2*k],&b[k]);
				k=k*2;
			//	if(k > v)
			//		break;
			}
			else
				break;
		}
		else if(b[2*k+1]< b[k])
		{
			swap(&b[2*k+1],&b[k]);
			k=2*k+1;
		}
		else
			break;
		  
	}
	return c;
}


int  main()
{
	long long int  m,n,i,j,k,l,u,v;
        int  a[500005];
	scanf("%lld%lld",&m,&n);
	for(i=1;i<=m;i++)
	{
		a[i]=0;
	}
	for(i=1;i<=m;i++)
		p[i]=NULL;
	for(i=1;i<=n;i++)
	{
//		prlong long int f("Scanning numbers\n");
		scanf("%lld%lld",&u,&v);

		p[u]=insert(v,p[u]);
		a[v]=a[v]+1;
	}
//	prlong long int f("Came out\n");
//	for(i=1;i<=m;i++)
//	  prlong long int f("%d ",a[v]);
	for(i=1;i<=m;i++)
	{
             node* tmp=(node*)malloc(sizeof(node));
	     tmp->value=i;
	     tmp->next=p[i];
	     p[i]=tmp;
	}
	for(i=1;i<=m;i++)
	{
		if(a[i]==0)
			insertminheap(i);
	}
	int c[500005];
	int z=0;
	while(1)
	{     
		k=deleteminheap();
		if(k==1000000008)
			break;
		 c[z++]=k;
		while(p[k]!=NULL)
		{
			p[k]=p[k]->next;
			if(p[k]!=NULL)
			{
				a[p[k]->value]=a[p[k]->value]-1;
				if(a[p[k]->value]==0)
					insertminheap(p[k]->value);
			}
		}
	}
	for(i=0;i<z-1;i++)
		printf("%d ",c[i]);
	printf("%d\n",c[z-1]);
	//printf("\b");
//	prlong long int f("BAnsalisbond\n");
//	printf("\n");
	
	return 0;

}
