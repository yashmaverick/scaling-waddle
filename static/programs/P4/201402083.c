#include<stdio.h>
#include<string.h>
inline unsigned long long int combination(int a){
	unsigned long long int result=(unsigned long long int)((long long int )(a)*(long long int)(a-1))/2;
	return result;
}

int luck(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int main()
{
	int t,ans[100001];
	scanf("%d",&t);
	while(t--)
	{
		char arr[100001];
		scanf("%s",arr);
		int length=strlen(arr);
		int i,count=0,num0=0,p=0;
		unsigned long long temp=0;
		if(arr[0]=='J')
			ans[p++]=-100002;
		else if(arr[0]=='R')
			ans[p++]=1;
		else
			ans[p++]=100001;
		for(i=1;i<length;i++)
		{
			if(arr[i]=='J')
				ans[p++]=ans[i-1]-100002;
			else if(arr[i]=='R')
			{
				ans[p++]=ans[i-1]+1;
			}
			else
				ans[p++]=ans[i-1]+100001;
		}
		qsort(ans,p,sizeof(int),luck);
		for(i=0;i<p;i++)
		{
			if(ans[i]==0)
				++num0;
			
		}
		for(i=0;i<p-1;i++)
		{
			if(ans[i]==ans[i+1] )
				count++;
			else
			{
				if(count!=0)
					temp+=combination(count+1);
				count=0;
			}
		}
		if(count!=0)
			temp+=combination(count+1);
		temp+=(unsigned long long int)(num0);
		printf("%llu\n",temp);
	}
	return 0;
}





