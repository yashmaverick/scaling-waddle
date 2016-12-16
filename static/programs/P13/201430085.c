#include<stdio.h>
int upper=-1;
int stack[1005004][2];
typedef struct akash{
int data;
int height;
}ak;	
int main()
{
	int i;
	int n;
	int query;
	scanf("%d",&query);
	int temp[1000007];	
	while(query--)
	{
		scanf("%d",&n);
		ak arr[n];
		for(i=0;i<n;i++)
			scanf("%d",&arr[i].data);
		for(i=0;i<n;i++)
			{temp[i]=arr[n-i-1].data;
		arr[i].height=0;
		     }
                         for(i=0;i<n;i++)
			arr[i].data=temp[i];
		for(i=0;i<n;i++)
		{	int flag=0;
			while(upper!=-1)
			{
				if(arr[i].data<stack[upper][0])
				{flag=1;
					
                               arr[i].height=arr[stack[upper][1]].height+1;
					upper--;
				}
				else
					break;
			}
			upper=upper+1;
			stack[upper][0]=arr[i].data;
                         stack[upper][1]=i;
			if(flag==0&&i!=0)
				arr[i].height=arr[i-1].height+1;
}
		int maximum=0;
		int store;
		for(i=0;i<n;i++)
		{
			if(arr[i].height>maximum)
			{
				maximum=arr[i].height;
				store=i;
			}
		}
			for(i=0;i<n;i++)
                         {
                          if(arr[i].height==maximum)
			{
				if(arr[i].data<arr[store].data)
					store=i;
}		
}
printf("%d %d\n",arr[store].data,arr[store].height);
		while(upper!=-1)
			upper--;
	}
	return 0;
}











