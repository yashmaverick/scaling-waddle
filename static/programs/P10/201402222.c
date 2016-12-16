#include<stdio.h>
int main()
{
	int max,n,m,head=-1,flag,count=0,tail=-1,k=0,i;
	scanf("%d",&max);
	char S[10001][101],a,x;
	scanf("%c",&a);
	while(a!='Q')
	{
		if(a=='A')
		{
				scanf("%d",&n);
				if(max!=0)
				{
					count=count+n;
					if(count>max)
					{
						count=max;
					}
					if(n!=0)
					{
				flag=0;
				if(head>tail && tail!=-1)
				{
					flag=1;
				}
				if(head==-1)
				{
					head++;
				}
				k=0;
				for(i=0;i<n;i++)
				{
					tail++;
					if(tail==max)
					{
						k++;
					}
					if(tail>=max)
					{
						tail=tail%max;
					}
						scanf("%s",S[tail]);

				}
				if(tail>=head && k==1)
				{
					head=(tail+1)%max;
				}
				if(k>1)
				{
					head=(tail+1)%max;
				}
				if(head==tail && count!=n)
				{
					head=(tail+1)%max;
				}
				if(head<=tail && flag==1)
				{
					//printf("yes\n");
					head=(tail+1)%max;
				}

			}
		}
		}
		if(a=='L')
		{
			if(max!=0)
			{
			if (count!=0)
			{
//printf("head=%d\n tail=%d\n",head,tail);
				if(head<=tail)
				{
					for(i=head;i<=tail;i++)
					{
						printf("%s\n",S[i]);
					}
				}
				else if(head>tail)
				{
					for(i=head;i<max;i++)
					{
						printf("%s\n",S[i]);
					}
					for(i=0;i<=tail;i++)
					{
						printf("%s\n",S[i]);
					}
				}
			}
		  }
		}
		if(a=='R')
		{
			scanf("%d",&m);
			if(max!=0)
			{
			if(m!=0)
			{
				count=count-m;
				if(count==0)
				{
					head=-1;
					tail=-1;
				}
				else
				{
					head=(head+m)%max;
				}
			}
			
		    }
		}
		scanf("%c",&x);
		a=x;
	   
	}
	
	return 0;
}
