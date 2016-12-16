#include<stdio.h>
int main()
{
		int n,j,t=0;
		scanf("%d",&n);
		int i,pre[100002],in[100002];
		for(i=0;i<n;i++)
			scanf("%d",&pre[i]);
		for(i=0;i<n;i++)
		{
			scanf("%d",&in[i]);
		}
		int test,a;
		scanf("%d",&test);
		for(a=0;a<test;a++)
		{
			int n1,n2,k,i1,i2,ans;
			scanf("%d %d",&n1,&n2);
			for(k=0;k<n;k++)
			{
				if(in[k]!=n1)
					continue;
				else
				{
					i1=k;
					break;
				}
			}
			for(k=0;k<n;k++)
			{
				if(in[k]!=n2)
					continue;
				else
				{
					i2=k;
					break;
				}
	                  }
			int gg=0,p,x,y;
			if(i1-i2==1 || i1-i2==-1)
		        {
				for(k=0;k<n;k++)
				{
					if(pre[k]==in[i1])
						x=k;
					if(pre[k]==in[i2])
						y=k;
				}
				if(x<y)
					printf("%d\n",pre[x]);
				else
					printf("%d\n",pre[y]);
			}


			else
			{
				if(i1>i2)
					i1=i1+i2-(i2=i1);
				for(k=0;k<n;k++)
				{
				for(p=i1-1;p<i2;p++)
				{if(pre[k]==in[p+1])
					{
						gg=33333;
						ans=pre[k];
						break;
					}
				}
				if(gg==33333)
				{
					printf("%d\n",ans);
					break;
				}
			        }
			
			}
		   }
		return 0;
}












