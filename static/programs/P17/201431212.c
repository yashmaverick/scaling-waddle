#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,t,m,n1,n2,cur1,cur2,first,last;
	scanf("%d",&n);
	int pre[n],in[n];
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		int r1=-1,r2=-1,flag=0,ans=0;
		first=-1,last=-1;
		scanf("%d%d",&n1,&n2);
		for(j=0;j<n;j++)
		{
			if(in[j]==n1)
				r1=j;
			if(in[j]==n2)
				r2=j;
			if(r1!=-1 && r2!=-1)
				break;
		}
		if(r1<=r2)
		{
			first=r1;
			last=r2;
		}
		else
		{
			first=r2;
			last=r1;
		}
		i=0;
		while(i<n)
		{
			ans=0;
			flag=0;
			j=0;
			while(j<n)
			{
				if(pre[i]==in[j])
				{
					if(j>=first && j<=last)
					{
						ans=in[j];
						flag=1;
						break;
					}
					else
						i++;
					if(flag==1)
						break;
				}
				//				if(flag==1)
				//					break;
				//				if(pre[i]!=in[j])
				else
					j++;
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
