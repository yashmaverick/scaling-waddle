#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,k,n,po[100000], io[100000],t,sa[100000], n1, n2,j, flag=0,a,b,ans;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &po[i]);
	for(i=0; i<n; i++)
		scanf("%d", &io[i]);
	scanf("%d", &t);

	while(t--)
	{
		j=0,flag=0;
		scanf("%d %d", &n1, &n2);
		for(i=0; i<n; i++)
		{
			if(io[i]==n1)
				a=i;
			if(io[i]==n2)
				b=i;

		}
		if(a>b)
		{
			for(i=0;i<n;i++)
			{
				for(j=b;j<=a;j++)
				{
					if(io[j]==po[i])
					{
						flag=1;

						ans=io[j];
						break;
					}
				}
				if(flag==1)
					break;
			}

		}
		else
			for(i=0;i<n;i++)
			{
				for(j=a;j<=b;j++)
				{
					if(io[j]==po[i])
					{
						flag=1;

						ans=io[j];
						break;
					}
				}
				if(flag==1)
					break;
			}
		printf("%d\n",ans);
	}
	return 0;
}



/*for(i=0; i<n; i++)
  {
  if(flag==1)
  break;
  for(k=0; k<j; k++)
  {
  if(flag==1)
  break;

  if(po[i]==sa[k])
  {
  printf("%d\n", sa[k]);
  flag=1;
  break;
  }
  }

  }*/





