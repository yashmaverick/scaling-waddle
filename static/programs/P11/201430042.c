#include<stdio.h>
long long int c[100001]={0};
long long int b[100001],a[100001];
long long int begin,end,n;
int flag;
void push(long long int val,long long int index)
{
	long long int i,j,k;
	if(end==-1)
	{
		end++;
		b[end]=index;
		return;
	}
	if(end==0) 
	{
		if(flag==1)
			k=b[end];
		else
			k=n-1-b[end];
		if(a[k]>val) 
		{
			if(flag==1)
				c[k]=1;
			else
				c[k]=1;
			b[end]=index;
		}
		else
		{
			end++;
			b[end]=index;
		}
	return;
	}
	for(i=end;i>=0;i--) 
	{
	       if(flag==1)
	       		j=b[i];
		else
	 		j=n-1-b[i];
		if(a[j]<=val) 
		{
			end=i+1;
			b[end]=index;
			return;
		} 
		else
		{
			if(flag==1) 
				c[j]=b[end]-b[i]+1;
			else
				c[j]=c[j]+b[end]-b[i];
			if(i==0)
			{
				end=0;
				b[end]=index;
			}
		}
	}
	return;
}
void count()
{
	long long int i;
	//printf("flag=%d\n",flag);
	for(i=0;i<=end;i++)
		if(flag==1)
			c[b[i]]=b[end]-b[i]+1;
		else
			c[n-1-b[i]]=c[n-1-b[i]]+b[end]-b[i];
}
int main()
{
	long long int i,k;
	while(1)
	{
	scanf("%lld",&n);
	if(n==0)
		break;
	end=-1;
	flag=1;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<n;i++)
	{
		push(a[i],i);
		//printf("end=%d\n",end);
	}
	count();
	/*for(i=0;i<=end;i++)
		printf("%d ",b[i]);
	printf("\n");
	for(i=0;i<n;i++)
	printf("begin:%d",c[i]);
	printf("\n");*/
	end=-1;
	flag=0;
	for(i=n-1;i>=0;i--)
		push(a[i],n-1-i);
	count();
	/*printf("end=%d\n",end);
	for(i=0;i<=end;i++)
		printf("%d",b[i]);
	for(i=0;i<n;i++)
	printf("end:%d ",c[i]);
	printf("\n");*/
	long long int area=0;
	for(i=0;i<n;i++)
	{
		k=c[i]*a[i];
		if(k>area)
			area=k;
	}                                   
	printf("%lld\n",area);
	}
	return 0;
}
