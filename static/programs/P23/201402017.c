#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[100007];
void insert2(int x,int k)
{
	int temp,par,i,flag=0;
	i=k+1;
	a[k+1]=x;
	while(i!=1 && flag!=1)
	{
		par=i/2;
		if(a[par]>a[i])
		{
			temp=a[i];
			a[i]=a[par];
			a[par]=temp;
		}
		else
			flag=1;
		i=par;
	}
}

struct node{
	int data;
	struct node *next;
};
struct node *arr[100007];
struct node *rev[100007];
int in[100007];
int vis[100007];
struct node *insert(int v,struct node *root)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=v;
	temp->next=root;
	return temp;
}
int del(int n)
{
	int p,q;
	int t1=a[1];
	a[1]=a[n];
	n=n-1;
	int i=1;
	while(i<=n/2 && (a[i]>a[2*i] || a[i]>a[2*i+1]))
	{
		if(a[2*i]<a[2*i+1])
		{
			p=a[i];
			a[i]=a[2*i];
			a[2*i]=p;
			i=2*i;
		}
		//if(a[2*i]>a[2*i+1])
		else
		{
			q=a[i];
			a[i]=a[2*i+1];
			a[2*i+1]=q;
			i=(2*i+1);
		}
	}
	return t1;
}
int main()
{
	int n,t,j,i,u,v,m,c,x,p,q,r=0;
	scanf("%d %d",&n,&m);
	memset(in,0,sizeof(in));
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		arr[u]=insert(v,arr[u]);
		//rev[v]=insert(u,arr[v]);
		in[v]=in[v]+1;
	}
	//	for(i=1;i<=n;i++)
	//		printf("%d ",in[i]);
	/*for(i=1;i<=n;i++)
	  {
	  printf("%d-->",i);
	  print(arr[i]);
	  }*/
	for(i=1,x=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			insert2(i,x-1);
			x++;
		}
			//puts("ss");
		
	}
//	for(i=1;i<x;i++)
//		printf("%d--%d ",i,a[i]);
	//printf("%d",x);
	i=1;p=x;q=x-1;
	while(r<n)
	{
		r++;
		t=del(q--);
	//	for(j=1;j<=q-1;j++)
	//		printf("%d-- ",a[i]);
		//`printf("\n");
		if(r==n)
			printf("%d\n",t);
		else
			printf("%d ",t);
		struct node *itr=arr[t];
		while(itr!=NULL)
		{
			in[itr->data]=in[itr->data]-1;
			if(in[itr->data]==0)
			{
				insert2(itr->data,q);
				q++;
			}
			itr=itr->next;
		}
		i++;
		//q=q-1;
	}
		


	/*while(rear>=front)
	  {
	  t=peek();	
	  printf("%d ",deq());
	  struct node *itr=arr[t];
	  while(itr!=NULL)
	  {
	  in[itr->data]=in[itr->data]-1;
	  if(in[itr->data]==0)
	  enq(itr->data);
	  itr=itr->next;
	  }
	  }*/
	return 0;
}


