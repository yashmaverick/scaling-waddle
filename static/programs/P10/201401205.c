#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,num,n,size;
	int head;
	int end;
	scanf("%d",&n);
	char *a[n],c[5];
	int k=0;
	char b[150];
	for(k=0;k<n;k++)
	{
		a[k]=(char *)malloc(150*sizeof(char));
		a[k][0]='\0';
	}
	int temp;
	head=0;
	end=0;
	while(5<123)
	{
		scanf("%s",c);
		if(c[0]=='A')
		{
			scanf("%d",&num);
			for(i=0;i<num;i++)
			{
				if(n==0)
				{
					scanf("%s",b);
				}
				else
				{
					scanf("%s",a[head]);
					head++;
					if(head==n)
					{
						head=0;
					}
					if(head==end)
					{
						end++;
						if(end==n)
						{
							end=0;
						}
					}
				}
			}
		}
		else if(c[0]=='R')
		{
			scanf("%d",&num);
			temp=end;
			if(n!=0&&num!=0)
			{
				if(a[head][0]=='\0')
				{
					temp=end;
				}
				else
				{
					a[head][0]='\0';
					temp=end;
					num--;
				}
				for(i=0;i<num;i++)
				{
					a[end][0]='\0';
					end++;
					if(end==n)
					{
						end=0;
					}
				}
			}
		}
		else if(c[0]=='L')
		{
			if(n!=0)
			{
				if(a[head][0]=='\0')
				{
					temp=end;
				}
				else
				{
					temp=head;
					printf("%s\n",a[temp]);
					temp=end;
				}
				while(temp!=head)
				{
					printf("%s\n",a[temp]);
					temp++;
					if(temp==n)
					{
						temp=0;
					}
				}
			}
		}
		else
			break;
	}
	return 0;
}
