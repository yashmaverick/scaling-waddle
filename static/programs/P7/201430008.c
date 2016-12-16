#include<stdio.h>
long long int x[1000007];
/*int merge(long long int arr[], long long int l,long long int m, long long int h)
 *   {
 *     int arr1[10000007], arr2[10000007];
 *       int n1, n2, i, j, k;
 *         n1 = m - l + 1;
 *           n2 = h - m;
 *             for(i = 0; i < n1; i++)
 *               arr1[i] = arr[l + i];
 *                 for(j = 0; j < n2; j++)
 *                   arr2[j] = arr[m + j + 1];
 *                     arr1[i] = 9999;
 *                       arr2[j] = 9999;
 *                         i = 0;
 *                           j = 0;
 *                             for(k = l; k <= h; k++)
 *                               {
 *                                 if(arr1[i] <= arr2[j])
 *                                   arr[k] = arr1[i++];
 *                                     else
 *                                       arr[k] = arr2[j++];
 *                                         }
 *                                           return 0;
 *                                             }
 *                                               int merge_sort(long long int arr[],long long int low,long long int high)
 *                                                 {
 *                                                   int mid;
 *                                                     if(low < high) 
 *                                                       {
 *                                                         mid = (low + high) / 2;
 *                                                           merge_sort(arr, low, mid); 
 *                                                             merge_sort(arr, mid + 1, high); 
 *                                                               merge(arr, low, mid, high); 
 *                                                                 }
 *                                                                   return 0;
 *                                                                     }*/
void merge(long long int x[],long long int l,long long int m,long long int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r-m;
	int L[n1], R[n2];
	for(i = 0; i < n1; i++)
		L[i] = x[l + i];
	for(j = 0; j < n2; j++)
		R[j] = x[m + 1+ j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			x[k] = L[i];
			i++;
		}
		else
		{
			x[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		x[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		x[k] = R[j];
		j++;
		k++;
	}
}
void mergesort(long long int x[],long long int l,long long int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2; 
		mergesort(x, l, m);
		mergesort(x, m+1, r);
		merge(x, l, m, r);
	}
}
int main()
{
	long long int n,i,l,v,m,j;
	long long int t,k;
	scanf("%lld",&t);
	for(k=0;k<t;k++)
	{
		v=1;
		m=0;
		l=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&x[i]);
		mergesort(x,0,n-1);
		//for(i=0;i<n;i++)
		//	//	printf("%lld",x[i]);
		for(j=0;j<n-1;j++)
		{
			if(x[j]==x[j+1])
				v++;
			else
			{
				m=(v*(v-1))/2;
				v=1;
				l=l+m;
			}

		}
		m=(v*(v-1))/2;
		l=l+m;
		printf("%lld\n",l);
	}
	return 0;
}

