#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	int value;
	int index;
	int count;
	struct stack *next;
}stack;
 
typedef struct stack* link;

link head=NULL;

void pop()
{
	if(head==NULL) return;

	link temp=head;
	head=head->next;
	free(temp);
}


int push(int x,int i)
{
	if(head==NULL)
	{
		head=malloc(sizeof(stack));
		head->value=x;
		head->index=i;
		head->next=NULL;
		return -1;
	}

/*
 if(x==head->value)
	{
	 int temp=head->index;
	 head->index=i;
	 return temp;
	}
*/
	if(x<head->value)
	{
		link temp;
		temp=malloc(sizeof(stack));
		temp->value=x;
		temp->index=i;
		temp->next=head;
		head=temp;
		return head->next->index;
	}

	pop();
	return push(x,i);
}

int ind(int x,int i,int n,int a[n][3])
{
	int t,p;
	t=a[i][1];
	if(t==-1) return -1;
	p=a[t][0];
	
	if(p>x) return t;

	return ind(x,t,n,a);
}

int ind1(int x,int i,int n,int a[n][3])
{
	int t,p;
	t=a[i][2];
	if(t==-1) return -1;
	p=a[t][0];
	
	if(p>x) return t;

	return ind1(x,t,n,a);
}


int main()
{
	long long int n;
	long long int ans=0;
	scanf("%lld",&n);
	while(n!=0)
	{
		head=NULL;
		ans=(n*(n-1))/2;

		int a[n][3];
		int b[n];
		int i=0;
		for(i=0;i<n;i++)
		{
			b[i]=0;
			int x;
			scanf("%d",&x);
			a[i][0]=x;
			a[i][1]=push(x,i);
		}

		while(head!=NULL) pop();

		for(i=n-1;i>=0;i--)
		{
			a[i][2]=push(a[i][0],i);
		}

		while(head!=NULL) pop();
		

		for(i=n-1;i>=1;i--)
		{
			int te=a[i][1];
			if(te!=-1) b[te]++;
		}
		for(i=n-1;i>=1;i--)   b[i-1]+=b[i];

		long long int temp=0;
		for(i=0;i<n-1;i++)
		{
			int left=a[i][2];

			if(left==-1)
			{
				temp+=(n-i-1)-b[i+1];
			}
			else
			{
				temp+=(left-i)-(b[i+1]-b[left]);
			}
		}


	//	printf("temp:%lld\n",temp);

		printf("%lld\n",ans-temp);
		scanf("%lld",&n);
	}	
	return 0;
}