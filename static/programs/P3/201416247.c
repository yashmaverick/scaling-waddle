#include<stdio.h>
int main()
{
	int n,i,j,k,a[1000000],t,m;
	scanf("%d",&m);
	for(t=0;t<m;t++)
	{int min=1000000000,max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
              for(j=0;j<n;j++)
	      {
		      if(min>a[j])
			      min=a[j];
			      if(max<a[j]-min)
			      {
				      max=a[j]-min;
			      }
		      
	      }
	      
	      printf("%d\n",max);
	}
	return 0;
}
