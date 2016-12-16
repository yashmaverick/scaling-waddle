#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int start=0,end=0,count=0;

void append(char arr[][100],int n,char *c)
{
	if(start==end&&count!=0)
	{
		//free(arr[start]);
		start++;
		count--;
		if(start>=n)
			start=start%n;
	}
	//arr[end]=(char*)malloc(100*sizeof(char));
	int i,j,k;
	strcpy(arr[end],c);
	/*for(i=0;c[i]!='\0';i++)
		{
			arr[end][i]=c[i];
			//printf("bef %c\n", arr[end][i]);
		}*/
	//printf("this %c\n",arr[end][1]);
	end++;
	count++;
	if(end>=n)
		end=end%n;
	return;
}

void print(char arr[][100],int n)
{
//printf("%d %d %d\n",start,end,count);
if(start==end&&count==0)
	return;
int i,j;
if(start<end)
{
	for(i=start;i<end;i++)
	{	
		for(j=0;arr[i][j]!='\0';j++)
			printf("%c",arr[i][j]);
		printf("\n");
	}
}
else
{
		for(i=start;i<n;i++)
		{
		for(j=0;arr[i][j]!='\0';j++)
			printf("%c",arr[i][j]);
		printf("\n");
		}
		for(i=0;i<end;i++)
		{
		for(j=0;arr[i][j]!='\0';j++)
			printf("%c",arr[i][j]);
		printf("\n");
		}
}
}

void delete(char arr[][100],int n,int k)
{
	int i,j;
	for(j=0;j<k&&count!=0;j++)
	{
		//free arr[start++];
		start++;
		count--;
		if(start>=n)
			start=start%n;
	}
}

int main()
{
	int i,j,k,l,n;
	scanf("%d",&n);
	getchar();
	char arr[n][100],c,temp[100];
	c=getchar();
	while(c!='Q')
	{
		if(c=='A')
		{
			scanf("%d",&i);
			for(j=0;j<i;j++)
			{
				scanf("%s",temp);
				//printf("temp %s\n",temp);
				append(arr,n,temp);
			}
		}
		if(c=='L')
			print(arr,n);
		if(c=='R')
		{
			scanf("%d",&j);
			delete(arr,n,j);
		}
		c=getchar();
	}
	return 0;
}