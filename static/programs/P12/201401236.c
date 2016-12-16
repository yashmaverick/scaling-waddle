#include<stdio.h>
long long int s[1001000],top=-1;
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
		long long int j,a[1001000],left,right,i,count=0,temp;
		top=-1;
		if(n==0)
		{	

			break;
		}		
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
					if(a[i]<=a[s[top]])
						push(i);
					else if(a[i]>a[s[top]])
					{
						while(top!=-1)
						{
							if(a[s[top]]<a[i])
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
						//		printf("%lld %lld ",a[s[top+1]],right);

								if(right<=n-2)
									count=count+n-right-1;		

								if(a[left]==a[s[top+1]])
								{
									while(left--)
										if(a[left]>a[s[top]])
											break;
								}

						//		printf(" %lld \n",left);

								for(j=left-1;j>=0;j--)
								{
									if(a[j]>=a[left])
									{
										count++;
										left=j;
									}

																}
						//		printf(" %lld\n",count);		




							}
							else 
							{

								push(i);
								break;	
							}



						}
						if(top==-1)
							push(i);

					}			
				}
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
			//	printf("%lld %lld \n ",a[s[top+1]],right);

				if(right<=n-2)
					count+=n-right-1;
				if(a[left]==a[s[top+1]])         
				{
					while(left--)
						if(a[left]>a[s[top+1]])
							break;

				}
				for(j=left-1;j>=0;j--)
				{
					if(a[j]>=a[left])
					{
						count++;	
						left=j;		
					}
				
				}
		//	printf("%lld\n",left);
			}
			printf("%lld\n",count);
		}
	}
	return 0;
}
