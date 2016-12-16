#include<stdio.h>
int main()
{
	int b=0,t,i,n,j,k,a[10000],temp,x;
	char s[1000];
	scanf("%d",&t);
	while(b<t)
	{
		x=0;
		i=0;
		scanf("%d %d",&n,&k);
                while(i<n)
		{
			scanf("%s",&s);
		scanf("%d",&a[i]);
		i++;
		}
                for(i=0;i<n-1;i++)
		{
			for(j=0;j<(n-i-1);j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		//for(i=0;i<n;i++)
		//	printf("%d",a[i]);
		for(i=0;i<n-2;i++)
		{
			j=i+1;
			temp=n-1;
			while(j<temp)
			{
				if((a[i]+a[j]+a[temp])<k)
					j++;
				else if((a[i]+a[j]+a[temp])==k)
				{
					//printf("%d %d %d\n",i,j,k);
					printf("YES\n");
					x++;
					break;
				}
				else
					temp--;
			}
			if(x>0)
				break;
		}
		if(x==0)
			printf("NO\n");

		b++;
	}
	return 0;
}

