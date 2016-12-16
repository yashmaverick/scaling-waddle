#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int no;
	long long int count;


}node;
int main ()
{
	long long int i,j,n=1,hi[100005],top=0,tsum=0,tcount=0,max=0;
	node a[100005];
	while(n!=0)
	{
		top=-1;
		tcount=0;
		max=0;
		tsum=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&hi[i]);
		}

		for(i=0;i<n;i++)
		{
			tcount=0;

			if(top==-1)
			{
				a[++top].no=hi[i]; 
				a[top].count=1; 

			}
			else if(hi[i]<a[top].no)
			{
				while((hi[i]<a[top].no)&&(top>=0))
				{
					tcount=tcount+a[top].count;
					tsum=tcount*a[top].no;
					top--;
					if(tsum>max)
						max=tsum;


				}

				if(hi[i]!=a[top].no)
				{
					a[++top].count=1+tcount;
					a[top].no=hi[i];

				}
				else
					a[top].count=a[top].count+tcount+1;


			}
			else if(a[top].no==hi[i])
				a[top].count++;
			else
			{
				a[++top].no=hi[i];
				a[top].count=1;
			}

		}
		tcount=0;
		tsum=0;
		while((top>=0)&&(n!=0))
		{
			tcount=tcount+a[top].count;
			tsum=tcount*a[top].no;
			top--;
			if(tsum>max)
				max=tsum;

		}

		if(n!=0)
			printf("%lld\n",max);
                
	

	}

	return 0;
}
