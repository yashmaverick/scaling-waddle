#include<stdio.h>
#include<string.h>
int main()
{
	int t,n,s,i,j,k,state,arr[100000];
		char b[100000];
	scanf("%d",&t);
	while(t--)
	{
		state=0;
		scanf("%d%d",&n,&s);
		for(i=0;i<n;i++)
		{
			scanf("%s",b);
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;i++)
		{
			for (j=i+1;j<n;j++)
			{
			if(arr[i]>s)
			{
				break;
			}
				for(k=j+1;k<n;k++)
				{             
				if(arr[i]+arr[j]>s)
				{
					break;
				}
					if(arr[i]+arr[j]+arr[k]==s)
					{
						state=1;
						break;
		}}}
			if(state==1)
				break;
		}
		if(state==0)
			printf("NO\n");
		if(state==1)   
			printf("YES\n");
	}
	return 0;
}
