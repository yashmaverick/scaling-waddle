#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
int t,n,a[100000],p1,p2,i,max,temp,j,mi,ma;
scanf("%d",&t);

while(t--)
	{
	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	p1=0;p2=1;max=a[1]-a[0],temp=0;
	for(i=0;i<n;i++)
		{

		//if(a[i]>a[p2])
			p2=i;
		
		if(a[i]<a[p1])
			p1=i;

		temp=a[p2]-a[p1];

		if(temp>max)
			max=temp;
		}
		 
	if(max<0) max=0;
	printf("%d\n",max);
	}

return 0;
}
