#include<stdio.h>
int main()
{
       	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{ 
		long long int a[n],left_index[n],right_index[n],max=0,area,i,j;
		for(i=0;i<n;i++)
		{ 
			scanf("%lld",&a[i]);
		}
		left_index[0]=-1;
		for(i=1;i<n;i++)
		{ 	
			if(a[i]<=a[i-1])
				// left_index[i]=left_index[i-1];
			{
				j=i-1;
				while(a[j]>=a[i] && j>=0)
				{	 
					if(left_index[j]==-1)
					{	
						if(a[j]>=a[i])
						{
							left_index[i]=-1;
							break;
						}	
						else
						{
							left_index[i]=j;
							break;
						}
					}
					else
					{ 	
						if(a[i]<=a[left_index[j]])
							j=left_index[j];
						else
						{
							left_index[i]=left_index[j];
							break;
						}
					}
				}
			}
			else 
				left_index[i]=i-1;
		}
//			        for(i=0;i<n;i++)
//				  printf("%lld ",left_index[i]);
//				  printf("\n");
		right_index[n-1]=-1;
		for(i=n-2;i>=0;i--)
		{ //if(a[i]>a[i+1])
			//	right_index[i]=i+1;
			if(a[i]<=a[i+1])
			{ 
				j=i+1;
				while( a[j]>=a[i] && j<=n)
				{ 
					//				printf("while\n");
					if(right_index[j]==-1)
					{
						if(a[j]>=a[i])
							right_index[i]=-1;
						else
							right_index[i]=j;
						//	printf("%lld j\n",j);
						break;
					}
					else
					{  
						if(a[i]<=a[right_index[j]])
							j=right_index[j];
						else
						{
							right_index[i]=right_index[j];
							break;
						}
					}
				}
			}
			else
				right_index[i]=i+1;
			//		printf("%lld ",right_index[i]);
		}
//			  for(i=0;i<n;i++)
//			    printf("%lld ",right_index[i]);
///		    printf("\n");
		for(i=0;i<n;i++)
		{ 
			if(left_index[i]==-1 && right_index[i]!=-1)
				area=a[i]*(right_index[i]);
			else if(right_index[i]==-1 && left_index[i]!=-1)
				area=a[i]*(n-left_index[i]-1);
			else if(right_index[i]==-1 && left_index[i]==-1)
				area=a[i]*n;
			else 
				area=a[i]*((right_index[i]-1)-(left_index[i]+1)+1);
			if(max<area)
				max=area;
			//  printf("%lld\n",max);
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
