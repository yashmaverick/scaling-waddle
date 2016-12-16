#include<stdio.h>
#include<stdlib.h>

int number[11111];
int vis[11111];

void sieve()
{
	int i,j;
	i=2;
	while(i<=100)
	{
		if(number[i]==0)
		{
			j=2;
			while(i*j<=9999)
			{
				number[i*j]=1;
				j++;
			}
		}
		i++;
	}
	return;
}
struct pair
{
	int val;
	int lev;
};

int front;
int last;
struct pair qu[11111];


typedef struct list
{
	int value;
	struct list *next;
}list;

list *insert(list *head,int ver)
{
	list *new;
	new=(list *)malloc(sizeof(list));
	new->value=ver;
	new->next=NULL;
	list *temp;
//	temp=malloc(sizeof(list));
	temp=head;
	if(head==NULL)
	{
//		head=malloc(sizeof(list));
		head=new;
		return head;
	}
	else
	{
		new->next=temp;
		head=new;
		return head;
	}
}

int main()
{
	list *head[11111];

	int i,prime[11111],j=0,k;

	for(i=0;i<=11000;i++)
		number[i]=0;
	sieve();
	for(i=10000;i<=11111;i++)
		number[i]=-1;

	j=0;
	for(i=1000;i<=9999;i++)
	{
		if(number[i]==0)
		{
			prime[j]=i;
			j++;
		}
	}
	for(i=0;i<j;i++)
	{
		head[prime[i]]=NULL;
	}

	int l,count,l1,count1;
	for(i=0;i<j;i++)
	{

		l1=prime[i];
		l=prime[i];
		count=l1/1000;
		while(count<9)
		{	
			l=l+1000;
			if(number[l]==0)
			{
				head[prime[i]]=insert(head[prime[i]],l);
				head[l]=insert(head[l],prime[i]);
			}
			count++;
		}

		l1=prime[i];
		l=prime[i];
		count=l1/100-((l1/1000)*10);
		count1=l1/100-((l1/1000)*10);
		while(count1<9)
		{
			l=l+100;
			if(number[l]==0)
			{	
				head[prime[i]]=insert(head[prime[i]],l);
				head[l]=insert(head[l],prime[i]);
			}
			count1++;
		}

		l1=prime[i];
		l=prime[i];
		count=l1/10-((l1/100)*10);
		count1=l1/10-((l1/100)*10);
		while(count1<9)
		{
			l=l+10;
			if(number[l]==0)
			{
				head[prime[i]]=insert(head[prime[i]],l);
				head[l]=insert(head[l],prime[i]);
			}
			count1++;
		}

		l1=prime[i];
		l=prime[i];
		count=l1-((l1/10)*10);
		count1=l1-((l1/10)*10);
		while(count1<9)
		{
			l=l+1;
			if(number[l]==0)
			{
				head[prime[i]]=insert(head[prime[i]],l);
				head[l]=insert(head[l],prime[i]);
			}
			count1++;
		}
	}
	/*for(i=0;i<j;i++)
	{
		list *temp=head[prime[i]];
		printf("%d ->>",prime[i]);
		while(temp!=NULL)
		{
			printf("%d ",temp->value);
			temp=temp->next;
		}
		printf("\n");
	}*/
	
	int t,n1,n2;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10001;i++)
			vis[prime[i]]=0;
		front=0;
		last=-1;
		scanf("%d %d",&n1,&n2);
		if (n1==n2)
		{
			printf("0\n");	continue;
		}
		int d,dlev,out,count=0;
		
		last++;
		qu[last].val=n1;
		qu[last].lev=0;
		vis[n1]=1;
		
		list *temp1;
		temp1=malloc(sizeof(list));
		while(front <= last)
		{
			d=qu[front].val;
			dlev=qu[front].lev;
			front++;
			if(d==n2)
			{
				printf("%d\n",dlev);
				vis[d]=1;
				break;
			}
			temp1=head[d];
			while(temp1!=NULL)
			{
				if(vis[temp1->value]==0)
				{
					vis[temp1->value]=1;
					last++;
					qu[last].val=temp1->value;
					qu[last].lev=dlev+1;
				}
				temp1=temp1->next;
			}
		}
		if (vis[n2]==0)
			printf("Impossible\n");
	}
	return 0;
}
