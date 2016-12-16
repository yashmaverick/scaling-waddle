#include<stdio.h>
#include<stdlib.h>

int start, end;

void insert(int n, int m, char a[][100])
{

	static int i=0;

	scanf("%s",a[i]);
	i++;
	i=i%n;

}

int main()
{
	int n,j,m,num=0,flag;
	start=0;
	end=0;
	scanf("%d",&n);
	char a[n][100], ch;
	while(1)
	{
		scanf("%c",&ch);
		if(ch=='A')
		{
			flag=0;
			scanf("%d",&m);
			num+=m;
			end+=m;
			if(num>=n)
				num=n;

			for(j=0;j<m;j++)
			{
				insert(n,m,a);
//				printf("insert me num is %d\n",num);
			}
		}

		else if(ch=='R')
		{
			scanf("%d",&m);
			num-=m;
	
		}

		else if(ch=='L')
		{
				end=end % n;
				start= end-num;
				if(start<0)
					start=start+n;

			if( start<end  || (start==end && num==0) )
			{
				for(j=start;j<end;j++)
					printf("%s\n",a[j]);
			}
			else
			{
				for(j=start;j<n;j++)
					printf("%s\n",a[j]);
	
				for(j=0;j<end;j++)
					printf("%s\n",a[j]);
			}
		}

		else if(ch=='Q')
			break;
	}
	return 0;
}
