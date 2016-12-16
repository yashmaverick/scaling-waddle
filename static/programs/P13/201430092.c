#include<stdio.h>
int dep=-1,ldep=-1,min=0;
void f(int a[],int s,int e,int b[],int d)
{
	if(s>e)
		return;
	if(s==e)
	{
		if(d>dep)
		{
			dep=d;
			if(d==ldep)
			{
				if(a[s]<min)
					min=a[s];
			}
			else
				min=a[s];
			ldep=d;
		}
		return;
	}
	f(a,s,b[e],b,d+1);
	f(a,b[e]+1,e-1,b,d+1);
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		dep=-1,ldep=-1,min=0;
		int stack[100000],y[100000],x[100000],j,m,i;
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&x[i]);
		stack[0]=0;
		j = 0;
		y[0]=-1;
		for(i=1;i<m;i++)
		{
			if(x[i]>x[stack[j]])
			{
				y[i]=stack[j];
			}
			else
			{
				while(x[i]<=x[stack[j]] && j>0)
				{
					j--;
				}
				if(j==0)
				{
					if(x[i] > x[0])
					{
						y[i]=0;
					}
					else
					{
						y[i]=-1;
					}
				}
				else
				{
					y[i]=stack[j];
				}
			}
			j++;
			stack[j]=i;
		}
		f(x,0,m-1,y,0);
		printf("%d %d\n",min,dep);
	}
	return 0;
}
