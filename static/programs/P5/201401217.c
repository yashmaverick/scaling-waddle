#include<stdio.h>
int main()
{
	int t,x;
	scanf("%d",&t);
	for(x=0;x<t;x++)
	{
		int y,n,c;
		scanf("%d%d",&n,&c);
		int a[n];
		char s[100];
		for(y=0;y<n;y++)
		{
			scanf("%s",s);
		/*	d=getchar();
		//	while(d!=' ')
			{
				//printf("fse45se\n");
				d=getchar();
			}*/
			scanf("%d",&a[y]);
		//	printf("srikanth %d\n",a[y]);
		}
		int l,m;
		for(l=0;l<n;l++)
		{
			int te;
			for(m=l+1;m<n;m++)
				if(a[m]<a[l])
				{
					te=a[l];
					a[l]=a[m];
					a[m]=te;
				}
		//	printf("sortarr %d\n",a[l]);
		}
		int i,j,k,flag;
		for(i=0;i<n-2;i++)
		{
			flag=0;
			j=i+1,k=n-1;
			while(j<k)
			{
				if((a[i]+a[j]+a[k])==c)
				{
					flag=1;
					break;
				}
				if((a[i]+a[j]+a[k])>c)
					k--;
				else
					j++;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
return 0;
}
