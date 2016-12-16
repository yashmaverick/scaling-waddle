#include<stdio.h>
long long int b[1000000];
long long int c[1000000];

void merge(long long int a[], long long int f, long long int m, long long int l)
{
	long long int i, j, k;    
	long long int n1 = m-f+1;    
	long long int n2 = l-m;
	long long int L[n1], R[n2];

	for(i=0; i<n1; i++)    
		L[i] = a[f+i];
	for(i=0; i<n2; i++)
		R[i] = a[m+1+i];

	i = 0;
	j = 0;
	k = f;
	while(i<n1 && j<n2)    
	{   
		if(L[i]<=R[j])
		{   
			a[k] = L[i];
			i++;
		}   
		else
		{   
			a[k] = R[j];
			j++;
		}   
		k++;
	}   

	while(i<n1)    
	{   
		a[k] = L[i];
		i++;
		k++;
	}   
	while(j<n2)
	{   
		a[k] = R[j];
		j++;
		k++;
	}   
}

void msort(long long int a[], long long int f, long long int l)
{
	if(f<l)    
	{   
		long long int m = ((f+l)/2);
		msort(a, f, m); 
		msort(a, m+1, l); 
		merge(a, f, m, l); 
	}   
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long int n, i, j;
		unsigned long long int count=0, temp=1;
		scanf("%lld", &n);
		for(i=0; i<n; i++)
			scanf("%lld", &b[i]);
		
		msort(b, 0, n-1);

		for(i=0; i<n-1; i++)
		{
			j = 0;
			if(b[i] == b[i+1])
			{
				temp++;
			}
			else if(b[i] != b[i+1])
			{
				if(temp > 1)
				{
					if(temp%2 == 0)
						count += (temp/2)*(temp-1);
					else
						count += temp*((temp-1)/2);
				}
				temp = 1;
			}
		}
/*			if(temp == n)
			{
				if(n%2 == 0)
					count += (n/2)*(n-1);
				else
					count += ((n-1)/2)*n;
				break;
			}
		}
		*/
				if(temp > 1)
				{
					if(temp%2 == 0)
						count += (temp/2)*(temp-1);
					else
						count += temp*((temp-1)/2);
				}
				temp = 1;
		printf("%llu\n", count);
	}

	return 0;
}
