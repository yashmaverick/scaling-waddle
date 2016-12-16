#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int data;
	struct node * next;
}node;
void insert(node * a[],long long int s, long long int d)
{
	node * temp;
	node * temp1=(node *)malloc(sizeof(node));
	temp=(node *)malloc(sizeof(node));
	temp->data=d;
	temp->next=a[s]->next;
	a[s]->next=temp;
	temp1->data=s;
	temp1->next=a[d]->next;
	a[d]->next=temp1;
}
long long int cnt=0,max=0, nod=0;
void dfs(long long int i,node * a[],long long int *v,long long int h)
{
	v[i]=1;
	node * temp=a[i];
	h++;
	long long int rem;
	long long int flag=0;
	while(temp!=NULL)
	{
		rem = temp->data;
		if(v[temp->data]==0)
		{
			dfs(temp->data,a,v,h);
		}
		temp=temp->next;
		flag=1;
	}
	if(h>max && flag==1){
		max = h;
		//printf("max is %lld\n",max);
		nod = rem;
	}
	return ;
}
long long int max1=0;
void  dfs1(long long int i,node * a[],long long int *v,long long int h)
{
	v[i]=1;
	node* temp=a[i];
	long long int flag=0;
	if(h>max1)
		max1 = h;
	while(temp!=NULL)
	{
		if(v[temp->data]==0)
		{
			v[temp->data]=1;
			dfs1(temp->data,a,v,h+1);
		}
		flag = 1;
		temp=temp->next;
	}
	return ;
}

int main()
{
	long long int i,j,k,n,m,V,t;
	scanf("%lld",&t);
	//printf("%d\n",t);
	while(t--)
	{
		nod=0;
		scanf("%lld",&V);
		long long int *v;
		/*node *a;
		a=(node *)malloc(sizeof(node )*(V+1));*/
		node *a[V+1];
		v=(long long int *)malloc(sizeof(long long int )*(V+1));
		for(i=1;i<=V;i++)
		{
			node* new;
		v[i]=0;
			new = (node *)malloc(sizeof(node));
			a[i] = new;
			a[i] -> data=i;
			a[i] -> next=NULL;
		}
		for(i=0;i<V-1;i++)
		{
			scanf("%lld %lld",&m,&n);
			insert(a,m,n);
		}
		node *temp;
		/*for(i=1;i<=V;i++)
		{	
			temp=a[i];
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp=temp->next;
			}
			printf("\n");
		}*/
		long long int h=0;
		for(i=1;i<=V;i++)
			v[i]=0;
		dfs(a[1]->data,a,v,0);
		long long int h2=1;
		for(i=1;i<=V;i++)
			v[i]=0;
		//rintf("%d\n",max);
		dfs1(nod,a,v,1);
		printf("%lld\n",max1+1);
		max=max1=0;
	}
	return 0;
}
