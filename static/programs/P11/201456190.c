#include<stdio.h>
#include<stdlib.h>

long long int s[1000005];
long long int a[1000005];

int main()
{
	while(1)
	{
		long long int max=0;
		long long int n;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int compute;
		long long int i;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		long long int top=1;
		s[0]=0;
		long long int k=1;
		while(1)
		{
			if(k==n)
				break;
			/*long long int v;
			v=s[top-1];*/
			/*if(a[k]>=a[v])
			{
				s[top]=k;
				top++;
			}
			else 
			{*/
				while(1)
				{
					if(top==0)
						break;
					long long int g;
					g=s[top-1];
					if(a[k]>=a[g])
					{
						s[top]=k;
						top++;
						break;
					}
					/*long long int g;*/
					g=s[top-1];
					top--;
					if(top==0)
					{
						compute=(a[g])*(k);
						if(compute>max)
							max=compute;
						// break;
					
					}
					/*if(a[k]>=a[g])
					   {
					   s[top]=k;
					   top++;
					   break;
					   }*/  
					long long int f;
					f=s[top-1];
					compute=(a[g])*(k-1-f);
					if(compute>max)
						max=compute;
					/*  int p;
					    p=s[top]; */
					/*if(a[k]>=a[g])
					{
						s[top]=k;
						top++;
						break;
					}*/

				}
				if(top==0)
				{
					s[top]=k;
					top++;
				}
			//}
				
			k++;
		}
		/*    for(i=0;i<k;i++)
		      {
		      printf("%d",a[s[i]]);
		      }   */
		//	printf("%d",top);
		if(top!=0)
		{

			while(1)
			{
				if(top==0)
					break;
				long long int m;
				m=s[top-1];
				top--;
				if(top==0)
				{
					compute=(a[m])*(k);
					if(compute>max)
						max=compute;
				}
				else
				{
					compute=(a[m])*(k-1-(s[top-1]));
					if(compute>max)
						max=compute;
				}
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}

