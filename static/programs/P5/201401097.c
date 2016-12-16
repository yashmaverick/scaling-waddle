#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int i,flag=0,j,k,d,sum=0,l,m,n,mid,beg,end,a[100000];
	char alpha[100000];
	scanf("%lld",&n);
		
	for(i=0;i<n;i++)
	{
		flag=0;
		scanf("%lld%lld",&d,&sum);
		for(j=0;j<d;j++)
		{
		
		scanf("%s",alpha);
		scanf("%lld",&a[j]);
		
				}
	



		for(j=0;j<d;j++)
			for(k=j;k<d;k++)
			{
				if(a[k]<a[j])
				{
					m=a[k];
					a[k]=a[j];
					a[j]=m;

				}
				
				
			}
		
for(j=0;j<d;j++)
{
	if((sum-a[j])/2>=a[j+1])
	for(m=j+1;j<d;m++)
	{
		beg=m+1;
		end=d-1;
		if(sum-(a[j]+a[m])>=a[m+1])
			while(beg<=end)
			{
			
				mid=(beg+end)/2;
				
				if(a[mid]+a[j]+a[m]==sum)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				else if(a[mid]+a[j]+a[m]>sum)
				{
					end=mid-1;
				}
				else
					beg=mid+1;

			}
	/*	for(k=m+1;k<d;k++)
		{
			if(a[j]+a[m]+a[k]==sum)
			{
				printf("YES\n");
				flag=1;
				break;
			}
			if(a[j]+a[m]+a[k]>sum)
				break;

		}*/
		else
			break;
		if(flag==1)
			break;
	}
	else
		break;
	if(flag==1)
		break;
}

if(flag!=1)
	printf("NO\n");



	}
	
	

return 0;
}
