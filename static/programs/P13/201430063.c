#include<stdio.h>
int top=-1;
int c[100007][2];
void push(int n);
void pop();
int to();
int empty();
void pop()
{
	top=top-1;
}
void push(int n)
{
	top=top+1;
	c[top][0]=n;
}
int to()
{
	return c[top][0];
}
int empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

typedef struct p13
{
	int a;
	int h;
}p13;

int main()
{
	int i;
	int n;
	int t;
	scanf("%d",&t);
	int d[100001];	
	while(t--)
	{
		scanf("%d",&n);
		p13 b[n];
		for(i=0;i<n;i++)
			scanf("%d",&b[i].a);
		for(i=0;i<n;i++)
			{d[i]=b[n-i-1].a;
		b[i].h=0;
		     }
                         for(i=0;i<n;i++)
			b[i].a=d[i];
		//for(i=0;i<n;i++)
		//printf("b[i].a is %d",b[i].a);
		//int height=-1;
		for(i=0;i<n;i++)
		{
			int f=0;
			while(!empty())
			{
				if(b[i].a<to())
				{f=1;
					//printf("topelement is %d\n",to());
					//printf("c[top][1] is %d\n",c[top][1]);
                                        b[i].h=b[c[top][1]].h+1;
					pop();
				}
				else
					break;
			}
			push(b[i].a);
			c[top][1]=i;
			if(f==0&&i!=0)
				b[i].h=b[i-1].h+1;
//printf("height  is%d\n",b[i].h);		
}
		//for(i=0;i<n;i++)
		//printf("%d ",b[i].h);
		//printf("\n");
		int max=0;
		int l,f;
		for(i=0;i<n;i++)
		{
			if(b[i].h>max)
			{
				max=b[i].h;
				l=i;
			}
			if(b[i].h==max)
			{
				if(b[i].a<b[l].a)
					l=i;
			}
		}
		printf("%d %d\n",b[l].a,b[l].h);
		while(!empty())
			pop();
	}
	return 0;
}











