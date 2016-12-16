#include <stdio.h>

int main()
{
	int A[1000011];
	int X[1000011];
	int t, minv, maxv, n, i;
	long long res;
	scanf("%d", &t);
	while(t!=0)
	{
		res = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &A[i]);
			if(i==0)
			{
			   	minv = A[i];
				maxv = A[i];
			}
			else
			{
				if(A[i]<minv) minv = A[i];
				if(A[i]>maxv) maxv = A[i];
			}
		}

		for(i=0; i<=(maxv-minv); i++)
			X[i] = 0;

		for(i=0; i<n; i++)
			X[A[i]-minv] += 1;

		for(i=0; i<=(maxv-minv); i++)
			res += (long long)X[i]*((long long)(X[i]-1))/2;

		printf("%lld\n", res);
		t--;
	}
	return 0;
}
