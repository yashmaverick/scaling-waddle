#include<stdio.h>
int main()
{
	int i,t,n,A[1000000],temp,temp2;
	scanf("%d",&t);
	while(t)
	{
	scanf("%d",&n);
	scanf("%d",&A[0]);
	temp=A[0];
	A[0]=0;
	for(i=1;i<n;i++)
	{
		scanf("%d",&A[i]);
		temp2=A[i];
		A[i]=A[i]-temp;
		temp=temp2;
	}
	int m=0,max=0;
	for(i=0;i<n;i++)
	{
		m=m+A[i];
		if(m<0)
			m=0;
		if(max<m)
			max=m;
	}
	printf("%d\n",max);
	t--;
	}
	return 0;
}
