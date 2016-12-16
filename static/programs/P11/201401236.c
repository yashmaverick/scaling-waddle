#include<stdio.h>
long long int s[100100],top=-1;
void push(long long int a)
{
	top++;
	s[top]=a;
	return ;
}
void pop()
{
	top--;
	return ;
}
int main()
{
	long long int n;	

	while(1)
	{
		scanf("%lld",&n);
		long long int     j,a[100100],left,right,area,max=0,i;
		if(n==0)
			break;
		else
		{
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			for(i=0;i<n;i++)
			{
				if(top==-1)
					push(i);
				else
				{
					if(a[i]>=a[s[top]])
						push(i);
					else if(a[i]<a[s[top]])
					{
						while(top!=-1)
						{
							if(a[s[top]]>a[i])
							{
								pop();
								if(top==-1)
								{
									right=i;
									left=-1;
								}
								else
								{
									right=i;
									left=s[top];
								}
								area=(right-left-1)*a[s[top+1]];
						//		printf("%d %d %d %d %d\n",area,a[s[top+1]],right,left,top);
								if(max<area)

									max=area;

							}

							else
							{

								push(i);
								break;	
							}
						}	

						if(top==-1)
							push(i);


					}								}
		}
		while(top!=-1)
		{
			pop();
			if(top==-1)
			{
				left=-1;
				right=n;
			}
			else
			{
				left=s[top];
				right=n;
			}
			area=(right-left-1)*a[s[top+1]];
		//	printf("%d\n",area);			
			if(area>max)
				max=area;
		}
		printf("%lld\n",max);
	}
}
return 0;
}




































