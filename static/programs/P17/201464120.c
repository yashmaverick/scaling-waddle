#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
	int *pre , *in;
	scanf("%d",&n);
	pre=(int *)malloc(n*sizeof(int));
	in=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	int t;
	scanf("%d",&t);
	while(t!=0)
	{
		int a,b,start=-1,last=-1;
		scanf("%d %d",&a,&b);
		for(i=0;i<n;i++)
		{
			if(in[i]==a)
				start=i;
			if(in[i]==b)
				last=i;
			if(start!=-1 && last!=-1)
				break;
		}
		int k,x,y;
		for(k=0;k<n;k++)
		{
			if(pre[k]==in[start])
				x=k;
			if(pre[k]==in[last])
				y=k;
		}
//		printf("%d %d %d %d\n",start,last,x,y);	
		
		if(start>last)
		{
			int temp=start;
			start=last;
			last=temp;
		}

		int j,index=n+1,ans=0,r,s;
		if(last-start==1)
		{
	//		printf("\t%d\t%d\n",start,last);
			for(j=0;j<n;j++)
			{
				if(pre[j]==in[start])
				{
					r=j;
				}
				if(pre[j]==in[last])
					s=j;
			}
			if(r<s)
				ans=in[start];
			else 
				ans=in[last];
		//	if(start==0)
		//		ans=in[last];
		}
		else if(last-start!=1)
		{
			for(i=start;i<=last;i++)
			{
				for(j=0;j<n;j++)
				{
					if(in[i]==pre[j])
					{
						if(j<index)
						{
							index=j;
							ans=pre[j];
						}
					}
				}
			}
		}
		else if(x-y==-1)
		{
			printf("%d\n",pre[x]);
			t=t-1;
			continue;
		}
		
		printf("%d\n",ans);
		t--;
	}

	return 0;
}
