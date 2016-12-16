#include<stdio.h>
int main()
{
	int n,i,j,a[500005],b[500005],k,l,q,t,p,x;
	long long s;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		j=-1;s=0;
		for(i=0;i<n;i++)
		{
			if(j!=-1)
			{
				if(a[i]<=a[b[j]])
				{
					j++;
					b[j]=i;
				}
				else if(a[i]>a[b[j]])
				{
					while(j>=0&&(a[i]>a[b[j]]))
					{
						x=j;
						while(x>0&&a[b[x]]==a[b[x-1]])
							x--;
						if(x!=0)
							s=s+(long long)(j-x+1)*(long long)(x-1);
						s=s+(long long)(j-x+1)*(long long)(n-i-1);
						j=x-1;
						if(j==-1)
							break;
					}
					//printf("%d %d   ",i,s);
					j=j+1;
					b[j]=i;
				}
			}
			if(j==-1)
			{
				j++;
				b[j]=i;
			}
		}
		while(j>1)
		{
			x=j;
			while(x>0&&a[b[x]]==a[b[x-1]])
				x--;
			if(x!=0)
				s=s+(long long)(j-x+1)*(long long)(x-1);
			j=x-1;
	//		printf("%d %d %d %d %d\n",l,j,k,s,t);
		}
		printf("%lld\n",s);
//		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
