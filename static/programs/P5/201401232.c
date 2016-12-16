#include<stdio.h>
void Sort(int arr[],int low,int mid,int high);
void divide(int arr[],int low,int high);
int main()
{
int test;
scanf("%d",&test);
while(test>0)
{
	int a[1000],i,n,j,l,u,mid,c=0,k;
	scanf("%d",&n);
	scanf("%d",&k);
	char d;
	for(i=0;i<n;i++)
	{
		while((d=getchar())!=' ');
		scanf("%d",&a[i]);
	}
	divide(a,0,n-1);
	//	for(i=0;i<n;i++)
	//	{
	//		printf("%d ",a[i]);
	//	}
	for(i=0;i<n-2;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			l=j+1,u=n-1;
			while(l<=u)
			{
				mid=(l+u)/2;
				if(a[mid]+a[i]+a[j]==k)
				{
					c=1;
					break;									
				}
				else if(k<a[mid]+a[i]+a[j])		
				{
					u=mid-1;
				}
				else
					l=mid+1;														        }
		 	if(c==1)
			{
				printf("YES");
					printf("\n");
				break;
			}
		}
			if(c==1)
			{
			break;	
                	}
	}
		if(c==0)
			printf("NO\n");
test=test-1;
}
		return 0;
}
void divide(int arr[],int low,int high)
	{
		int mid;
		if(low<high)
		{
			mid=(low+high)/2;
			divide(arr,low,mid);
			divide(arr,mid+1,high);
			Sort(arr,low,mid,high);
		}
	}
void Sort(int arr[],int low,int mid,int high)
	{
	int i,m,k,l,temp[1000];
		l=low;
		i=low;
		m=mid+1;
		while((l<=mid)&&(m<=high))
		{
			if(arr[l]<=arr[m])
			{
				temp[i]=arr[l];
				l++;
			}
			else
			{
				temp[i]=arr[m];
				m++;
			}
			i++;
		}
		if(l>mid)
		{
			for(k=m;k<=high;k++)
			{
				temp[i]=arr[k];
				i++;
			}
		}
		else
		{
			for(k=l;k<=mid;k++)
			{
				temp[i]=arr[k];
				i++;
			}
		}
		for(k=low;k<=high;k++)
		{
			arr[k]=temp[k];
		}
	}
