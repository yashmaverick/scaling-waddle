#include <stdio.h>
int arr[1001];
char s[1001];
void find(int arr[], int arr_len, int k);
int divide(int arr[], int x, int y);
void sort(int arr[], int x, int y);
int main()
{
	int t,n,i,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%s %d",s,&arr[i]);
		find(arr,n,k);
	}
	return 0;
}
void find(int arr[],int arr_len,int k)
{
	int l,r,i;
	sort(arr,0,arr_len-1);
	for (i=0;i<arr_len-2;i++)
	{
		l=i+1;
		r=arr_len-1;
		while (l<r)
		{
			if(arr[i]+arr[l]+arr[r]==k)
			{
				printf("YES\n");
				return;
			}
			else if(arr[i]+arr[l]+arr[r]<k)
				l++;
			else
				r--;
		}
	}
	printf("NO\n");
	return;
}
int divide(int arr[],int x,int y)
{
	int x1=arr[y],i=(x-1),j,temp;
	for (j=x;j<=y-1;j++)
	{
		if(arr[j]<=x1)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[y];
	arr[y]=temp;	
	return (i + 1);
}       
void sort(int arr[],int x,int y)
{
	int z;
	if(x<y)
	{
		z=divide(arr,x,y);
		sort(arr,x,z-1);
		sort(arr,z+1,y);
	}
}
