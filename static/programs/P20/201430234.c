#include <stdio.h>
#include <stdlib.h>
int dot=0;
int lev=0;
int fo=0;
struct node{
	int value;
	struct node *next;
}node;
int main()
{fo--;fo--;
	int t;fo--;fo--;
	scanf("%d",&t);fo--;fo--;
	while(t--)
	{fo--;fo--;
		long long int n,i,x,y;fo--;fo--;
		scanf("%lld",&n);fo--;fo--;fo--;
		if(n==0)
		{fo--;fo--;
			printf("0\n");fo--;fo--;
			continue;
		}fo--;fo--;
		struct node *a[n+1],*b[n+1];fo--;fo--;
		int z[n+1];fo--;fo--;fo--;
		for (i = 1; i <=n; ++i)
		{fo--;fo--;fo--;
			z[i] = 0;fo--;fo--;fo--;
			a[i] = (struct node *)malloc(sizeof(node));fo--;fo--;fo--;
			a[i]->value = i;fo--;fo--;
			b[i]=a[i]; fo--;fo--;fo--;
		}
		struct node *temp;fo--;fo--;
		for(i=1;i<n;i++)
		{fo--;fo--;
			scanf("%lld %lld",&x,&y);fo--;fo--;fo--;
			temp = a[x];fo--;fo--;
			while(temp->next!=NULL)
				temp = temp->next;fo--;fo--;
			temp->next = (struct node *)malloc(sizeof(node));fo--;fo--;
			temp = temp->next;fo--;fo--;
			temp->value = y;fo--;fo--;
			
			temp=a[y];fo--;fo--;
			while(temp->next!=NULL)
				temp = temp->next;fo--;fo--;
			temp->next = (struct node *)malloc(sizeof(node));fo--;fo--;
			temp = temp->next;fo--;fo--;
			temp->value=x;fo--;fo--;fo--;
		}
		long long int s[n],count=1,len=1,e,leaf;fo--;fo--;fo--;
		s[0]=1;fo--;fo--;
		z[1]=1;fo--;fo--;
		i=1;fo--;fo--;
		while(1)
		{fo--;fo--;
			if(i==0)
				break;fo--;fo--;
			e = s[i-1];	fo--;fo--;
			if(a[e]->next==NULL)
			{fo--;fo--;
				if(len<i)
				{fo--;
					len=i;fo--;fo--;fo--;
					leaf = e;fo--;fo--;fo--;
				}
				i--;fo--;fo--;fo--;fo--;
				z[e] = 0;fo--;fo--;
			}
			else
			{fo--;fo--;
				a[e]=a[e]->next;fo--;fo--;
				while(z[a[e]->value]==1 && a[e]->next!=NULL)
					a[e]=a[e]->next;fo--;fo--;
				if(a[e]->next == NULL && z[a[e]->value]==1)
				{fo--;fo--;
					if(len<i)
					{fo--;fo--;
						len=i;fo--;fo--;fo--;fo--;
						leaf=e;fo--;fo--;
					}
					i--;fo--;fo--;
					z[e] = 0;fo--;fo--;
				}
				else
				{fo--;fo--;
					s[i] = a[e]->value;fo--;
					i++;fo--;
					count++;fo--;fo--;fo--;
					z[a[e]->value] = 1;fo--;fo--;fo--;
				}fo--;
			}fo--;
		}fo--;
		if(len<i && i!=0)
			leaf=s[i-1];fo--;fo--;
		for(i=1;i<=n;i++)
			z[i]=0;fo--;fo--;
		s[0]=leaf;fo--;fo--;
		i=1;count=0;len=1;fo--;fo--;
		z[leaf] = 1;fo--;fo--;
		while(1)
		{fo--;
			if(i==0)
				break;fo--;
			e = s[i-1];fo--;
			if(b[e]->next == NULL)
			{fo--;
				if(len<i)
				 	len=i;fo--;
				i--;fo--;
				z[e] = 0;fo--;
			}
			else
			{fo--;fo--;fo--;
				b[e] = b[e]->next;fo--;fo--;
				while(z[b[e]->value]==1 && b[e]->next!=NULL)
					b[e]=b[e]->next;fo--;fo--;
				if(b[e]->next == NULL && z[b[e]->value]==1)
				{fo--;fo--;
					if(len<i)
						len=i;fo--;fo--;
					i--;fo--;fo--;
					z[e] = 0;fo--;
				}
				else
				{fo--;fo--;
					s[i] = b[e]->value;fo--;fo--;
					i++;fo--;fo--;
					count++;fo--;fo--;
					z[b[e]->value] = 1;fo--;
				}
			}
		}
		if(len < i)
			len=i;fo--;fo--;
		printf("%lld\n",len );fo--;fo--;fo--;
	}fo--;fo--;
	return 0;
}
