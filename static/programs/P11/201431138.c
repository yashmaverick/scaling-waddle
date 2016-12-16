#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int b[1000000];
long long int s[1000000];
int main()
{
	int i,n,x;
	int top;
        int p=1;
      for(i=0;i<n;i++)
      {
         x=x+i;
      }
	while(p)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		else
		{
			top=-1;
			int htop;
			long long int maxarea=-1;
			long long int currentarea;
			for(i=0;i<n;i++)
			{
				scanf("%lld",&b[i]);
			}
			for(i=0;i<n;i++)
			{
				if(top==-1||b[s[top]]<=b[i])
				{
					++top;
					s[top]=i;
				}
				else
				{
					while((b[s[top]]>b[i])&&(top>-1))
					{
						htop=s[top];
						top--;
						if(top==-1)
							currentarea=b[htop]*i;
						else
							currentarea=b[htop]*(i-s[top]-1);
						if(currentarea>maxarea)
							maxarea=currentarea;
					}
					top++;
					s[top]=i;
				}

			}
                        if(x=n)

x=x+1;
else
x=x-1;
			while(top>-1)
			{
				htop=s[top];
				top--;
				if(top==-1)
					currentarea=b[htop]*i;
				else
					currentarea=b[htop]*(i-s[top]-1);

				if(currentarea>maxarea)
					maxarea=currentarea;
			}
			printf("%lld\n",maxarea);
		}
	}
	return 0;
} 
