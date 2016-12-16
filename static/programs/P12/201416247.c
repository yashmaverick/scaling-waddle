#include<stdio.h>
#include<stdlib.h>
inline void scanf_k(long long int *a)
  {
  register char c=0;
  while(c<33)
  {
  c=getchar_unlocked();
 *a=0;
 }
 while(c>33)
 {
 *a=*a*10+c-'0';
 c=getchar_unlocked();
 }
 }
/*long long int scanf_k(long long int *a)
{
	long long int x=0;
	register long long int c=getchar_unlocked();
	for(; c>47 && c<58 ; c = getchar_unlocked())
	{
		x = (x<<1) + (x<<3) + c - 48;
	}
	*a=x;
}*/
int main()
{
	long long int *a;
	long long int n,i,j,k,max;
	while(1)
	{	long long int count=0;
		scanf_k(&n);
		a=(long long int *)malloc(sizeof(long long int)*n);
		if(n==0)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			scanf_k(&k);
			a[i]=k;
		}
		for(i=0;i<n-1;i++)
		{
			max=a[i+1];
			for(j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
				{
					count+=n-j-1;
					break;
				}
				else if(a[j]<max)
					count++;
				else if(max<a[j])
					max=a[j];
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
