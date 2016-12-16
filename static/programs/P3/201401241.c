#include<stdio.h>
int main()
{
	int t,n,k,i,j,maximum,a[100000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int min=a[0],max=a[1];
		maximum=a[1]-a[0];
		for(j=0;j<n;j++)
		{
			if(a[j]<min)
                  min=a[j];
            max=a[j]-min;
            
            if(max>maximum)
                           maximum=max;
		}
		if(maximum>0)
			printf("%d\n",maximum);
		else
			printf("0\n");
	}
	return 0;
}
