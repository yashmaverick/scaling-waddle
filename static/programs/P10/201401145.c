#include<stdio.h>
#include<stdlib.h>
char queue[1001][101];
void str_in(char *address)
{
scanf("%s",address);
}
void str_out(char *pointer)
{
printf("%s\n",pointer);
}
void int_in(int *address1)
{
scanf("%d",address1);
}
int main()
{
	int start,end,i,j,n,q;
	start=-1;end=-1;
	int state1=0,state=0;
	int_in(&n);
	char c,p;
	while(1)
	{
		scanf("%c",&c);
		if(c=='A')
		{
			int_in(&j);
			for(i=0;i<j;i++)
			{
				if((end+1)%n==start) 
				{
					start=(start+1)%n;
					end=(end+1)%n;
					str_in(queue[end]);
				}
				else 
					str_in(queue[(++end)%n]);
				if(start==-1) 
					start=end=0;
				start%n;
				end%=n;	
			}
		}
		else if(c=='R') 
		{
			int_in(&j);
			for(i=0;i<j;i++)
			{
				start=(start+1)%n;
				if(start==(end+1)%n)
					start=end=-1;
			}
		}
		else if(c=='L')
		{
			i=start;
			if(start!=-1)
			{
				while(i!=end)
				{
					str_out(queue[i]);
					i=(i+1)%n;
				}
					str_out(queue[end]);
			}
		}
		else if(c=='Q')
			return 0;
	}
	return 0;
}
