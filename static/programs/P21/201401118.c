#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
	struct ll *next;
	long long int val;
	long long int weight;
	int status;
}list;
list *a[100010],*b[100010];
long long int rear=1,pre=0;
void delete()
{
	long long int i,s;
	list *temp;
	a[b[1]->val]->status=1;
	b[1]=b[rear];
	rear--;
	if(rear==0)
		pre=1;
	i=1;
	while(i<=rear/2)
	{
		s=2*i;
		if(2*i+1<=rear)
		{
			if(b[2*i]->weight>b[2*i+1]->weight)
				s=2*i+1;
		}
		if(b[i]->weight>b[s]->weight)
		{
			temp=b[i];
			b[i]=b[s];
			b[s]=temp;
		}
		i=s;
	}
	return;
}
void update(long long int k)
{
	long long int j;
	list *ins,*temp;
	rear++;
	ins=(list *)malloc(sizeof(list));
	ins->val=k;
	ins->weight=a[k]->weight;
	ins->status=0;
	b[rear]=ins;
	j=rear;
	while(j>1)
	{
		if(b[j]->weight<b[j/2]->weight)
		{
			temp=b[j];
			b[j]=b[j/2];
			b[j/2]=temp;
		}
		j=j/2;
	}
	return;
}
int main()
{
	long long int n,m;
	scanf("%lld %lld",&n,&m);
	long long int i;
	list *temp,*ins;
	for(i=1;i<=n;i++)
	{
		a[i]=(list *)malloc(sizeof(list));
		a[i]->val=i;
		a[i]->weight=1000000007;
		a[i]->status=0;
		a[i]->next=NULL;
	}
	long long int x,y,z;
	for(i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&z);
		temp=a[x];
		ins=(list *)malloc(sizeof(list));
		ins->val=y;
		ins->weight=z;
		ins->status=0;
		ins->next=temp->next;
		temp->next=ins;
	}
	long long int f,c,d;
	scanf("%lld %lld",&f,&d);
	c=f;
	a[f]->weight=0;
	b[1]=(list *)malloc(sizeof(list));
	b[1]->val=c;
	b[1]->weight=0;
	b[1]->status=0;
	while(c!=d)
	{
		temp=a[c];
		temp=temp->next;
		while(temp!=NULL)
		{
			if(a[temp->val]->status==0)
			{
				if(a[temp->val]->weight>temp->weight+a[c]->weight)
				{
					a[temp->val]->weight=temp->weight+a[c]->weight;
					update(temp->val);
				}
			}
			temp=temp->next;
		}
		delete();
		c=b[1]->val;
		if(pre==1)
			break;
	}
	if(pre==1)
		printf("NO\n");
	else if(pre==0)
		printf("%lld\n",a[d]->weight);
	return 0;
}
