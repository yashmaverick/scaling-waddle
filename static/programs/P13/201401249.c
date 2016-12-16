#include<stdio.h>
int stack[1000000];
int pointer=-1;
int c[1000000];
int maximumheight=0;
int deepestnode;
void push(int value)
{
pointer++;
stack[pointer]=value;
return;
}
void pop()
{
if(pointer==-1)
return ;
pointer--;
}
void postheight(int start,int end,int subsize,int *getit,int height)
{
	if(subsize==0)
		return ;
	if(height>=maximumheight)
	{
		if(height!=maximumheight)
			deepestnode=getit[start];
		else if(getit[start]<deepestnode)
			deepestnode=getit[start];
		maximumheight=height;
	}
	height++;
	subsize=c[start]-end+1;
	postheight(c[start],end,subsize,getit,height);
	subsize=start-c[start]-1;
	postheight(start-1,c[start]+1,subsize,getit,height);	
return ;
}


int main()
{
	int n, index,test ;
	scanf("%d",&test);
	while(test)
	{
	scanf("%d",&n);
	int post[n];
	maximumheight=0;
	for(index=0;index<n;index++)
	{
		scanf("%d",&post[index]);
	}
		pointer=-1;

	index=n-1;
	while(index>=0)
	{
		if(pointer==-1 || post[stack[pointer]]<=post[index])
		{
			push(index);
			index--;
		}

		else
		{
			c[stack[pointer]]=index;
			pop();
		}
	}

	while(pointer!=-1)
	{
		c[stack[pointer]]=stack[pointer]-1;
		pop();
	}
	postheight(n-1,0,n,post,0);
	printf("%d %d\n",deepestnode,maximumheight);
	test--;
	}
	return 0;
}
