#include<stdio.h>
int newa[1000000];
void merge(int a[], int s, int e)
{
	int t;
//	printf("\n");
	//      printf("s==%d e==%d\n", s,e);
	int i,j,k,l,p;
	i=s;
	j=(s+e)/2+1;
	k=s;
	// printf("%d %d %d %d", i,j,(s+e)/2,e);
	while(i<=(s+e)/2 && j<=e)
	{   
		if(a[i]<a[j])
		{
			newa[k]=a[i];
			//    a[k]=newa[k];
			k++;i++;
			//      printf("%d", newa[k]);
		}
		else
		{
			newa[k]=a[j];
			//   a[k]=newa[k];
			k++;j++;
			//     printf("%d", newa[k]);
		}
	}
	if(i>(s+e)/2)
	{
		for(p=j;p<=e;p++)
		{
			newa[k]=a[p];
			//    a[k]=newa[k];
			k++;
			//   printf("%d", newa[k]);
		}
	}
	else
	{
		for(p=i;p<=(s+e)/2;p++)
		{
			newa[k]=a[p];
			//   a[k]=newa[k];
			k++;
			// printf("%d", newa[k]);
		}
	}
	for(t=s;t<=e;t++)
	{
		a[t]=newa[t];
	}
}

int mergesort(int a[], int s, int e)
{
	//      printf("s=%d e=%d\n",s,e );
	if(s==e)
	{
		return;
	}
	else
	{
		mergesort(a,s,(s+e)/2);
		mergesort(a,(s+e)/2+1,e);
		merge(a,s,e);
	}
}

int main()
{
	int a[1000000],i,j,e,s,p,n,k,flag=0,l,t,r,test;
	char str[1000000];
	scanf("%d", &test);
	for(t=0;t<test;t++)
	{
		flag=0;
		scanf("%d %d", &n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s", str);
			scanf("%d", &a[i]);
		}
		s=0;
		e=n-1;
		mergesort(a,s,e);
		for(i=0;i<n-2;i++)
		{
		//	printf("-1");
			l=i+1;
			r=n-1;
			while(l<r)
			{
				if(newa[i]+newa[l]+newa[r]<k)
				{
					l++;
				}
				else if(newa[i]+newa[l]+newa[r]>k)
				{
					r--;
				}
				else
				{
					flag=1;
					printf("YES\n");
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		if(i==n-2)
		printf("NO\n");
	}
	return 0;

}

