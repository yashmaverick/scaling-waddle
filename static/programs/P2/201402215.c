#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p,q,r,i;
		long long int a[100000]={0},b[100000]={0},c[100000]={0},d[100000]={0};
		scanf("%d",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%d",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%d",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		int start=0,end=r-1,flag=0;
		long long int count=0;

		for(i=0;i<q&&start<r;)
		{	
			//printf("%d\n",i);

			if (i>start)
				start++;
			if(i<=start&&b[i]<=c[start])
			{	d[i]=r-start;
				i++;
			}
			if(i<=start&&b[i]>c[start])
			{	//d[i]+=d[i+1];
				start++;

			}
		}

//		for(i=0;i<q;i++)
//			printf("%lld ",d[i]);
//		printf("\n");
		for(i=q-2;i>=0;i--)
			d[i]+=d[i+1];
	//	end=q-1;
//		for(i=0;i<q;i++)
//			printf("%lld ",d[i]);
//		printf("\n");
	//	d[q]=0;
		start=0;
		for(i=0;i<p&&start<q;)
		{	
			if (i>start)
				start++;
			if(i<=start&&a[i]<=b[start])
			{	count+=d[start];
				i++;


			}
			if(i<=start && a[i]>b[start])
			{
				start++;


			}


		}
		/*	if(a[i]<=b[end]&&end>=i)
			{	count+=d[end];
			end--;

		//	printf("%d\n",start);
		}
		else
		{		i--;

		}
		}*/

		printf("%lld\n",count);
}
return 0;
}
