#include<stdio.h>
#include<math.h>
int main()
{
	int test,i;
	int n,l,max,k;
	scanf("%d",&n);
	  int a[n];
	l=0;
	i=0;
	l=log2(n);	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		/*k=a[i];
		for(l=0;k>1;l++)
		{
			k=k/2;
		}*/
		l=log2(a[i]);
		max=(1<<l)+(1<<l-1);
		if(a[i]<max)
			printf("%d\n",2*l-1);
		else
			printf("%d\n",2*l);
	}
	return 0;
}

