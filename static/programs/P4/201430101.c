#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long int ll;

int cmpfunc (const void * a, const void * b)
{
	   return ( *(ll*)a - *(ll*)b );
}

int main()
{
	int test;
	ll i,v,j,sum;
	char c[100001];
	//ll arr[100004];
	scanf("%d",&test);
	while(test--)
	{
	  scanf(" %[^\n]",c);
          v=strlen(c);
	  ll*arr=(ll*)malloc(sizeof(ll)*(v+1));
	  arr[0]=0;
		sum=0;
	
	//     	printf("%s",c);	
			ll p=1;
	  for(i=0;c[i]!='\0';i++)
	  {
		if(c[i]=='J')
			sum=sum+1000003;
		else if(c[i]=='M')
			sum=sum-3;
		else if(c[i]=='R')
			sum=sum-1000000;
		arr[p++]=sum;
	  }
	  qsort(arr,p, sizeof(ll), cmpfunc);
	//  for(i=0;i<v+1;i++)
	//`:w	  printf("%lld--",arr[i]);
	 // printf("%lld\n",arr[1]);
	  ll count=0;
	  ll ans=0;
	  for(i=0;i<p;i++)
	  {
	//	if(arr[i]==arr[i+1])
	//		count++;
		if(arr[i]!=arr[i+1])
		{
			count++;
			ans=ans+(count*(count-1))/2;
			count=0;
		}
		else
			count++;
	  }
		printf("%lld\n",ans);
	}
	return 0;
}
		  
		
