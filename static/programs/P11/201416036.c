#include<stdio.h>
int first=0;
int main(){
first++;
int n;
	scanf("%d",&n);
	while(n!=0)
	{
int a[100005],a1[100005],a2[100005],i,j,r,t,y;
	long long ans;
		first++;
		ans=0;
i=0;
while(i<n)
{first++;
scanf("%d",&a[i]);
i++;}
		a1[0]=-1;
i=1;
while(i<n)
		
		{
first++;
			j=i-1;
			while(j>=0)
{first++;
				if(a[j]>=a[i])
{first++;
					j=a1[j];}
				else {first++;
					break;}}
			a1[i]=j;
i++;
		}
		a2[n-1]=n;
		for(i=n-2;i>=0;i=i-1)
		{
first++;
			j=i+1;
			while(j<=n-1)
				{first++;
				if(a[j]>=a[i]){first++;j=a2[j];}
				else {first++;break;}}
			a2[i]=j;
		}
		for(i=0;i<n;i=i+1)
{first++;
			if(((long long)(a2[i]-1-a1[i])*a[i])>ans)
				{first++;ans=(long long)(a2[i]-a1[i]-1)*a[i];}}
		printf("%lld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
