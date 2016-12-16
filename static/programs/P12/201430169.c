#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int *S,p,q,count,n,i,j,ans,x,flag;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			return 0;
		S=(long long int*)malloc(n*sizeof(long long int));
		scanf("%lld",&x);
		
		S[0]=x;count=0;
		
		q=1;i=1;
		while(i<n)
		{
			scanf("%lld",&x);flag=0;
			if(x<S[q-1])
				count++;
			else if(x>S[q-1])
			{
				j=q-1;
				while(j>=0 && S[j]<=x)
				{
					
					count++;
					if(S[j]==x && flag==0)
					{	q=j+1;flag=1;}
					j=j-1;
				}
				if(j!=-1 && S[j]>x)
					count++;
				if(j!=-1 && flag==0)
					q=j+1;
				else if(j==-1 && flag==0)
					q=0;//printf("for i=%d x=%d j=%d\n",i,x,j);
			}
			else if(x==S[q-1])
			{
				j=q-1;
				while(j>=0 && S[j]<=x)
				{
					j--;
					count++;
				}
				if(j!=-1 && S[j]>x)
					count++;
			}
			S[q++]=x;//printf("i=%d x=%d S[%d]=%d\n",i,x,q-1,S[q-1]);
			i++;
		}
		
		
		ans=(n*(n-1))/2-count;
		printf("%lld\n",ans);
	}
	
}	
