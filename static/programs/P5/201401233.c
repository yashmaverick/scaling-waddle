#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d",&m);
	for(n=0;n<m;n++)
	{
		int flag=0,sum,temp,i,j,a[1001],s,first,last;
		char r[1001];

		scanf("%d%d",&s,&sum);

		for(i=0;i<s;i++)
			scanf("%s%d",r,&a[i]);
		for(i=0;i<s;i++)
		{
			for(j=i+1;j<s;j++)
			{
				if(a[j]<a[i])
				{
					temp=a[j];
					a[j]=a[i];
					a[i]=temp;
				}
			}
		}
		for(i=0;i<s-2;i++)
		{
			first=i+1;
			last=s-1;
			while(first<last)
			{
				if((a[first]+a[last]+a[i])>sum)
					last--;
				else if((a[first]+a[last]+a[i])<sum)
					first++;
				else
				{
					flag=1;
					break;
				}

			}
			if(flag==1)
			{	
				break;
			}

		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}



