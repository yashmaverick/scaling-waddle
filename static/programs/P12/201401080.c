#include<stdio.h>
long long int a[500000],b[500000];
int main()
{
	while(1)
	{
		long long int n,i,top=0,j,p=0,temp,v;
		scanf("%lld",&n);
		if(n==0)
			break;

		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		b[top]=0;
		j=1;
		while(j<n)
		{
			
			if(top==-1 || a[j]<=a[b[top]])
			{
				top++;
				b[top]=j;
				j++;
				v=top;
				if(v>=2)

				{
					temp=a[b[v]];
					while(temp==a[b[v-1]] && v>=1)
						v--;
					if(v>0)
						p=p+v-1;



				}
				//printf("ans%d ",p);




			}
			else//if(a[j]>a[b[top]])
			{
				top--;
				p=p+n-j-1;
			}
		}
		printf("%lld\n",p);

	}
	return 0;
}













