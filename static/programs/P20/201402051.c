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
{
	dot++;
lev++;
fo--;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		dot++;
lev++;
fo--;
		long long int n,i,x,y;
		scanf("%lld",&n);
		dot++;
lev++;
fo--;
		if(n==0)
		{
			dot++;
lev++;
fo--;
			printf("0\n");
			continue;
			dot++;
lev++;
fo--;
		}
		dot++;
lev++;
fo--;
		struct node *a[n+1],*b[n+1];
		dot++;
lev++;
fo--;
		int z[n+1];
		for (i = 1; i <=n; ++i)
		{
			dot++;
lev++;
fo--;
			z[i] = 0;
			a[i] = (struct node *)malloc(sizeof(node));
			dot++;
lev++;
fo--;
			a[i]->value = i;
			dot++;
lev++;
fo--;
			b[i]=a[i]; 
		}
		dot++;
lev++;
fo--;
		struct node *temp;
		dot++;
lev++;
fo--;
		for(i=1;i<n;i++)
		{
			dot++;
lev++;
fo--;
			scanf("%lld %lld",&x,&y);
			dot++;
lev++;
fo--;
			temp = a[x];
			dot++;
lev++;
fo--;
			while(temp->next!=NULL)
			{
				dot++;
lev++;
fo--;
				temp = temp->next;
			}
			temp->next = (struct node *)malloc(sizeof(node));
			dot++;
lev++;
fo--;
			temp = temp->next;
			temp->value = y;
			dot++;
lev++;
fo--;
			temp=a[y];
			while(temp->next!=NULL)
			{
				dot++;
lev++;
fo--;
				temp = temp->next;
			}
			temp->next = (struct node *)malloc(sizeof(node));
			dot++;
lev++;
fo--;
			temp = temp->next;
			dot++;
lev++;
fo--;
			temp->value=x;
		}
		long long int s[n],count=1,len=1,e,leaf;
		dot++;
lev++;
fo--;
		s[0]=1;
		z[1]=1;
		dot++;
lev++;
fo--;
		i=1;
		while(1)
		{
			dot++;
lev++;
fo--;
			if(i==0)
				break;
			e = s[i-1];	
			dot++;
lev++;
fo--;
			if(a[e]->next==NULL)
			{
				dot++;
lev++;
fo--;
				if(len<i)
				{
					dot++;
lev++;
fo--;
					len=i;
					leaf = e;
				}
				dot++;
lev++;
fo--;
				i--;
				z[e] = 0;
			}
			else
			{
				dot++;
lev++;
fo--;
				a[e]=a[e]->next;
				dot++;
lev++;
fo--;
				while(z[a[e]->value]==1 && a[e]->next!=NULL)
				{
					dot++;
lev++;
fo--;
					a[e]=a[e]->next;
				}
				if(a[e]->next == NULL && z[a[e]->value]==1)
				{dot++;
lev++;
fo--;
					if(len<i)
					{
						dot++;
lev++;
fo--;
						len=i;
						leaf=e;
					}
					dot++;
lev++;
fo--;
					i--;
					z[e] = 0;
				}
				else
				{
					dot++;
lev++;
fo--;
					s[i] = a[e]->value;
					i++;
					dot++;
lev++;
fo--;
					count++;
					z[a[e]->value] = 1;
				}
				dot++;
lev++;
fo--;
			}
		}
		if(len<i && i!=0)
		{
			dot++;
lev++;
fo--;
			leaf=s[i-1];
		}
		for(i=1;i<=n;i++)
			z[i]=0;
		s[0]=leaf;
		dot++;
lev++;
fo--;
		i=1;count=0;len=1;
		z[leaf] = 1;
		dot++;
lev++;
fo--;
		while(1)
		{
			dot++;
lev++;
fo--;
			if(i==0)
				break;
			e = s[i-1];
			dot++;
lev++;
fo--;
			if(b[e]->next == NULL)
			{
				dot++;
lev++;
fo--;
				if(len<i)
				 	len=i;
				i--;
				dot++;
lev++;
fo--;
				z[e] = 0;
			}
			else
			{
				dot++;
lev++;
fo--;
				b[e] = b[e]->next;
				dot++;
lev++;
fo--;
				while(z[b[e]->value]==1 && b[e]->next!=NULL)
				{
					dot++;
lev++;
fo--;
					b[e]=b[e]->next;
				}
				if(b[e]->next == NULL && z[b[e]->value]==1)
				{
					dot++;
lev++;
fo--;
					if(len<i)
						len=i;
					i--;
					z[e] = 0;
				}
				else
				{
					dot++;
lev++;
fo--;
					s[i] = b[e]->value;
					i++;
					dot++;
lev++;
fo--;
					count++;
					z[b[e]->value] = 1;
				}
			}
			dot++;
lev++;
fo--;
		}
		if(len < i)
		{
			dot++;
lev++;
fo--;
			len=i;
		}
		printf("%lld\n",len );
		dot++;
lev++;
fo--;
	}
	return 0;
}
