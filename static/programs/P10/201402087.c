#include<stdio.h>
char a[1000][101];
int size;
int start=0;
int sz=0;
void push();
void pop();
void display();
int main()
{
		scanf("%d",&size);
		getchar();
		char c;
		int n;
		scanf("%c",&c);
		while(c!='Q')
		{
				if(c=='A')
				{	
						scanf("%d",&n);
						getchar();
						while(n--)
								push();
				}
				else if(c=='R')
				{
						scanf("%d",&n);
						getchar();
						while(n--)
								pop();
				}
				else if(c=='L')
						display();
				scanf("%c",&c);
		}
		return 0;
}

void push()
{
		scanf("%s",a[(start+sz)%size]);
		if(sz<size)
				sz++;
		else if(sz==size)
				start=(start+1)%size;

}

void pop()
{
		start++;
		if(sz>0)
				sz--;
		if(start==size)
				start=0;
}

void display()
{
		int i;
		if(start+sz<=size)
			for(i=start;i<start+sz;i++)
					printf("%s\n",a[i]);
		else
		{
		//		printf("yo\n");
				for(i=start;i<size;i++)
						printf("%s\n",a[i]);
				for(i=0;i<sz+start-size;i++)
						printf("%s\n",a[i]);
		}
}
