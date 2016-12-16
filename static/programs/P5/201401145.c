#include<stdio.h>
#include<stdbool.h>
int a[1001];
void read_int(int *pointer)
{
	scanf("%d",pointer);
}
void read_string( char *address)
{
	scanf("%s",address);
}
void s_yes()
{
	printf("YES\n");
}
void s_no()
{
	printf("NO\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,sum,count=0,j,k,temp;
		read_int(&n);
		read_int(&sum);
		char s[1001];
		bool state=0;
		for(i=0;i<n;i++)
		{read_string(s);read_int(&a[i]);}
		for(i=n-2;i>=0;i--)
		{
			for(j=0;j<=i;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		/*	for(i=0;i<n;i++)printf("%d ",a[i]);
			printf("\n");
			*/
		for(i=0;i<n-2;i++)
		{
			j=i+1;
			k=n-1;
			while(j<k)
			{
				if(a[i]+a[j]+a[k]==sum)
				{
					state=1;
					break;
				}
				else if(a[i]+a[j]+a[k]<sum)
					j++;
				else
					k--;
				//		printf("%d\n",sum);
			}
		}
		if(state)
			s_yes();
		else 
			s_no();
	}
	return 0;
}
