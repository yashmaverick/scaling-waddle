#include<stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,a[100007],j,k,l,a1[100007],a2[100007],m;
		scanf("%d",&n);
                for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		int min=a[0],max=a[n-1],omg=0,max2;
		for(k=0;k<n;k++)
		{
			if(a[k]<min)
				min=a[k];
			a1[k]=min;
		}
		for(l=n-1;l>=0;l--)
		{
			if(a[l]>max)
				max=a[l];
			a2[l]=max;
		}
		for(m=n-1;m>=0;m--)
		{
			max2=(a2[m]-a1[m]);
			if(omg<max2)
				omg=max2;
		}
		printf("%d\n",omg);
	}
	return 0;
}


