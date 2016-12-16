#include<stdio.h>
int search(int num,int b[],int n)
{
	int i=0;
	while(i!=n)
	{
		if(num==b[i])
			return i;
		i++;
	}
	return -1;
}	
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int b[n];
	int i,j,k;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	int t;
	scanf("%d",&t);
	int c[n];
	for(i=0;i<n;i++)
		c[i]=search(a[i],b,n);
	while(t--)
	{
		int n1,n2;
		scanf("%d%d",&n1,&n2);
		i=0;
		j=search(n1,b,n);
		k=search(n2,b,n);
		//printf("%d%d\n",j,k);
		while(i!=n)
		{
			if((c[i]<=j && c[i]>=k) && (j!=-1 || k!=-1))
				break; 
			if((c[i]>=j && c[i]<=k) && (j!=-1 || k!=-1))
				break;
			i++;
		}
		if(j!=-1 && k!=-1)
			printf("%d\n",b[c[i]]);
	}
	return 0;
}
