#include<stdio.h>

int main()
{

	int n,pre[1000000],in[1000000],t,i,j,end=0,start=0,ans,a,b;

	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);

	for(i=0;i<n;i++)
		scanf("%d",&in[i]);

	scanf("%d",&t);

	while(t--)
	{
	
		scanf("%d %d",&a,&b);

		for(i=0;i<n;i++)
		{
			if(a==in[i])
				start=i;
		
			else if(b==in[i])
				end=i;
		}

		if(start > end)
		{
			int temp=start;
			start=end;
			end=temp;
		
		}

		for(i=0;i<n;i++)

			for(j=start;j<=end;j++)

				if(pre[i]==in[j])
				{
					ans=in[j];
					goto end;
				
				}

end:;
		printf("%d\n",ans);
		

	}
	return 0;

}
