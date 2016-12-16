#include <stdio.h>
#include <string.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	int L[n1], R[n2];

	for(i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2; 
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	int t,T,n,jv,mv,rv,a[100000],ans,count,zc,i;
	char s[100000];

	scanf("%d",&T);

	jv=10001;
	mv=1;
	rv=-10002;

	while(T--)
	{
		scanf("%s",s);

		ans=0;
		n=strlen(s);

/*		if(s[0]=='J')
			a[0]=jv;
		if(s[0]=='M')
			a[0]=mv;
		if(s[0]=='R')
			a[0]=rv; */

		a[0]=0;

		for(i=0;i<n;i++)
		{
			if(s[i]=='J')
				a[i+1]=a[i]+jv;
			if(s[i]=='M')
				a[i+1]=a[i]+mv;
			if(s[i]=='R')
				a[i+1]=a[i]+rv;
		}

		mergeSort(a,0,n);

		count=1;
	//	zc=0;

		for(i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])
				count++;
			else if(a[i]!=a[i-1])
			{
				ans=ans+(count*(count-1))/2;
				count=1;
			}
			//if(a[i]==0)
			//	zc++;

		}

		if(count>1)
			ans=ans+(count*(count-1))/2;

		printf("%d\n",ans);
	}

	return 0;
}
