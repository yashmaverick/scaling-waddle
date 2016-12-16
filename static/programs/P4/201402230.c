#include<stdio.h>
#include<string.h>
//#define J -100002
//#define M 1
//#define R 100001
void merge_sort(long long int a[],long long int fi,long long int la);
void merge(long long int a[],long long int l,long long int r);
long long int a[100001],temp[100001];
int main()
{ 
	int t;
	scanf("%d",&t);
	while(t--)
	{ 
		char c[100001];
		long long int cnt=0,cnt0=0,i=0,j,l,ans=0;
		//getchar();
		//while(c=getchar()!='\n')
		scanf("%s",c);
		l=strlen(c);
		if(c[0]=='J')
			a[0]=-1012;

		if(c[0]=='M')
			a[0]=1;
		if(c[0]=='R')
			a[0]=1011;
		for(i=1;i<l;i++)
		{       
			if(c[i]=='J')
			{  a[i]=a[i-1]-1012;

			}
			if(c[i]=='M')
			{
			       	a[i]=a[i-1]+1;

			}
			if(c[i]=='R')
			{ 
				a[i]=a[i-1]+1011;

			}
		}
		merge_sort(a,0,l-1);
		/*for(i=0;i<l;i++)
			printf("%lld ",a[i]);
			printf("\n");*/
		if(a[l-1]==0)
			cnt0=1;
		for(i=0;i<l-1;i++)
		{ 
			if(a[i]!=0)
			{
				if(a[i]==a[i+1] && a[i]==a[i+2]&& i!=l-2)
				{
					cnt++;
					//printf("First case\n");
				}
				if(a[i]==a[i+1] && a[i+1]!=a[i+2]&& i!=l-2)
				{
					cnt=cnt+2; 
					//printf("Second case\n");
				}
				if(i==l-2 && a[i]==a[i+1])
				{       cnt=cnt+2; 
					//printf("End condition\n");  
					ans=ans+(cnt*(cnt-1))/2;
				}

				if(a[i]!=a[i+1])
				{  if(cnt>=2)
					{
						ans+=(cnt*(cnt-1))/2;
					//	printf("Current ans is %lld\n", ans );
					}
					cnt=0;
				}
			}
			else
			{
				cnt0++;
			}
		}
		if(cnt0>=2)
		ans=ans+cnt0+(cnt0*(cnt0-1))/2;
		else
		ans=ans+cnt0;
			printf("%lld\n",ans);
	}
	return 0;
}
void merge_sort(long long int a[],long long int fi,long long int la)
{ long long int i;
	//for(i=fi;i<=la;i++)
	//	printf("%lld ",a[i]);printf("\n");
	if(fi>=la)
		return;
	if (fi<la)
	{ long long int mid=(fi+la)/2;
		merge_sort(a,fi,mid);
		merge_sort(a,mid+1,la);
		merge(a,fi,la);
	}
}
void merge(long long int a[],long long int l,long long int r)
{      
	long long int i,mid=(l+r)/2;
	long long int j=mid+1,k=0;
	i=l;
	while(i<=mid && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		if(a[i]>a[j])
		{
			temp[k]=a[j];
			//                      printf("%d ",a[j]);
			k++;
			j++;
		}
	}
	while(i<=mid)
	{ temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=r)
	{ temp[k]=a[j];
		k++;
		j++;
	}
	//      k=l; 
	k=0;
	for(i=l;i<=r;i++)
	{ a[i]=temp[k];
		//              printf("%d ",a[i]); 
		k++;
	}
	//for(i=l;i<=r;i++)
	//	printf("%lld ",a[i]);printf("\n");
}
