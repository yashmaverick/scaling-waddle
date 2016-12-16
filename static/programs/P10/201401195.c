#include<stdio.h>
#include<string.h>
char a[10000][100];
int start=0,last=0,end=10000;
void append(char *element,int capacity)
{
	if(start!=last)
	{
		strcpy(a[last],element);
		last++;
		end=last-1;
	}
	else if(end==10000&&start==0&&last==0)
	{
		strcpy(a[last],element);
		last++;
		end=last-1;
	}
	else if(end==capacity-1&&start==0&&last==0)
	{
		start++;
		strcpy(a[last],element);
		last++;
		end=last-1;
	}
	else if(start==(capacity-1)&&last==(capacity-1))
	{
		start=0;
		strcpy(a[last],element);
		last++;
		end=last-1;
	}
	else if(end==10000)
	{
	strcpy(a[last],element);
	last++;
	end=last-1;
	}
	else  
	{
		start++;
		strcpy(a[last],element);
		last++;
		end=last-1;
	}

	if(last==capacity)
	{

		last=0;
	}

}
void remov(int n,int capacity)
{
	if(n==0)
	{
	return;
	}
	else if(start+n>=capacity)
	{
		start=start-capacity+n;
		if(start==last)
			end=10000;
	}
	else
	{	
		start=start+n;
		if(start==last)
		{
			end=10000;
		}

	}
}
void list(int capacity)
{
	int i;
	if(start<=end&&end!=10000)
	{
		for(i=start;i<=end;i++)
			printf("%s\n",a[i]);
	}
	else if(start>end)
	{
		for(i=start;i<capacity;i++)
			printf("%s\n",a[i]);
		for(i=0;i<=end;i++)
			printf("%s\n",a[i]);
	}
}	
int main()
{
	int capacity,n,i;
	scanf("%d",&capacity);
	char choice;
	char element[100];
	scanf("%c",&choice);
	while(choice!='Q')
	{
		if(choice=='A')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%s",element);
				append(element,capacity);
			}
		}
		else if(choice=='R')
		{

			scanf("%d",&n);
			remov(n,capacity);
		}
		else if(choice=='L')
		{
			list(capacity);
		}
		scanf("%c",&choice);

	}
	return 0;
}

