#include<stdio.h>
#include<string.h>
long long A[10000001], B[10000001];
void merge(int beg, int mid, int end)
{
	int i, j, k, l = 2e6;

	for(i=0;i+beg<=mid;++i)
		B[i] = A[i+beg];
	B[i] = 1e18;
	for(j=l;j-l+mid+1<=end;++j)
		B[j] = A[j-l+mid+1];
	B[j] = 1e18;

	i = 0, j = l, k = beg;

	while(k<=end)
	{
		if(B[i]<B[j])
		{
			A[k++] = B[i++];
		}
		else
		{
			A[k++] = B[j++];
		}
	}
}
void mergeSort(int beg, int end)
{
	int mid;
	if(beg < end)
	{
		mid = (beg+end)/2;
		mergeSort(beg, mid);
		mergeSort(mid+1, end);
		merge(beg, mid, end);
	}
}
int main()
{
	long long t, i, val, l;
	char jmr[100091];
	long long r, dupes;
	scanf("%lld", &t);
	while(t--)
	{
		dupes = 0;
		r = 0;
		scanf(" %s", jmr);
		l = strlen(jmr);
		for(i = 0; i < l; i++)
		{
			if(!i)
			{
				if(jmr[i] == 'J')
				{
					A[i] = 1e5 + 1;
				}
				else if(jmr[i] == 'M')
				{
					A[i] = 1;
				}
				else
				{
					A[i] = -1e5 - 2;
				}
			}
			else
			{
				if(jmr[i] == 'J')
				{
					A[i] = A[i-1] + 1e5 + 1;
				}
				else if(jmr[i] == 'M')
				{
					A[i] = A[i-1] + 1;
				}
				else
				{
					A[i] = A[i-1] - 1e5 - 2;
				}
			}
		}
		mergeSort(0, l-1);
		
		/*for(i=0;i<l;++i)
			printf("%lld ",A[i]);
		printf("\n");*/
			
		val = A[0];
		dupes++;	
		for(i = 1; i < l; i++)
		{
			if(A[i] == val)
			{
				dupes++;
			}
			if(A[i] != val)
			{	
				if(val == 0)
				{
					dupes++;
				}
				r += ((dupes)*(dupes-1))/2;
				dupes = 1;
			}
			val = A[i];
		}
		if(val == 0)
			dupes++;
		r += ((dupes)*(dupes-1))/2;
		printf("%lld\n", r);
	}
	return 0;
}
