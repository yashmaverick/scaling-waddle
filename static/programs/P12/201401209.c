#include<stdio.h>
int main()
{
	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0) break;
		long long int a[n],i,ans=0,stack[n],sp=0,max=0,temp,count=0;
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		stack[sp]=0;
		for(i=1;i<n;i++)
		{
			if(a[i]>a[max]) max=i;
			if(a[i]<a[stack[sp]]) { sp++; stack[sp]=i;ans++; }
			else if(a[i]==a[stack[sp]])
			{
				temp=sp; count=0;
				//printf("sp=%lld stack[sp]=%lld\n",sp,stack[sp]);
				while(temp!=-1 && a[stack[temp]]==a[i]) { temp--; count++;}
				//printf("temp=%lld count=%lld\n",temp,count);
				sp++; stack[sp]=i;
				ans=ans+count; if(a[i]!=a[max])ans++;
				//printf("ans=%lld\n",ans);
			}
			else
			{
				while(sp!=-1 && a[stack[sp]]<a[i]) { sp--; ans++;  }
				if(sp==-1) { sp++; stack[sp]=i; }
				else if(a[i]==a[stack[sp]])
				{
					temp=sp; count=0;
				//	printf("sp=%lld stack[sp]=%lld\n",sp,stack[sp]);
					while(temp!=-1 && a[stack[temp]]==a[i]) { temp--; count++;}
				//	printf("temp=%lld count=%lld\n",temp,count);
					sp++; stack[sp]=i;
					ans=ans+count; if(a[i]!=a[max]) ans++;
				}
				else
				{
					sp++; stack[sp]=i;
					ans++;
				}
				//printf("ans=%lld\n",ans);
			}		
		}		long long int fans=(n*(n-1))/2-ans;
		printf("%lld\n",fans);

	}
	return 0;
}