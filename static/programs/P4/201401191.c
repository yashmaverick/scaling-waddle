#include<stdio.h>
#include<string.h>
typedef long long int ll;
char s[100100];
ll  tmp[100100];
void merge(ll c[],ll start,ll mid,ll end)
{
	ll i,j,k=start;
	i=start;j=mid+1;
	while(i<=mid&&j<=end)
	{
		if(c[i]<c[j])
		{
			tmp[k++]=c[i];
			i++;
		}
		else
		{
			tmp[k++]=c[j];
			j++;
		}
	}
	while(i<=mid)
	{
		tmp[k++]=c[i];
		i++;
	}
	while(j<=end)
	{
		tmp[k++]=c[j];
		j++;
	}
	for(i=start;i<=end;i++)
	{
		c[i]=tmp[i];
	}
	return;
}
void mergesort(ll arr[],ll start,ll end)
{
	ll i,j,k;
	ll mid;
	mid=(start+end)/2;
	if(start==end)
	{
		return;
	}
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,mid,end);
	return;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		ll n,i,j;
		scanf("%s",s);
		//      printf("%s",s);
		n=strlen(s);
		ll a,b,c;
		a=100001;
		b=1;
		c=-100002;
		ll arr[100100]={0};
		for(i=0;i<n;i++)
		{
			if(s[i]=='J')
			{
				arr[i]+=a;
			}
			else if(s[i]=='M')
			{
				arr[i]+=b;
			}
			else if(s[i]=='R')
			{
				arr[i]+=c;
			}
		}
		for(i=1;i<n;i++)
		{	
			arr[i]+=arr[i-1];
		}
		arr[n]=0;
		mergesort(arr,0,n);
	/*	for(i=0;i<=n;i++)
		{
			printf("%Ld ",arr[i]);
		} */ 
		ll count=0;
		int st=0;
		ll tm;
		for(i=0;i<n;i++)
		{
	/*		if(arr[i]==0)
			{
				count++;
			} */
			if(arr[i]-arr[i+1]==0)
			{
		/*		ll ss=0;
				while(arr[i]<arr[i+1]&&i<n)
				{
					ss++;	
					i++;
				}
				ss++;
				count+=((ss)*(ss-1))/2;
			} */
				if(st!=1)
				{
				tm=i;
				}
				st=1;
			}
			if(arr[i]-arr[i+1]!=0&&st==1)
			{
				ll tmp=(i-tm+1);
				tmp=((tmp)*(tmp-1))/2;
				count+=(tmp);
				st=0;
			}  
		}
		if(st==1)
		{
		ll tmp=(i-tm+1);
		tmp=((tmp)*(tmp-1))/2;
		count+=(tmp);
		}
		printf("%Ld\n",count);
	}
}
