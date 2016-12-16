#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
	struct ll *next;
	long long int val;
	long long int status;
	long long int weight;
}list;
list *a[1000010],*b[1000010];
long long int sum=0,rear=0,flag=0;
void update(long long int k)
{
//	printf("update\n");
	list *temp,*ins;
	int j;
	rear++;
	ins=(list *)malloc(sizeof(list));
	ins->val=k;
	ins->status=0;
	ins->weight=a[k]->weight;
	b[rear]=ins;
	j=rear;
	while(j>2 && j>3)
	{
		if(b[j]->weight<b[j/2]->weight)
		{
			temp=b[j];
			b[j]=b[j/2];
			b[j/2]=temp;
		}
		j=j/2;
	}
//	printf("complete\n");
	return;
}
void delete()
{
	list *temp;
	long long int s,k;
	b[1]=b[rear];
	rear--;
	k=1;
	while(k<=rear/2)
	{
		s=2*k;
		if(2*k+1<=rear)
		{
			if(b[2*k]->weight>b[2*k+1]->weight)
				s=2*k+1;
		}
		if(b[s]->weight<b[k]->weight)
		{
			temp=b[s];
			b[s]=b[k];
			b[k]=temp;
		}
		k=s;
	}
	return;
}
int main()
{
	long long int n,m,c;
	scanf("%lld %lld",&n,&m);
	int i;
	for(i=1;i<=n;i++)
	{
		a[i]=(list *)malloc(sizeof(list));
		a[i]->val=i;
		a[i]->weight=10000007;
		a[i]->status=0;
		a[i]->next=NULL;
	}
	long long int x,y,z;
	list *tx,*ty,*ins1,*ins2;
	for(i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&z);
		tx=a[x];
		ty=a[y];
		ins1=(list *)malloc(sizeof(list));
		ins2=(list *)malloc(sizeof(list));
		ins1->val=x;
	 	ins2->val=y;
		ins1->weight=ins2->weight=z;
		ins1->status=ins2->status=0;
		ins1->next=a[y]->next;
		ins2->next=a[x]->next;
		a[x]->next=ins2;
		a[y]->next=ins1;
	}
	list *head;
//	for(i=1;i<=n;i++)
//	{
//		head=a[i];
//		while(head!=NULL)
//		{
//			printf("%lld=%lld",head->val,head->weight);
//			head=head->next;
//		}
//		printf("\n");
//	}
	b[1]=(list *)malloc(sizeof(list));
	b[1]->val=1;
	b[1]->status=0;
	b[1]->weight=0;
	a[1]->weight=0;
	rear++;
	c=1;
	list *temp;
	while(rear>=1)
	{
		temp=a[c];
		sum+=a[c]->weight;
		temp=temp->next;
		while(temp!=NULL)
		{
			if(a[temp->val]->status==0)
			{
				if(a[temp->val]->weight>temp->weight)
				{
//					printf("temp=%lld\n",temp->val);
					a[temp->val]->weight=temp->weight;
					update(temp->val);
				}
			}
			temp=temp->next;
		}
//		for(i=1;i<=rear;i++)
//			printf("val=%lld weight=%lld\n",b[i]->val,b[i]->weight);
		a[c]->status=1;
	//	printf("top=%lld\n",a[b[1]->val]->status);
		while(a[b[1]->val]->status!=0)
		{
//			printf("$\n");
			delete();
			if(rear==0)
				break;
		}
		c=b[1]->val;
//		printf("top=%lld",c);
	}
//	printf("flag=%lld\n",flag);
	for(i=1;i<=n;i++)
	{
		if(a[i]->status==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("-1\n");
	else if(flag==0)
		printf("%lld\n",sum);
	return 0;
}
