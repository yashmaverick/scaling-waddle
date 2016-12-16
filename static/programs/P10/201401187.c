#include<stdio.h>
#include<string.h>
char a[10010][110];
int n,p=-1,q=-1;
void push()
{
	char s[110];
		if(p==-1)
		{
			p=0;
			q=0;
		}
		else if(q==n-1)
		{
			q=0;
			if(p==0)
				p=q+1;
		}
		else if(p==q+1)
		{
			q=q+1;
			if(p==n-1)
				p=0;
			else
				p=p+1;
		}
		else q=q+1;
		scanf("%s",s);
		strcpy(a[q],s);
}
void pop()
{
		if(p==q)
		{
			p=-1;
			q=-1;
		}
		else if(p==n-1)
			p=0;
		else p=p+1;
}
/*void print()
{
	int i,j;
	if(front>rear)
	{
		for(i=front;i<n;i++)
			printf("%s\n",a[i]);
		for(i=0;i<=rear;i++)
			printf("%s\n",a[i]);
	}
	else
	{
		if(front!=-1&&rear!=-1)
			for(i=front;i<=rear;i++)
				printf("%s\n",a[i]);
	}
}*/
int main()
{
	int x,i,j;
	char c;
	scanf("%d",&n);
	while(1)
	{
		getchar();
		scanf("%c",&c);
		if(c=='Q')
		{
			break;
		}
		else if(c=='A')
		{
			scanf("%d",&x);
			while(x--)
				push();
		}
		else if(c=='R')
		{
			scanf("%d",&x);
			while(x--)
				pop();
		}
		else if(c=='L')
		{ 
			if(p<=q)
			{
				if(p!=-1&&q!=-1)
					for(i=p;i<=q;i++)
						printf("%s\n",a[i]);
			}
			else
			{
				for(i=p;i<n;i++)
					printf("%s\n",a[i]);
				for(i=0;i<=q;i++)
					printf("%s\n",a[i]);
			}


		}
	}
	return 0;
}
