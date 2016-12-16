#include<stdio.h>
int c[100001],b[100000];
void function(int start,int end,int a[],int count)
{
	int i;
	c[a[end]]=count;
//	printf("%d *********%diiiiiiii%d\n",a[start],a[end],count);
	//for(i=start;i<=end;i++)
	//	printf("%d  ",a[i]);
	//printf("\n");
//	printf("%d\n",c[end]);
///	printf("%d %d \n",start,end);
	if(start==end)
	{	c[a[start]]=count;
		return ;
	}
//		printf("%d**** %d\n",start,b[end]);
//	c[a[end]]=count;
	if(b[end]==-1)
	{	if(b[end]+1<=end-1)	
			function(b[end]+1,end-1,a,count+1);
	}
	else{
		if(start<=b[end])
			function(start,b[end],a,count+1);
		if(b[end]+1<=end-1)
			function(b[end]+1,end-1,a,count+1);
	}


}


int main()
{	int t;
	scanf("%d",&t);
	while(t--)
	{
	int n,i,j,max=0,ans;
	scanf("%d",&n);
	int a[100000],count;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);

	}
	b[0]=-1;
	for(i=1;i<n;i++)
	{	
		j=i-1;
		if(a[i]>a[i-1])
			b[i]=i-1;
		else
		{	if(b[j]==-1)
			b[i]=-1;
			while(b[j]!=-1)
			{	
				if(a[b[j]]<a[i])
				{b[i]=b[j];
					break;
				}
				else
				{
					j=b[j];
				}
			}
			if(b[j]==-1)
				b[i]=-1;
		}
	}
	//for(i=0;i<n;i++)
	//	printf("%d ",b[i]);
	//printf("\n");
			function(0,n-1,a,0);
	for(i=1;i<n+1;i++)
	{
		//printf("%d ",c[i]);
		if(c[i]>max)
		{	max=c[i];
			ans=i;
		}
	}
		if(max==0)
			printf("1 0\n");
		else
			printf("%d %d\n",ans,max);
	}
		
	return 0;
}
	



