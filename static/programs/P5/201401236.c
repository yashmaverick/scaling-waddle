#include<stdio.h>
int b[1001];
char ss[10001];
int main()
{
	int n,i,s,add,test,high,low,k;
	scanf("%d",&test);
	while(test--)
	{
		s=1;
		int temp;
		scanf("%d%d",&n,&add);
		for(i=0;i<n;i++)
			scanf("%s %d",ss,&b[i]);
		for(k=0;k<n-1;++k)
			for(i=0;i<n-k-1;++i)
			{
				if(b[i]>b[i+1])   
				{
					temp=b[i];
					b[i]=b[i+1];
					b[i+1]=temp;
				}
			}

		for(k=0;k<n-2;k++)
		{
			low=k+1;
			high=n-1;
			while(low<high)
			{
				if(b[k]+b[low]+b[high]>add)
					high--;
				else if(b[k]+b[low]+b[high]<add)
					low++;
				else if(b[k]+b[low]+b[high]==add)
				{
					//	printf("found with:%d %d %d\n",b[k],b[low],b[high]);
					s=0;				 
					break;
				}
			}
			if(s==0)
				break;
		}
		if(s==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
