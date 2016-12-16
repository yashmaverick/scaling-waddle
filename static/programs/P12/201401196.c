#include<stdio.h>
#include<stdlib.h>
int ans=0;
struct link
{
	int data;
	int wt;
	struct link* ptr;
};
struct link* head=NULL;
struct link* new;
void push(int x)
{
	new = (struct link*)malloc(sizeof(struct link));
	new->data=x;
	new->wt=1;
	new->ptr=head;
	head=new;
	return ;
}
void pop(int x)
{
	while(x>head->data && head!=NULL)
	{
		head=head->ptr;
		if(head==NULL)
		{
			new = (struct link*)malloc(sizeof(struct link));
			new->data = x;
			new->wt = 1;
			new->ptr = head;
			head = new;
			break;
		}
		else
		{
			if(head->data==x)
			{
				ans+=head->wt;
				head->wt++;
				break;
			}
			else if(head->data>x)
			{
				new = (struct link*)malloc(sizeof(struct link));
				new->data = x;
				new->wt = 1;
				new->ptr = head;
				head = new;
				break;
			}
		}
	}
	return ;
}
int main()
{

	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		ans=0;
		head=NULL;
		int maximum,maximum1,i,j,k,l,m,a[100000];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		maximum=a[0];
		maximum1=a[n-1];
		for(i=1;i<n;i++)
		{
			if(a[i]<maximum)
				ans++;
			else
				maximum=a[i];
			if(a[n-i-1]<maximum1)
				ans++;
			else
				maximum1=a[n-i-1];
		}
		new = (struct link*)malloc(sizeof(struct link));
		new->data = a[0];
		new->wt=1;
		new->ptr=head;
		head=new;
		for(i=1;i<n;i++)
		{
			if(a[i]<head->data)
			{
				push(a[i]);
			}
			else if(a[i]>head->data)
			{
				pop(a[i]);
			}
			else
			{
				ans = ans+head->wt;
				head->wt++;
			}
		}
		printf("%d\n",n*(n-1)/2-ans);
		scanf("%d",&n);
	}
	return 0;
}
