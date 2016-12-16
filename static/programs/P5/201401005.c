#include<stdio.h>

void merge(int a[], int f, int m, int l)
{
	int i, j, k;    
	int n1 = m-f+1;    
	int n2 = l-m;
	int L[n1], R[n2];

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

void msort(int a[], int f, int l)
{
	if(f<l)    
	{   
		int m = ((f+l)/2);
		msort(a, f, m); 
		msort(a, m+1, l); 
		merge(a, f, m, l); 
	}   
}


int bsearch(int a[], int f, int l, int x)
{
	if(l >= f)
	{
		int m = f + (l-f)/2;
		if(a[m] == x)
			return 1;
		else if(x < a[m])
			return bsearch(a, f, m-1, x);
		else if(x > a[m])
			return bsearch(a, m+1, l, x);
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, i, j, fl=0;
		int b[100001], v, sum;
		char a[100001];
		scanf("%d%d", &n, &v);
		for(i=0; i<n; i++)
			scanf("%s%d", a, &b[i]);

		if(n == 3)
		{
			if(b[0]+b[1]+b[2] == v)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			msort(b, 0, n-1);
			i = 0;
			while(i < n)
			{
				sum = b[i];
				j = i+1;
				while(j < n)
				{
					sum += b[j];
					if(bsearch(b, j+1, n-1, v-sum) == 1)
					{
						printf("YES\n");
						fl = 1;
						break;
					}
					else
					{
						sum -= b[j];
						j++;
						if(i == n-2)
						{
							printf("NO\n");
							fl = 1;
							break;
						}
					}
				}
				if(fl == 1)
					break;
				i++;
			}
		}
	}
	return 0;
}
