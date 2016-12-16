#include<stdio.h>

int main()
{
	int t,n,k;
	int flag;
	int z;
	int a[100005];
	char str[1001];
	scanf("%d",&t);
	int x,i,j;
	for(x=0;x<t;x++)
	{
			flag=1;
		scanf("%d%d",&n,&k);
		int l;
		for(l=0;l<n;l++)
		{
			scanf("%s",str);
			scanf("%d",&a[l]);
		}

		for(i=0;i<n-1;i++)
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					int temp;
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		/*                for(i=0;i<n;i++)
				  {
				  printf(" %d",a[i]);
				  }*/

		for(i=0;i<n-2;i++)
		{
			j=i+1;
			z=n-1;
			while(z>j)
			{
				if((a[i]+a[j]+a[z])==k)
				{
					printf("YES\n");
					flag=0;
					break;
				}

				else if((a[i]+a[j]+a[z])>k)
					z--;
				else
					if((a[i]+a[j]+a[z])<k)
						j++;
			}


			if(flag==0)
				break;
		}
		//		  else
		if(flag==1)
			printf("NO\n");

	}	

	return 0;
}
/*int l;
  for(i=0;i<n-1;i++)
  { j=i+1;
  l=n-1;
  while(j<l)
  { if(a[i]+a[j]+a[l]==k)
  { printf("YES\n");
  flag=1;
  break;
  }
  if(a[i]+a[j]+a[l]>k)
  k--;
  if(a[i]+a[l]+a[j]<k)
  j++;
  }
  if(flag==1)
  break;
  }
  if(flag==0)
  printf("NO\n");
  }
  return 0;
  }
 */



