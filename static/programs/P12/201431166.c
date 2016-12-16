#include<stdio.h>
int main()
{
	long long int n;
	long long count=0;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int a[n],i,j,k,b[n],c[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
//		b[n-1]=n;
	/*	if(a[n-2]<a[n-1])
			b[n-2]=n-1;
		else
			b[n-2]=n;
	//	count++;
	//	c[n-1]=n;
		if(a[n-2]<=a[n-1])
			c[n-2]=n-1;
		else
			c[n-2]=n;
	//	count1++;
		for(i=n-3;i>=0;i--)
		{
			j=i+1;
			k=n-1-i;
			while(k--)
			{
				if(a[i]<a[j])
				{
					b[i]=j;
				//	count++;
					break;
				}
				else
				{
				//	if(j!=n-1 || j==n-1)	
				//	{
				//		count++;
				//	}
					j=b[j];
					if(j==n)
					{
						//if(a[i]<=a[j-1])
					///	{
					///		count++;
					//	}	
						b[i]=n;
						break;
					}
				}
			}
		}
		for(i=n-3;i>=0;i--)
		{
			j=i+1;
			k=n-1-i;
			while(k--)
			{
				if(a[i]<=a[j])
				{
					c[i]=j;
				//	count1++;
					break;
				}
				else
				{
				//	if(j!=n-1 || j==n-1)	
				//	{
				//		count1++;
				//	}
					j=b[j];
					if(j==n)
					{
						//if(a[i]<a[j-1])
					//	{
					//		count1++;
					//	}
						c[i]=n;
						break;
					}
				}
			}
		}*/
		long long int s[n];
		long long int upper=-1;
		s[++upper]=n-1;
		for(i=n-2;i>=0;i--)
		{
			while(upper!=-1 && (a[s[upper]]<=a[i]))
					upper--;
			if(upper!=-1)
				b[i]=s[upper];
			else
				b[i]=n-1;
			upper++;
			s[upper]=i;
		}

		upper=-1;
		s[++upper]=n-1;
		for(i=n-2;i>=0;i--)
		{
			while(upper!=-1 && (a[s[upper]]<a[i]))
					upper--;
			if(upper!=-1)
				c[i]=s[upper];
			else
				c[i]=-1;
			upper+=1;
			s[upper]=i;
		}

		b[n-1]=c[n-1]=-1;
//		for(i=0;i<n;i++)
//			printf("%d ",b[i]);
//	printf("\n");
//		for(i=0;i<n;i++)
//			printf("%d ",c[i]);
//	printf("\n");
		long long int temp;
		count=0;
		for(i=0;i<n-1;i++)
		{
			temp=i+1;
			while(temp<=b[i] && temp>0)
			{
				count++;
//				printf("count is %lld:\n",count);
//				printf("temp is :%d b[i] is %d : ",temp,b[i]); 
				temp=c[temp];
			}
		}
		long long ans=(n*(n-1))/2;
		ans=ans-count;
		printf("%lld\n",ans);
		scanf("%lld",&n);
	}
	return 0;
}
