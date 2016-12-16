#include<stdio.h>
#include<string.h>
int head=-1,tail=-1,N;
char a[10009][109],b[101];
//head points to top
//tail points to last not to which is to be changed
void append()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		if(head==-1&&tail==-1)
		{
			head=(head+1)%N;
			tail=(tail+1)%N;
			scanf("%s",a[head]);
		}
		else
		{
			tail=(tail+1)%N;
			scanf("%s",a[tail]);
			if(tail==head)
				head=(head+1)%N;
		}
	}
	return;
}

void rem()
{
	int n;
	scanf("%d",&n);
	if(head==-1)
		return;
	if(n==N||head==tail)
	{
		head=-1;
		tail=-1;
	}
	else
		head=(head+1)%N;
}

void list()
{
	int i;
	if(head==-1&&tail==-1)
		return;
	else
	{
		i=head;
		while(i!=tail)
		{
			printf("%s\n",a[i]);
			i=(i+1)%N;
		}
		printf("%s\n",a[tail]);
	}
	return;
}

int main()
{
	int n,i,j,l;
	char c;
	scanf("%d",&N);
	scanf("%c",&c);
	if(N!=0)
		while(1)
		{
			scanf("%c",&c);
			if(c=='Q')
				break;
			else
			{
				if(c=='A')
					append();
				else if(c=='R')
				{
					scanf("%d",&n);
					for(i=0;i<n;i++)
						rem();
				}
				else if(c=='L')
					list();
			}
		}
	else
	{
		while(1)
		{
			scanf("%c",&c);
			if(c=='Q')
				break;
			else
			{
				if(c=='A')
				{
					scanf("%d",&n);
					while(n--)
						scanf("%s",b);
				}

				else if(c=='R')
					scanf("%d",&n);
				else if(c=='L')
					continue;

			}
		}
	}
	return 0;
}
