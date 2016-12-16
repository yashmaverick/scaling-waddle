#include<stdio.h>
int upper=-1;
int arr[100001];
long long int largestarea(int hist[],int length);
long long int largestarea(int hist[], int length)
{
	long long int largearea[length]; 
	int n, i, bar;

for (i=0; i<length; i++)
	{
		while (upper!=-1)
		{
			if(hist[i] <= hist[arr[upper]])

				upper--;

			else
				break;
		}
		if(upper==-1)
			bar = -1;
		else
			bar= arr[upper];

		largearea[i] = i -bar- 1;
		upper++;
                arr[upper]=i;
	}
	

	while (upper!=-1)
		upper--;

	for (i=length-1; i>=0; i--)
	{
		while (upper!=-1)
		{
			if(hist[i] <= hist[arr[upper]])
			{
				upper--;
			}
			else
				break;
		}
		if(upper==-1)
			bar= length;
		else
			bar= arr[upper];

		largearea[i]+= bar - i -1;
		upper++;
                     arr[upper]=i;
	}

	long long int maximum = 0;

	for (i=0; i<length; i++)
	{
		largearea[i] =  hist[i]*(largearea[i] + 1);
		if (largearea[i] > maximum)
			maximum = largearea[i];
	}
	//for(i=0;i<len;i++)
	//printf("%d\n",area[i]);
	while(upper!=-1)
		upper--;
	return maximum;
}
int main()
{
	int n=-5;
	while(n!=0)
	{
		scanf("%d",&n);
		int b[n];
		int i;

		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		long long int c; 
		c=largestarea(b,n);
		if(n!=0)
			printf("%lld\n",c);
	}
	return 0;
}



