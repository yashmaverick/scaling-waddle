#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link[10];
};

struct node* create()
{
	struct node* q=(struct node*)malloc(sizeof(struct node));
	q->data=0;
	return q;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int i,n,a[100005],flag=0,num;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		struct node* root=(struct node*)malloc(sizeof(struct node));
		for(i=0;i<n;i++)
		{
			struct node* q=root;
			int it=0;
			long long int temp,p,b[100005];
			while(a[i]!=0)
			{
				b[it]=a[i]%10;
				a[i]=a[i]/10;
				it++;
			}
			it--;
			while(it>=0)
			{
				temp=b[it];
				//printf("%lld\n",temp);
				it--;
				if(q->link[temp]==NULL)
				{
					q->link[temp]=create();
				}
				else
				{
					if(q->link[temp]->data==1)
					{
						flag=1;
						break;
					}
					if(it==-1)
					{
						for(i=0;i<10;i++)
						{
							if(q->link[i]!=NULL)
							{
								flag =1;
								break;
							}
						}
					}
				}
				q=q->link[temp];
			}
			q->data=1;
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}