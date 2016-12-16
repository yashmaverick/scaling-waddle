#include<stdio.h>
#include<string.h>
int newa[1000000];
int second[100000];
void merge(int a[], int s, int e,int sub[])
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
			second[k]=sub[i];
			//    a[k]=newa[k];
			k++;i++;
			//      printf("%d", newa[k]);
		}
		else if(a[i]==a[j])
		{
			if(sub[i]>sub[j])
			{
				newa[k]=a[j];
				second[k]=sub[j];
				k++;j++;
			}
			else
			{
				newa[k]=a[i];
				second[k]=sub[i];
				k++;i++;
			}
		}
		else
		{
			newa[k]=a[j];
			second[k]=sub[j];
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
			second[k]=sub[p];
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
			second[k]=sub[p];
			//   a[k]=newa[k];
			k++;
			// printf("%d", newa[k]);
		}
	}
	for(t=s;t<=e;t++)
	{
		a[t]=newa[t];
		sub[t]=second[t];
	}
}

int mergesort(int a[], int s, int e,int sub[])
{
	//      printf("s=%d e=%d\n",s,e );
	if(s==e)
	{
		return;
	}
	else
	{
		mergesort(a,s,(s+e)/2,sub);
		mergesort(a,(s+e)/2+1,e,sub);
		merge(a,s,e,sub);
	}
}

int main()
{
	int i,j,e,s,p,n,test,t,len,x,y,sum=0,count=1;
	char str[100000];
	scanf("%d", &test);
	for(t=0;t<test;t++)
	{
		int sub[100000],a[100000];
		sum=0;
		sub[0]=0;
		a[0]=0;
		x=0;
		y=0;
		scanf("%s", str);
		len = strlen(str);
		p=1;
		for(i=0;i<len;i++)
		{
		//	printf("-1\n");
			if(str[i]=='J')
			{
				x--;
				y--;
				a[p]=x;
				sub[p]=y;
				p++;
			}
			else if(str[i]=='R')
			{
				x++;
				a[p]=x;
				sub[p]=y;
				p++;
			}
			else
			{
				y++;
				a[p]=x;
				sub[p]=y;
				p++;
			}
		}
	/*	for(i=0;i<=len;i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		for(i=0;i<=len;i++)
		{
			printf("%d ", sub[i]);
		}*/


		s=0;
		e=len;
		mergesort(a,s,e,sub);
	//	printf("\n");
		//      printf("\n");
	/*	for(j=0;j<=len;j++)
		{
			printf("%d ", newa[j]);
		}
		printf("\n");
		for(j=0;j<=len;j++)
		{
			printf("%d ", second[j]);
		}*/
		count=1;
		for(i=0;i<len;i++)
		{
			if(newa[i]==newa[i+1] && second[i]==second[i+1])
			{
				count++;
				if(i==len-1)
				{
					sum=sum+((count*(count-1))/2);
				}
					
			}
			else
			{
				sum=sum+((count*(count-1))/2);
				count=1;
			}
		//	printf("\n%d\n", count);
		}
		printf("%d\n", sum);
	}
	return 0;
}

