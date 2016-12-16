#include <stdio.h>
int main()
{
		int ax[1000000], bx[1000000], i, j, n, test, a, b, index1, index2, i1, i2, flag =0, ans;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&ax[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&bx[i]);
		}
		scanf("%d",&test);
		while(test>0)
		{   flag = 0;
			test--;
			scanf("%d",&a);
			scanf("%d",&b);
			for(i=0;i<n;i++)
			{
				if(bx[i]==a)
					index1=i;
				if(bx[i]==b)
					index2=i;
			}
			
			if(index1>index2)
			{
				i1=index2;
				i2=index1;
			}
			else
			{
				i1=index1;
				i2=index2;
			}

			for(i=0;i<n;i++)
			{
				for(j=i1;j<=i2;j++)
				{
					if(ax[i]==bx[j])
					{
						ans=ax[i];
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
			}
			printf("%d\n",ans);
		}
		return 0;
}