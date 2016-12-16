#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m,k;
		scanf("%d%d",&m,&k);
		char b[10000];
		int a[100000],flag=0,state=0,j,i,l;
		for(i=0;i<m;i++)
			scanf("%s %d",b,&a[i]);
		//printf("%d\n",a[0]);
		qsort(a,m,sizeof(int),cmpfunc);
		//printf("%d\n",a[0]);
		for(i=0;i<(m-2);i++)
		{
			l=m-1;
			j=i+1;
			while(j<l)
			{
				if((a[i]+a[j]+a[l])<k)
					j++;
				else if((a[i]+a[j]+a[l])>k)
					l--;
				else if((a[i]+a[j]+a[l])==k)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				state=1;
				break;
			}
		}
		if(state==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
