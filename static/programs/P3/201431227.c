#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{	
		 int a[100000];
		int size,i,j;
		scanf("%d",&size);
		for(i=0;i<size;i++)
		{
			scanf("%d",&a[i]);
		}
		 int flag=0,v=0,r=0;
		for(i=0;i<size-1;i++)
		{		
			v+=a[i+1]-a[i];
			if(v<0)
				v=0;
			if(v>r)
				r=v;
		}
		printf("%d\n",r);
	}
	return 0;
}

