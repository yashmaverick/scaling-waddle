#include <stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node *next;
}node;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,i,x,y;
		scanf("%lld",&n);
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		struct node *a[n+1],*b[n+1];
		int z[n+1];
		for (i = 1; i <=n; ++i)
		{
			z[i] = 0;
			a[i] = (struct node *)malloc(sizeof(node));
			a[i]->value = i;
			b[i]=a[i]; 
		}
		struct node *temp;
		for(i=1;i<n;i++)
		{
			scanf("%lld %lld",&x,&y);
			temp = a[x];
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next = (struct node *)malloc(sizeof(node));
			temp = temp->next;
			temp->value = y;
			
			temp=a[y];
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next = (struct node *)malloc(sizeof(node));
			temp = temp->next;
			temp->value=x;
			//b[y] = -1;
		}
		// for(i=1;i<=n;i++)
		// {
		// 	temp = a[i];
		// 	while(temp!=NULL)
		// 	{
		// 		printf("%d",temp->value );
		// 		printf("->");
		// 		temp=temp->next;
		// 	}
		// 	printf("\n");
		// }
		long long int s[n],count=1,len=1,e,leaf;
		s[0]=1;
		z[1]=1;
		i=1;
		while(1)
		{
			// if(count == n)
			// 	break;
			if(i==0)
				break;
			e = s[i-1];	
			if(a[e]->next==NULL)
			{
				if(len<i)
				{
					len=i;
					leaf = e;
				}
				i--;
				z[e] = 0;
			}
			else
			{
				a[e]=a[e]->next;
				while(z[a[e]->value]==1 && a[e]->next!=NULL)
					a[e]=a[e]->next;
				if(a[e]->next == NULL && z[a[e]->value]==1)
				{
					if(len<i)
					{
						len=i;
						leaf=e;
					}
					i--;
					z[e] = 0;
				}
				else
				{
					s[i] = a[e]->value;
					//printf("..%lld.. %lld\n",i,s[i] );
					i++;
					count++;
					z[a[e]->value] = 1;
				}
			}
		}
		if(len<i && i!=0)
			leaf=s[i-1];
		for(i=1;i<=n;i++)
			z[i]=0;
		//printf("leaf is %lld\n", leaf);
		s[0]=leaf;
		i=1;count=0;len=1;
		z[leaf] = 1;
		while(1)
		{
			// if(count == n)
			// 	break;
			if(i==0)
				break;
			e = s[i-1];
			if(b[e]->next == NULL)
			{
				if(len<i)
				 	len=i;
				i--;
				z[e] = 0;
			}
			else
			{
				b[e] = b[e]->next;
				while(z[b[e]->value]==1 && b[e]->next!=NULL)
					b[e]=b[e]->next;
				if(b[e]->next == NULL && z[b[e]->value]==1)
				{
					if(len<i)
						len=i;
					i--;
					z[e] = 0;
				}
				else
				{
					s[i] = b[e]->value;
					//printf("..%lld.. %lld\n",i,s[i] );
					i++;
					count++;
					z[b[e]->value] = 1;
				}
			}
		}
		if(len < i)
			len=i;
		printf("%lld\n",len );
	}
	return 0;
}