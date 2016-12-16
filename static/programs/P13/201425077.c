#include<stdio.h>


int a[100005],c[100005];

int binary(int start,int end,int n)
{
	if(start>end) return -1;


	int mid=(start+end)/2;

	if(a[mid]>n)
	{
		if(a[mid-1]<n)
			return mid-1;

		else
			binary(start,mid-1,n);
	}
	else if(a[mid]<n)
	{
		if(a[mid+1]>n)
			return mid;
		else
			binary(mid+1,end,n);
	}

}

void tree(int start,int end,int count)
{

		//printf("cend %d %d",start,end);
	if(end-start>1)
	{
//		printf("aa");
		int left=binary(start,end-1,a[end]);

		c[end]=count;
//		printf("cend %d",count);

		if(left==-1)
		{
			c[end-1]==count+1;
			tree(start,end-1,count+1);
		}

		else if(left == end-1)
		{
			c[left]=count+1;
			tree(start,end-1,count+1);
		}

		else
		{
			c[left]=count+1; c[end-1]=count+1;
		
			tree(start,left,count+1);

			tree(left+1,end-1,count+1);
		}

	}

	else if(end-start==1)
	{
		c[end]=count;
		c[end-1]=count+1;
	}

	else if(start==end)
		c[end]=count;
		

}





int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,i,max,maxi;



		scanf("%d",&n);

		for(i=0;i<n;i++)
			c[i]=0;

		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		tree(0,n-1,0);

		max=-1; maxi=-1;
		for(i=0;i<n;i++)
			if(c[i]>max)
			{
				max=c[i];
				maxi=i;
			}
	
		printf("%d %d\n",a[maxi],max);
	//	printf("%d",binary(0,n-2,a[n-1]));


	}


	return 0;
}
