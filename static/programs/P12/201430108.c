#include <stdio.h>
#include<stdlib.h>
long long int dp[1000][1000];
struct stack{
	long long int num[1000001];
	long long int top;
	long long int c[1000001];
};
typedef struct stack stack;
stack s;
void push (long long int i)
{
    
        s.top ++;
        s.num[s.top] = i;    
    	return;
}
void pop ()
{
    
        s.top = s.top - 1;
    return;
}
int main()
{
	long long int n,i,l,ans=0;
	long long int *m;
	long long int temp;
	long long int stc[500001][2];
	scanf("%lld",&temp);
	while(temp!=0)
	{	n=temp;
		s.top = -1;
		m=(long long int *)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++)
			scanf("%lld",&m[i]);
			long long int max=m[0];
			long long int ans=0;
			for(i=1;i<n;i++)
			{
				if(m[i]<max)
					ans++;
				else
					max=m[i];
			}
			max=m[n-1];
		l=0;	//pointer for stack
		for(i=n-2;i>=0;i--)
			{
				if(m[i]<max)
					ans++;
				else
					max=m[i];
			}
	//printf("**%lld**\n",ans);
			long long int c;
			long long int top;
		stc[0][0]=m[0];
		stc[0][1]=1;
		for(i=1;i<n;i++){
			if(m[i]<stc[l][0]){
				l++;
				stc[l][0]=m[i];
				stc[l][1]=1;
			}
			else{
				while(stc[l][0]<m[i] && l>0)
					l--;
				if(l==0){
					if(stc[0][0]>m[i]){
						l++;
						stc[l][0]=m[i];
						stc[l][1]=1;
					}
					else if(stc[l][0]==m[i]){
						ans+=stc[l][1];
						stc[l][1]++;
					}
					else{
						stc[0][0]=m[i];
						stc[0][1]=1;
					}
				}
				else{
					if(stc[l][0]==m[i]){
					//printf("##%lld##\n",stc[l][1]);
					//printf("aaa%lld %lldaaa\n",m[i],l );
						ans=ans+stc[l][1];
						stc[l][1]++;
					}
					else{
						l++;
						stc[l][0]=m[i];
						stc[l][1]=1;
					}
				}
			}
		}
		//printf("$%lld$\n",ans);
		long long int cr=n*(n-1)*0.5;
		ans=cr-ans;
		printf("%lld\n",ans);	
		scanf("%lld",&temp);	
	}
	return 0;
}
