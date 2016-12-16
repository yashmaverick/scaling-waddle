#include<stdio.h>
int first,last;
void push(int arr[],int ele)
{
	if(first==0&&last==0)
	{
		first++;
		last++;
		arr[first]=ele;
	}
	else
	{
		last++;
		arr[last]=ele;
	}
}
void popup(int arr[])
{
		if(first==last)
		{
			first=0;
			last=0;
		}
		else
		{
			first++;
		}
}
void popbot(int arr[])
{
	if(first==last)
	{
		first=0;
		last=0;
	}
	else
	{
		last--;
	}
}
void mini(int a[],int arr[],int i,int j)
{
	int b,c,d;
	push(arr,a[i]);
	for(b=i+1;b<=j;b++)
	{
		while(last!=0&&a[b]<arr[last])
		{
			popbot(arr);
		}
		push(arr,a[b]);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		first=0;
		last=0;
		scanf("%d%d",&n,&k);
		int a[n+2],arr[n+2],i,j,l,min;
		for(i=1;i<=n;i++)
		{	
			scanf("%d",&a[i]);
		}
		mini(a,arr,1,k);
		printf("%d",arr[first]);
		int index=1;
		for(j=k+1;j<=n;j++)
		{
			if(a[index]==arr[first])
			{
				popup(arr);
			}
			while(a[j]<arr[last]&&last!=0)
			{
				popbot(arr);
			}
			push(arr,a[j]);
			printf(" %d",arr[first]);
			index++;
		}
		printf("\n");
	}
	return 0;
}
