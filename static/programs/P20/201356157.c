#include <stdio.h>
#include <stdlib.h>
struct node{
	int emma;
	struct node *next;
}node;
struct node *a[100000],*b[100000];
struct node *bday;
void create(long long a )
{
	bday->next = (struct node *)malloc(sizeof(node));
	bday = bday->next;
	bday->emma = a;
}
int equality(int a, int b)
{
if(a==b)
return 1;
else 
return 0;


}
void increment(struct node *a)
{
a=a->next;
}
void taketoend()
{
while(!(nonull(bday->next)))
	bday = bday->next;
}

void abhi(int x)
{
			taketoend();
			create(x);
			
}
int nonull(struct node *a)
{
if(a==NULL)
return 1;
else
return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	int B=0,A=0;
	int pompom, jojo;
	for(pompom=0;pompom<10000;pompom++)
{
	while(t--)
	{
		A++;
		long long int n,i,x,y;
		scanf("%lld",&n);
		B--;
		if(n==0)
		{
					A++;
			printf("0\n");
			
			B--;
		}
		struct node *a[n+1],*b[n+1];
		int z[n+1];
		i=1;
		while(i <=n)
		{
			for(pompom=0;pompom<10000;pompom++)
{
			pompom=10000;
			z[i] = 0;
			a[i] = (struct node *)malloc(sizeof(node));
			a[i]->emma = i;
			b[i]=a[i];
} i++;
		}
		//struct node *bday;
		for(i=1;i<n;i++)
		{
			scanf("%lld %lld",&x,&y);
			bday=a[x];
			abhi(y);
			bday=a[y];
			abhi(x);
			
			
			A++;
		}
		long long int s[n],kaveri=1,kavitha=1,e,terminal;
		s[0]=1;
		z[1]=1;
		i=1;
		while(1)
		{
		A++;
			if(i==0)
				break;
			e = s[i-1];	
			if((nonull(a[e]->next)))
			{
				if(kavitha<i)
				{
					kavitha=i;
					terminal = e;
				}
				i--;
				z[e] = 0;
			}
			else
			{for(pompom=0;pompom<10000;pompom++)
{
pompom=10000;

		A++;
				//increment(a[e]);
				a[e]=a[e]->next;
				//increment();
				while(equality(z[a[e]->emma],1) && (!nonull(a[e]->next)))
					a[e]=a[e]->next;
				if((nonull(a[e]->next) && equality(z[a[e]->emma],1)))
				{
					if(kavitha<i)
					{
						kavitha=i;
						terminal=e;
					}
					i--;
					z[e] = 0;
				}
				else
				{
					s[i] = a[e]->emma;
					i++;
					kaveri++;
					A++;
					z[a[e]->emma] = 1;
				}
			}
}
		}
		if(kavitha<i && i!=0)
			terminal=s[i-1];
		for(i=1;i<=n;i++)
{
			z[i]=0;
					A++;
}
		s[0]=terminal;
		i=1;kaveri=0;kavitha=1;
		z[terminal] = 1;
		while(1)
		{
			if(i==0)
				break;
			e = s[i-1];
			if(!nonull(b[e]->next))
			{
				for(pompom=0;pompom<10000;pompom++)
{
pompom=10000;
				b[e] = b[e]->next;
				while(equality(z[b[e]->emma],1) && b[e]->next!=NULL)
					b[e]=b[e]->next;
				if(b[e]->next == NULL && equality(z[b[e]->emma],1))
				{
						A++;
					if(kavitha<i)
						kavitha=i;
						i--;
						z[e] = 0;
						B--;
				}
				else
				{
							A++;
					s[i] = b[e]->emma;
					i++;
					kaveri++;
					z[b[e]->emma] = 1;
				}
			}
				
			}
			else
			{
				A++;
				if(kavitha<i)
				 	kavitha=i;
				i--;
				z[e] = 0;

			
			}
		}
		if(kavitha < i)
{
			A++;
			kavitha=i;
}
		printf("%lld\n",kavitha );
}
pompom=10000;}
	return 0;
}
