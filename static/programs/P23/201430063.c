#include<stdio.h>
#include<stdlib.h>
int a[100005];
int size=0;
typedef struct topo
{
	struct topo *next;
	int val;
	int count;
}topo;
topo *head[100005];
void create(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{	
		head[i]=(topo*)malloc(sizeof(topo));
		head[i]->next=NULL;
		head[i]->count=0;
		head[i]->val=i;
	}
}
void insert1(int u,int v)
{
	topo *temp;
	topo *temp1;
	temp1=head[u];
	temp=temp1->next;
	temp1->next=(topo*)malloc(sizeof(topo));
	temp1->next->val=v;
	temp1->next->next=temp;            
	head[v]->count++;
}

void insert(int c) 
{
	size++;
	a[size]=c;
	int temp;
	int i=size;
	while(i!=1 && a[i/2]>a[i]) 
	{
		temp=a[i/2];
		a[i/2]=a[i];
		a[i]=temp;
		i=i/2;
	}

}
void delete()
{
	a[1]=a[size];
	size--;
	int i=1;
	int temp,l,r,flag,j;
	while(1)
	{
		l=2*i;
		r=2*i+1;
		if(l<=size && a[i]>a[l])
		{	
			if(r>size)
			{
				temp=a[i];
				a[i]=a[l];
				a[l]=temp;
				i=l;  
			}
			else
			{
				if(a[r]>a[l])
				{
					temp=a[i];
					a[i]=a[l];
					a[l]=temp;
					i=l;  
				}
				else
				{
					temp=a[i];
					a[i]=a[r];
					a[r]=temp;
					i=r;  
				}
			}
		}
		else  if(r<=size&&a[i]>a[r])
		{

			temp=a[i];
			a[i]=a[r];
			a[r]=temp;
			i=r; 

		}
		else
			break;

	}
}
void print(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		topo *temp=head[i];
		while(temp!=NULL)
		{
			printf("%d->",temp->val);
			temp=temp->next;
		}
		printf("\n");
	}
}


int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	int ans[n];
	int j;
	int i,u,v;
	create(n);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&u,&v);
		insert1(u,v);
	}
	for(i=1;i<=n;i++)
		if(head[i]->count==0)
			insert(i);
//	for(i=1;i<=size;i++)
//		printf("%d ",a[i]);
//	putchar(10);



	int k;
	int co=0;
	topo *temp;
	while(size!=0)
	{
		ans[co]=a[1];
		co++;
		k=a[1];
		delete();
//		printf("AFTER DELETE\n");
//		for(i=1;i<=size;i++)
//			printf("%d ",a[i]);
//	putchar(10);
		temp=head[k]->next;
		while(temp!=NULL)
		{
			head[temp->val]->count--;
			if(head[temp->val]->count==0)
				insert(temp->val);
			temp=temp->next;
		}
			
//		printf("after insert\n");
//		for(i=1;i<=size;i++)
//			printf("%d ",a[i]);
//	putchar(10);
	}
	for(i=0;i<co-1;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[co-1]);
	return 0;
}

