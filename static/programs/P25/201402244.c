#include<stdio.h>
#include<stdlib.h>
long long int final;
long long int a[100003];
typedef struct node
{
	long long int wei;
	long long int val;
	struct node* next;
}node;
node **head;
void insert(long long int value,long long int f,long long int weight)
{
	node *new=(node*)malloc(sizeof(node));
	new->val=value;
	new->next=NULL;
	new->wei=weight;
	node *p=head[f];
	node *q=head[f];
	if(head[f]==NULL)
	{
		head[f]=new;
		return;
	}
	if(weight<=p->wei)
	{
		new->next=head[f];
		head[f]=new;
		return;
	}
	while(p!=NULL&&p->wei<weight)
	{
		q=p;
		p=p->next;
	}
	q->next=new;
	new->next=p;
	return;
}
long long int main()
{
	long long int n,i,e;
	final=0;
	scanf("%lld%lld",&n,&e);
	int rt[100003];
	if(e>0)
	{
		head=(node**)malloc((n+1)*sizeof(node));
		for(i=1;i<=n;i++)
		{
			rt[i]=0;
			head[i]=NULL;
		}
		long long int c,b,w;
		scanf("%lld%lld%lld",&c,&b,&w);
		insert(b,c,w);
		insert(c,b,w);
		rt[c]=1;
		rt[b]=1;
		for(i=1;i<e;i++)
		{
			scanf("%lld%lld%lld",&c,&b,&w);
			insert(b,c,w);
			insert(c,b,w);
			rt[c]=1;
			rt[b]=1;
		}
		long long int state=1;
		for(i=1;i<=n;i++)
		{
			if(rt[i]==0)
			{
				state=0;
				printf("-1\n");
			break;
			}
		}
		/*if(e<n-1)
		{
			printf("-1\n");
			state=0;
		}*/
		if(state==1)
		{
			long long int top=0;
			long long int check=0;
			i=1;
			long long int j;
			node **p;
			p=(node**)malloc((n+1)*sizeof(node));
			for(j=1;j<=n;j++)
			{
				p[j]=head[j];
			}
			long long int stack[100003];
			long long int min,k;
			long long int temp;
			long long int h[100003];
			a[1]=1;
			stack[top]=1;
			top++;
			long long int count=0;
			while(check==0)
			{
				count++;
				long long int vu;
				min=0;
				long long int tem;
				for(j=0;j<top;j++)
				{
					if(h[j]!=1)
					{
						while(a[p[stack[j]]->val]==1&&p[stack[j]]->next!=NULL)
						{
							p[stack[j]]=p[stack[j]]->next;
						}
						if(p[stack[j]]->next==NULL)
						{
							if(a[p[stack[j]]->val]==1)
								h[j]=1;
							else
							{
								min=p[stack[j]]->wei;
								vu=p[stack[j]]->val;
								break;
							}
						}
						else
						{
							min=p[stack[j]]->wei;
							vu=p[stack[j]]->val;
							break;
						}
					}
				}
				if(h[j]!=1)
				{
					for(k=j+1;k<top;k++)
					{
						if(h[k]!=1)
						{
							while(a[p[stack[k]]->val]==1&&p[stack[k]]->next!=NULL)
							{
								p[stack[k]]=p[stack[k]]->next;
							}
							if(p[stack[k]]->next==NULL)
							{
								if(a[p[stack[k]]->val]==1)
									h[k]=1;
								else
								{
									if(min>p[stack[k]]->wei)
									{
										min=p[stack[k]]->wei;
										vu=p[stack[k]]->val;
									}
								}
							}
							else
							{
								if(min>p[stack[k]]->wei)
								{
									vu=p[stack[k]]->val;
									min=p[stack[k]]->wei;
								}
							}
						}
					}
				} 
				a[vu]=1;
				stack[top]=vu;
				top++;
				final=final+min;
				if(count==n-1)
					check=1;
			}
			int rp=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					rp=1;
					printf("-1\n");
					break;
				}
			}
			if(rp==0)
			printf("%lld\n",final);
		}
	}
	else if (e==0)
	{
		printf("-1\n");
	}
	return 0;
}
