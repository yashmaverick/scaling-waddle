#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int p[n],i[n],j;
	for(j=0;j<n;j++)
	{
		scanf("%d",&p[j]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&i[j]);
	}
	int t,I,x,y,z,k,i1,sub[1000000],s,end,i2,diff,count;
	scanf("%d",&t);
	for(I=0;I<t;I++)
	{
		z=0;
		count=0;
		diff=0;
		end=0;
		i1=0;
		scanf("%d %d",&x,&y);
		for(k=0;k<n;k++)
		{
			if(i[k]==x)
			{
				i1=k;
			}
			if(i[k]==y)
			{
				i2=k;
			}
		}
		if(i1<i2)
		{
			diff=i2-i1;
			for(k=0;k<=diff;k++)
			{
				sub[k]=i[i1];
				i1++;
				count++;
			}
		}
		else if(i1>i2)
		{
			diff=i1-i2;
			for(k=0;k<=diff;k++)
			{
				sub[k]=i[i1];
				i1--;
				count++;
			}
		}
		else
			end=x;
		for(k=0;k<n;k++)
		{
			for(s=0;s<count;s++)
			{
				if(p[k]==sub[s])
				{
					end=p[k];
					break;
				}
			}
			if(end==p[k])
			{
				break;
			}
		}
		printf("%d\n",end);
	}
	return 0;
}
