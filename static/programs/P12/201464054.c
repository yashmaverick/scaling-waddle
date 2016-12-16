#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
//#pragma pack (2)
#define ll long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
/*void printstack(int stack[500001],ll top)
{
	if (top==-1)
		printf ("Stack empty.\n");
	else
	{
		ll i;
		for (i=0;i<=top;i++)
			printf ("%d ",stack[i]);
				printf("\n");
	}
	return;
}*/
int main()
{
	int stack[500001],x;
	ll i,n,top,ct,flag,j,tempval,tempind;
	while(1)
	{
		sll(n);
		if (n==0){break;}
		top=-1;	ct=0;
		f0(i,n)
		{	
			sint(x);
			if (top==-1)
				stack[++top]=x;
			else
			{
				while (top > -1)
				{
					if (x>stack[top])
					{
						ct++;
						top--;
					}
					else if (x<stack[top])
					{
						ct++;
						stack[++top]=x;
						break;
					}
					else if (x==stack[top])
					{
						tempval=x;
						tempind=top;
						while (stack[tempind]==x && tempind>-1)
						{
							tempind--;
							ct++;
						}
						if (tempind!=-1 && stack[tempind]>x)
							ct++;
						stack[++top]=x;
						break;
					}
				}
				if (top==-1)
					stack[++top]=x;
			}
//			printstack(stack,top);
//			printf ("count = ");pll(ct);
		}
		pll((((n)*(n-1))/2)-ct);
	}
	return 0;
}
