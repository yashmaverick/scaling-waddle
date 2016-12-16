#include <stdio.h>
#include <stdlib.h>
int mine=0;
int level=0;
int form=0;
struct node{
	int value;
	struct node *next;
}node;
int main()
{
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int t;
	scanf("%d",&t);
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	while(t--)
	{
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		long long int n,i,x,y;
		scanf("%lld",&n);
		if(n==0)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			printf("0\n");
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			continue;
		}
		struct node *a[n+1],*b[n+1];
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		int z[n+1];
		for (i = 1; i <=n; ++i)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			z[i] = 0;
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			a[i] = (struct node *)malloc(sizeof(node));
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			a[i]->value = i;
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			b[i]=a[i]; 
		}
		struct node *temp;
		for(i=1;i<n;i++)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			scanf("%lld %lld",&x,&y);
			temp = a[x];
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			while(temp->next!=NULL)
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				temp = temp->next;
			}
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			temp->next = (struct node *)malloc(sizeof(node));
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			temp = temp->next;
			temp->value = y;
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			temp=a[y];
			while(temp->next!=NULL)
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				temp = temp->next;
			}
			temp->next = (struct node *)malloc(sizeof(node));
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			temp = temp->next;
			temp->value=x;
		}
		long long int s[n],count=1,len=1,e,leaf;
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		s[0]=1;
		z[1]=1;
		i=1;
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		while(1)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			if(i==0)
				break;
			e = s[i-1];	
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			if(a[e]->next==NULL)
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				if(len<i)
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					len=i;
					leaf = e;
				}
				i--;
				z[e] = 0;
			}

			else
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				a[e]=a[e]->next;
				while(z[a[e]->value]==1 && a[e]->next!=NULL)
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					a[e]=a[e]->next;
				}
				if(a[e]->next == NULL && z[a[e]->value]==1)
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					if(len<i)
					{
						for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
						len=i;
						leaf=e;
					}
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					i--;
					z[e] = 0;
				}
				else
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					s[i] = a[e]->value;
					i++;
					count++;
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					z[a[e]->value] = 1;
				}
			}
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		}
		if(len<i && i!=0)
			leaf=s[i-1];
		for(i=1;i<=n;i++)
			z[i]=0;
		s[0]=leaf;
		i=1;count=0;len=1;
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		z[leaf] = 1;
		while(1)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			if(i==0)
				break;
			e = s[i-1];
			if(b[e]->next == NULL)
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				if(len<i)
				 	len=i;
				i--;
				z[e] = 0;
			}
			else
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				b[e] = b[e]->next;
				while(z[b[e]->value]==1 && b[e]->next!=NULL)
					b[e]=b[e]->next;
				if(b[e]->next == NULL && z[b[e]->value]==1)
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					if(len<i)
						len=i;
					i--;
					z[e] = 0;
				}
				else
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					s[i] = b[e]->value;
					i++;
					count++;
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					z[b[e]->value] = 1;
				}
			}
		}
		if(len < i){
			
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			len=i;
		}
		printf("%lld\n",len );
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	}
	return 0;
}
