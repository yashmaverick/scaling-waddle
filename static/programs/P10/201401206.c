#include<stdio.h>
int first=-1,last=-1;
char buf[10000][100];
int size;
void append(int n)
{
	int ele,i;
	if(last>=first)
		ele=last-first+1;
	else
		if(first>last)
			ele=size-first+last+1;
	if(first==-1&&last==-1)
	{
		ele=0;
		first=0;last=-1;
	}
	//	printf("###%d %d %d###\n",first,last,ele);
	for(i=0;i<n;i++)
	{
		last++;
		last%=size;
		scanf("%s",buf[last]);
	}
	if((size-n-ele)<0)
		first=(ele+n+first-size)%size;
	//	printf("***%d %d***\n",first,last);

}
void rem(int n)
{
	int ele;
	if(last>=first)
		ele=last-first+1;
	else
		if(first>last)
			ele=size-first+last+1;
	first=(first+n)%size;
	if(ele==n)
	{
		first=-1;
		last=-1;
	}
}
void print()
{
	//printf("**%d %d**\n",first,last);
	if(first!=-1&&last!=-1&&first==last)
	{
		printf("%s\n",buf[last]);
		return;
	}
	if(first>last)
	{
		int start=first,end=last;
		while(start<size)
		{
			printf("%s\n",buf[start]);
			start++;
		}
		start=0;
		while(start<=end)
		{
			printf("%s\n",buf[start]);
			start++;
		}
	}
	if(last>first)
	{
		int start=first,end=last;
		while(start<=end)
		{
			printf("%s\n",buf[start]);
			start++;
		}
	}
}
int main()
{
	char c;
	int n;
	scanf("%d",&size);
	scanf(" %c",&c);
	while(c!='Q')
	{
		if(c=='A')
		{
			scanf("%d",&n);
			append(n);
		}
		if(c=='R')
		{
			scanf("%d",&n);
			rem(n);
		}
		if(c=='L')
			print();
		scanf(" %c",&c);
	}
	return 0;
}

