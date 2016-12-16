#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MOD 1000000007
#define ll long long int

int compare (const void * a, const void * b)
{
  return ( *(ll*)a - *(ll*)b );
}

ll t,l,i,hash[100100],cnt,ans;
char s[100100];

int main()
{
    scanf("%lld",&t);
    while(t--)
    {
    	cnt=1;
    	ans=0;
    	scanf("%s",s);
    	l=strlen(s);
    	//printf("%lld\n",l);
    	hash[0]=0;
    	for(i=1;i<=l;i++)
    	{
    		if(s[i-1]=='J')hash[i]=hash[i-1]+1;
    		else if(s[i-1]=='M')hash[i]=hash[i-1]+1000000;
    		else if(s[i-1]=='R')hash[i]=hash[i-1]-1000001;
    	}
    	//for(i=0;i<=l;i++)printf("%lld\t",hash[i]);
    	qsort (hash, l+1, sizeof(long long int), compare);
    	
    	//printf("\n");
    	for(i=1;i<=l;i++)
		{
			if(hash[i]==hash[i-1])cnt++;
			else
			{
				//if(hash[i-1]==0&&cnt==1)ans+=1;
				if(cnt>=2)ans+=(cnt*(cnt-1)/2);
				cnt=1;
			}
		}
		if(cnt>=2)ans+=(cnt*(cnt-1)/2);
		printf("%lld\n",ans);
    }
	return 0;
} 
