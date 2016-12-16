#include<stdio.h>
#include<string.h>
char b[10000][101];
char a[101];
int begin,end,n,max; // no of elements
void add(char a[])
{
	if(end==-1)
	{
		//if(begin==-1)
		begin=(begin+1)%max;
		strcpy(b[begin],a);
		end=(end+1)%max;
		return;
	}
	if(end==max-1)
	{
		if(begin==0)
			begin=(begin+1)%max;
		end=(end+1)%max;
		strcpy(b[end],a);
		return;
	}
	if(begin-end==1)
	{
		begin=(begin+1)%max;
		end=(end+1)%max;
		strcpy(b[end],a);
		return;
	}/*
	if(end==max-1)
	{
		end=(end+1)%max;
		strcpy(b[end],a);
		return;
	}*/
	end=(end+1)%max;
	strcpy(b[end],a);
	return;
}
void print();
int main()
{
	char c;
	int len,k,i,j=0;
	scanf("%d",&max);
	begin=-1;
	end=-1;
	while(1)
	{
		scanf("%c",&c);
		if(j>5000)
			break;
		if(c=='A')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%s",a);
				add(a);
			}
		}
		if(c=='L')
		{
			//printf("begin=%d end=%d",begin,end);
			print();
		}
		if(c=='R')
		{
			scanf("%d",&n);
			//printf("begin=%d end=%d\n",begin,end);
			if(end==-1)
				continue;
			if(begin<end)
			{
				k=end-begin+1;
				//printf("k=%d\n",k);
				if(k==n)
				{
					//begin=(end+1)%max;
					end=-1;
					begin=-1;
				}
				else if(k>n)
					begin=(begin+n)%max;
			}
			else if(begin==end)
			{
				if(n==1)
				{
					begin=-1;
					end=-1;
				}
			}
			else if(begin>end)
			{	
				k=max-begin+end+1;
				if(k==n)
				{
					//begin=(end+1)%max;
					end=-1;
					begin=-1;
				}
				if(k>n)

					begin=(begin+n)%max;
			}
		//printf("final:begin=%d end=%d\n",begin,end);
		}
		if(c=='Q')
			break;
	}
	return 0;
}
void print()
{
	//printf("%d %d\n",begin,end);
	int i,j;
	if(end==-1)
		return;
	if(begin==end)
	{
		printf("%s",b[end]);
		printf("\n");
		return;
	}
	printf("%s",b[begin]);
	printf("\n");
	for(i=begin;;)
	{
		i=(i+1)%max;
		if(i!=end)
		{
			printf("%s",b[i]);
			printf("\n");
		}
		else
			break;
	}
		if(i==end)
			printf("%s",b[end]);
		printf("\n");
	return;
}







