#include<stdio.h>
//#include<stdlib.h>
/*struct node {
	long long int val;
	struct node* next;
};
typedef struct node node;
node* push(node* head,long long int n)
{
	node* a;
	a=malloc(sizeof(node));
	a->val=n;
	a->next=head;
	return a;
}
node* pop(node *head)
{
	return head->next;
}
long long int top(node *head)
{
	if(head==NULL)
		return -1;
	return head->val;
}*/
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int a[n],b[n],c[n];
		long long int i,j;
		long long int max=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		b[0]=-1;
		for(i=1;i<n;i++)
		{
			j=i-1;
			if(a[j]<a[i])
				b[i]=j;
			else
			{
				while(b[j]!=-1)
				{
					if(a[b[j]]<a[i])
					{
						b[i]=b[j];
						break;
					}
					else
						j=b[j];
				}
				if(b[j]==-1)
				{
					b[i]=-1;
				}
			}
		}
//			for(i=0;i<n;i++)
//				printf("%lld ",b[i]);
//			printf("\n");
	//	free(head);
	//	head=NULL;i
		c[n-1]=n;
		for(i=n-2;i>=0;i--)
		{
			j=i+1;
			if(a[j]<a[i])
				c[i]=j;
			else
			{
				while(c[j]!=n)
				{
					if(a[c[j]]<a[i])
					{
						c[i]=c[j];
						break;
					}
					else
						j=c[j];
				}
				if(c[j]==n)
				{
					c[i]=n;
				}
			}
		}
		//	node *head=NULL;
	/*	for(i=n-1;i>=0;i--)
		{

			while(top(head)!=-1)
			{
				if(a[top(head)]<a[i])
				{
					c[i]=top(head);
					head=push(head,i);
					break;
				}
				else
					head=pop(head);
			}
			if(top(head)==-1)
			{
				c[i]=n;
				head=push(head,i);
			}
		}*/
//			for(i=0;i<n;i++)
//		printf("%lld ",c[i]);
//			printf("\n");
		for(i=0;i<n;i++)
		{
			//		printf("%lld ",a[i]*(c[i]-b[i]-1));
			if(max<a[i]*(c[i]-b[i]-1))
				max=a[i]*(c[i]-b[i]-1);
		}
		//	printf("\n");
		printf("%lld\n",max);
		scanf("%lld",&n);
//		free(head);
	}
	return 0;
}
