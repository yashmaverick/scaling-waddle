#include<stdio.h>
long long int arr[1000007],max[1000007],min[1000007],left,right,temp;
void insert(long long int b[],long long int data,long long int flag)
{
	long long int end,j;
	if(flag==0)
	{
		end=right;
		right++;
		b[++end]=data;
		j=end;
		while(j/2>=1)
		{
			if(b[j/2]>b[j])
			{
				temp=b[j];
				b[j]=b[j/2];
				b[j/2]=temp;
			}
			else
				break;
			j=j/2;
		}
	}
	else 
	{
		end=left;
		left++;
		b[++end]=data;
		j=end;
		while(j/2>=1)
		{
			if(b[j/2]<b[j])
			{
				temp=b[j];
				b[j]=b[j/2];
				b[j/2]=temp;
			}
			else
				break;
			j=j/2;
		}
	}
	return;
}
long long int delete(long long int b[],long long int flag)
{
	long long int end,req,i,j;
	if(flag==0)
	{
		end=left;
		left--;
		req=b[1];
		b[1]=b[end];
		i=1;
		while(2*i<=end)
		{
			if(2*i==end)
				j=2*i;
			else if(b[2*i+1]>b[2*i])
				j=2*i+1;
			else
				j=2*i;
			if(b[i]<b[j])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				i=j;
			}
			else
				break;
		}
	}
	else
	{
		end=right;
		right--;
		req=b[1];
		b[1]=b[end];
		i=1;
		while(2*i<=end)
		{
			if(2*i==end)
				j=2*i;
			else if(b[2*i+1]<b[2*i])
				j=2*i+1;
			else
				j=2*i;
			if(b[i]>b[j])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				i=j;
			}
			else
				break;
		}
	}
	return req;
}
int main()
{
	long long int t,i,sum,x;
	scanf("%lld",&t);
	while(t--)
	{
		left=0;
		right=0;
		sum=0;
		long long int a,b,c,n;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		long long int median;
		arr[1]=1;
		median=1;
		for(i=2;i<=n;i++)
		{
			if(left-right>0)
			{
				x=delete(max,0);
				insert(min,median,0);
				median=x;
			}
			if(right-left>1)
			{
				x=delete(min,1);
				insert(max,median,1);
				median=x;
			}
			arr[i]=((((a*median)%1000000007+(b*i))%1000000007+c)%1000000007)%1000000007;
			if(arr[i]<=median)
			{
			//	max[++left]=arr[i];
				insert(max,arr[i],1);
			}
			else
			{
			//	min[++right]=arr[i];
				insert(min,arr[i],0);
			}
		}
		for(i=1;i<=n;i++)
		{
			sum+=arr[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
