#include<stdio.h>
#include<string.h>
void append(int n);
void rem(int n);
void list(int n);
typedef struct ak2
{
	char str[101];
}ak2;
ak2 buffer[10001];
int first=0,last=-1,k,track=0;
void append(int n)
{ 

	scanf("%d",&k);
	while(k>0)
	{
		last++;
		last=last%n;
		scanf("%s",buffer[last].str);
		if(track==n)
			first=first+1;
		if(first==n)
			first=0;
		track=track+1;
		if(track>=n)
			track=n;
		k--;
	}
}
void rem(int n)
{
	scanf("%d",&k);
	track=track-k;
	if(track<0)
		track=0;
	if(track==0)
	{first=0;  
		last=-1;
	}
	if(first<=last)
	{
		first=first+k;
		if(first>last)
		{first=0;
			last=-1;
		}
	}
	if(last<first&&last!=-1)
	{  int flag=0;
		if(first-last==1&&k==n)
		{first=0;
			last=-1;
		}
		if(first+k<n)
		{	first=first+k;
			flag=1;
		}    
		if(first+k>=n&&last!=-1&&flag==0)
			first=first%n+k%n;
	}
}
void list(int n)
{int i;
	for(i=first;i<=last;i++)
		printf("%s\n",buffer[i].str);		
	if(last<first&&last!=-1)
	{
		for(i=first;i<n;i++)
			printf("%s\n",buffer[i].str);
		for(i=0;i<=last;i++)
			printf("%s\n",buffer[i].str);
	}                           
}
int main()
{

	int n,i,n1;
	scanf("%d",&n);
	//printf("ascii=%d\n",n);
//	scanf("%d",&n1);
  //      printf("ascii=%d\n",n1);
	char ch='f';

	while(ch!='Q')
	{
		scanf("%c",&ch);
		if(n!=0)
		{ 
			if(ch=='A')
				append(n);
			if(ch=='R')
				rem(n);
			if(ch=='L')
				list(n);
		}
	}
	return 0;
}
