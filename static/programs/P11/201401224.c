#include<stdio.h>
int main()
{
	long int n,i,j,b[100005];
	long int a[100005],s,t=0;
	scanf("%ld",&n);
	while(n!=0)
	{
		t=0;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		j=-1;
		for(i=0;i<n;i++)
		{	
			if(j>-1)
			{
				if(a[i]>=a[b[j]])
				{
					j++;
					b[j]=i;
				}
				if(a[i]<a[b[j]])
				{
					while((a[b[j]]>a[i])&&j>=0)
					{
						if(j==0)
							s=a[b[j]]*i;
						else
							s=a[b[j]]*(i-b[j-1]-1);
						j=j-1;
						if(t<s)
							t=s;
					}
					j++;
					b[j]=i;
				}
			}
			if(j==-1)
			{
				j++;
				b[j]=i;
			}
		}
		while(j!=-1)
		{
			if(j==0)
				s=a[b[j]]*i;
			else
				s=a[b[j]]*(i-b[j-1]-1);
			j=j-1;
			if(t<s)
				t=s;
		}
		printf("%ld\n",t);
		scanf("%ld",&n);
	}
	return 0;
}
