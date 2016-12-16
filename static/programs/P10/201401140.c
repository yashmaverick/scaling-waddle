#include<stdio.h>
#include<stdlib.h>
#define max 10000
#define max1 100
char a[max][max1];
int start,end;
int y=0;
void append(int m,int n)
{
	int i,j;
	//y=0;
	for(i=0;i<m;i++)
	{
		if(end<n-1 && y==0)
		{
			end++;
			char c;
			j=0;
			while ((c=getchar())!='\n')
				a[end][j++]=c;
			a[end][j++]='\0';
		}
		else
		{
			//printf("&&&&&&&&7srart=%d end=%d\n",start,end);
			if(end==n-1)
				end=-1;
			//if(y==0)
			//	start++;
			if((end+1==start && y==1)||(start==0&&end==-1&&y==0))
				start++;
			y=1;
			if(start==n)
				start=0;
			end++;
			j=0;
			char c;
			while ((c=getchar())!='\n')
				a[end][j++]=c;
			a[end][j++]='\0';
		//	printf("******srart=%d end=%d\n",start,end);
		}
	}
	return ;
}
void remove1(int m,int n)
{
//	printf("****srart=%d end=%d\n",start,end);
	if(m>=n || (start<=end && m>=(end-start+1))||(start>=end && m>=n-(start-end-1)))
	{
		start=0;
		end=-1;
		y=0;
	}
	else
	{
		start+=m;
		if(start>=n)
		{
			start=start%n;
			//start--;
		}
	}
//	printf("$$$$$$srart=%d end=%d\n",start,end);
	return ;
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	//if(n!=0)
	//	{
	char c;
	start=0;
	end=-1;
	int m,i;
	while(1)
	{
		scanf("%c",&c);
		if(c=='A')
		{
			scanf("%d",&m);
			getchar();
			append(m,n);
		}
		else if (c=='R')
		{
			scanf("%d",&m);
			getchar();
			remove1(m,n);
		}
		else if (c=='L')
		{
			int j;
			if (end>=0 && start!=end)
			{
				i=start;
				while(i!=end)
				{
					j=0;
					i=(i%n);
					if(i!=end)
					{
						while(a[i][j]!='\0')
							printf("%c",a[i][j++]);
						printf("\n");
						i++;
					}
				}
			}
			j=0;
			int flag=0;
			while(a[end][j]!='\0')
			{
				printf("%c",a[end][j++]);
				flag=1;
			}
			if(flag==1)
				printf("\n");
		}
		else if(c=='Q')
			break ;
	}
	//	}
	return 0;
}
