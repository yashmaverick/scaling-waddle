#include<stdio.h>
void swap(int *a, int *b)
{
	int t=*a; *a=*b; *b=t;
}
void sort(int arr[], int beg, int end)
{
	if (end > beg + 1)
	{
		int piv = arr[beg], l = beg + 1, r = end;
		while (l < r)
		{
			if (arr[l] <= piv)
				l++;
			else
				swap(&arr[l], &arr[--r]);
		}
		swap(&arr[--l], &arr[beg]);
		sort(arr, beg, l);
		sort(arr, r, end);
	}
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,k,i,m;
		scanf("%d %d",&n,&k);
		int a[100000],j,l;char b[10000];i=0;char c;
		int flag=0;
		for(j=0;j<n;j++)
		{

			scanf("%s",b);
			scanf("%d",&a[i]);
			i++;
			//	printf("%s",b);
		}
		sort(a,0,n);
		//		for(l=0;l<n;l++)
		//		{

		//			printf("%d",a[l]);
		//		}
		for(j=0;j<=n-3;j++)
		{
			l=j+1;
			m=n-1;
			while(m>l)
			{
				if(a[j]+a[l]+a[m]==k)
				{
					printf("YES\n");
					flag=1;
					break;
				}

				(a[j]+a[l]+a[m]>k)?m--:l++;
			}
			if (flag==1)
				break;
			if(j==n-3)
				printf("NO\n");
		}
//		if(flag==0)
//				printf("NO\n");

	}
	return 0;
}
