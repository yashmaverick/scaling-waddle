#include<stdio.h>

long long int stack[1000001],top;


int main()
{
	while(1)
	{

	long long int n,i,a[1000001],temp,j;
		long long ans=0,max=0;

		scanf("%lld",&n);

		if(n==0)   break;


		for(i=0;i<n;i++)
			scanf("%lld",&a[i]); 

		top=0;
		stack[0]=0; top++;
		i=1;

		while(i<n)
		{
			if(top==0 || a[i]>=a[stack[top-1]])
			{
				stack[top]=i; i++; top++;

/*				for(j=top-1;j>=0;j--)
					printf("%d ",stack[j]);
				printf("\n");
*/
			}

			else  //&& a[stack[top-1]]>a[i])
			{
				temp=stack[top-1];

				top--;

				if(top!=0)
					ans=(i-stack[top-1]-1)*a[temp];

				else
					ans=i*a[temp];


				if(ans>max)  
					max=ans;

			}
		if(top<0)
			top=0;

		}

		while(top>0)
		{
			temp=stack[top-1];
			top--;

			if(top!=0)
				ans=(i-stack[top-1]-1)*a[temp];

			else
				ans=i*a[temp];


			if(ans>max)  
				max=ans;


		}	

		printf("%lld\n",max);

	}



	return 0;
}
