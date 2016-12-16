#include<stdio.h>
int main()
{
	int p,t,i,j,n,k,c,d,A[1000],s=0,u,l,temp,m;
	char e,a;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&k);
		j=0;
		u=n;
		while(u!=0)
		{
			e=a;
			while( e!=' ')
				e=getchar();
			scanf("%d",&A[j]);
			j++;
			u--;
		}
		for(j=0;j<n;j++)
		{
			for(m=0;m<n;m++)
			{
				if(A[j]<A[m])
				{
					temp=A[j];
					A[j]=A[m];
					A[m]=temp;
				}
			}
		}
		for(j=0;j<n-2;j++)                
		{
			c=j+1;
			d=n-1;
			while(c<d)
			{
				s=A[j]+A[c]+A[d];
				if(s==k)
				{
					printf("YES\n");
					break;
				}
				else if(s<k)
					c++;
				else
					d--;
			}
			if(s==k)
				break;
		}
		if(s!=k)
			printf("NO\n");
	}
	return 0;
}
