//GABBAR STUDIOWORKS
//p 23
//10 APR 2015
#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	long long int a;
	struct link*next;
}node;
typedef long long int ll;
node*arr[100002]={NULL};
node*point[100002]={NULL};
void insert(ll c,ll b)
{
	node*obj=(node*)malloc(sizeof(node));
	obj->a=b;
	obj->next=NULL;
	if(arr[c]==NULL)
	{
		arr[c]=obj;
		point[c]=arr[c];
	}
	else
	{
		point[c]->next=obj;
		point[c]=point[c]->next;
	}
}
ll minheap[200004];
ll minhead=1;
ll flag=0;
void deletemin(ll i)
{
	ll temp;
	minheap[i]=minheap[minhead-1];
	minheap[minhead-1]=9999999999;
	minhead--;
	//now to check whether the new heap maintains the property
	while((minheap[i]>minheap[2*i] || minheap[i]>minheap[2*i+1])&&(2*i)<minhead && minheap[2*i]!=9999999999)
	{
		//swap heap[i] & heap[2*i+1]
		if(minheap[2*i]>minheap[2*i+1] && minheap[2*i+1]!=9999999999)
		{
			temp=minheap[i];
			minheap[i]=minheap[2*i+1];
			minheap[2*i+1]=temp;
			i=2*i+1;
		}
		else
		{
			temp=minheap[i];
			minheap[i]=minheap[2*i];
			minheap[2*i]=temp;
			i=2*i;
		}

	}
}
void insertmin(ll p)
{
	if(flag==0)
	{
		minheap[minhead++]=p;
		flag=1;

	}
	else
	{
		ll j,temp;
		minheap[minhead]=p;
		j=minhead;
		while(minheap[j]<minheap[j/2] && j>1)
		{
			//	swap(heap[j],heap[j/2]);
			temp=minheap[j];
			minheap[j]=minheap[j/2];
			minheap[j/2]=temp;

			j=j/2;
		}
		minhead++;
	}
}
ll inver[100003]={0};
int main()
{
	ll n,m,p,q,i;
	scanf("%lld%lld",&n,&m);
	ll k=m;
	while(k--)
	{
		scanf("%lld%lld",&p,&q);
		insert(p,q);
		inver[q]++;
	}
	for(i=1;i<=n;i++)
	{
		if(inver[i]==0)
		{
			insertmin(i);
		}
	}
	node*te=NULL;
	int op=0;
	
	while(minhead>1)
//	while(op--)
	{
		if(op==1)
		printf(" ");
		ll x=minheap[1];
		deletemin(1);
		printf("%lld",x);
		

		//if(arr[x]!=NULL)
		te=arr[x];
	//	break;
		while(te!=NULL)
		{
			inver[te->a]--;
			if(inver[te->a]==0)
				insertmin(te->a);
			te=te->next;
		}
		op=1;
	}

	printf("\n");
	return 0;
}
