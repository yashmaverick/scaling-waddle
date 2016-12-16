#include<stdio.h>
	int a[1000000];long long int b[1000000];
void quick_sort (int *a,int n) {
	int i, j, p, t;
	if (n < 2)
		return;
	p = a[n / 2];
	for (i = 0, j = n - 1;; i++, j--) {
		while (a[i] < p)
			i++;
		while (p < a[j])
			j--;
		if (i >= j)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	quick_sort(a, i);
	quick_sort(a + j + 1, n - j - 1);
}
int main()
{
	int tc,n,i,j,k,final,initial;long long int ans;
	scanf("%d",&tc);
	
	while(tc--)
	{	k=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		quick_sort(a,n);
		i=j=0;
		int l=1;
		for(i=0;i<n-1;i++)
		{

			//final=i;
			//initial=i;
			if(a[i]==a[i+1])
			{
				/*j=i;
				initial =j;
				printf("i%d",initial);
				while(a[j+1]==a[j])
				{
					j++;
				}
				final=j;
				printf("f%d",final);
				b[k++]=final-initial+1;
				i=i+final-initial;*/
				l++;
			}
			 if(a[i]!=a[i+1] || i+1==n-1) 
			{
			b[k]=l;
			l=1;
                        k++; 
			}
		}
		//	for(i=0;i<n;i++)
		//	{
		//		printf("%d",b[i]);
		//	}
		ans=0;
		for(i=0;i<k;i++)
		{
			ans=ans+(b[i]*(b[i]-1))/2;
		}
		printf("%lld\n",ans);

	}
	return 0;
}



