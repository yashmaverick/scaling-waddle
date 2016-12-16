#include<stdio.h>
long long int Temp[10010],Array[10010];
void merge(int i,int j)
{
	int k,mid,l,start;
	start=i;
	mid=(i+j)/2;
	k=mid+1;
	l=i;
	while(i<=mid&&k<=j)
		if(Array[i]<=Array[k])
			Temp[l++]=Array[i++];
		else
			Temp[l++]=Array[k++];
	if(i>mid)
		for(;k<=j;)
			Temp[l++]=Array[k++];
	else if(k>j)
			for(;i<=mid;)
				Temp[l++]=Array[i++];
	for(l=start;l<=j;l++)
		Array[l]=Temp[l];
	return;
}
void mergesort(int i,int j)
{
	int k,mid;
	if(i>=j)
		return;
	mid=(i+j)/2;
	mergesort(i,mid);
	mergesort(mid+1,j);
	merge(i,j);
}
int main()
{
	int tc,i,wall,final,flag,temp,n,j,k;
	char str[100];
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		flag=0;
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)
		{
			scanf("%s",str);
			scanf("%d",&Array[j]);
		}
		mergesort(0,n-1);
		for(j=0;j<=n-3;j++)
		{
			final=n-1;
			wall=j+1;
			while(final>wall)
			{
				temp=Array[j]+Array[final]+Array[wall];
				if(temp==k)
				{
					flag=1;
					break;
				}
				else if(temp>k)
					final--;
				else
					wall++;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}
