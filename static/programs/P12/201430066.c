#include<stdio.h>
int main()
{

	int n;
	while(1)
	{	
		scanf("%d",&n);
		if(n==0)
			break;
		int i=0,h[n];
		while(i<n)
		{
			scanf("%d",&h[i]);
			i++;
		}
		int v,r,s,count=0;
		i=0;
		while(i<(n-2))
		{	
			v=i;
			r=i+2;
			while(r<n)
			{
				s=i+1;
				while(s<r)
				{
					if(h[r]!=h[s] ||  h[v]!=h[s])
					{	if(h[v]<h[s] || h[r]<h[s])
						{	
							count++;
							break;
						}
					}
					s++;
				}
				r++;
			}
			i++;
		}
		printf("%d\n",count);
	}
	return 0;
}
