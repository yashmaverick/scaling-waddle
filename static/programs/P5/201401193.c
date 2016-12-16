#include<stdio.h>
void qsort(int left,int right,int a[])
{
	int pivot=right,wall=left-1,i,temp;
	for(i=left;i<=pivot;i++)
	{
		if(a[i]<=a[pivot])
		{
			temp=a[i];
			a[i]=a[wall+1];
			a[wall+1]=temp;
			wall++;
		}
	}
	if(wall-1>=left)
		qsort(left,wall-1,a);
	if(wall+1<=right)
		qsort(wall+1,right,a);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,sum;
		scanf("%d %d",&n,&sum);
		int i,a[n];
		char s[1000000];
		for(i=0;i<n;i++)
		{
			scanf(" %s",s);
			scanf("%d",&a[i]);
		}
		qsort(0,n-1,a);
		int b,state=0,d;
		for(i=0;i<n-2;i++)
		{
			b=i+1;
			d=n-1;
			while(b<d && state==0)
			{
				if(a[i]+a[b]+a[d]==sum)
				{
					printf("YES\n");
					state=1;
				}
				else if(a[i]+a[b]+a[d]<sum)
					b++;
				else
					d--;
			}
			if(state==1)
				break;
		}
		if(state==0)
			printf("NO\n");
	}
	return 0;
}
