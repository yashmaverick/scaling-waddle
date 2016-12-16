#include<stdio.h>
#include<string.h>
void mergesort(long long int* a,long long int* b,long long int low,long long int high)
{
	if(low>=high)
		return ;
//	printf("%d %d\n",low,high);
	mergesort(a,b,low,(low+high)/2);
	mergesort(a,b,((low+high)/2)+1,high);
	long long int i,j,k,l,n,m;
	n=low;
	i=low;
	j=((low+high)/2)+1;
	while(i<=(low+high)/2 || j<=high)
	{
		if(a[i]<=a[j] && i<=(low+high)/2)
		{
			b[n]=a[i];
			i++;
			n++;
		}	
		else
		{
			if(a[i]>=a[j] && j<=high){
				b[n]=a[j];
				j++;
				n++;
			}
			else{
				if(i>(low+high)/2){
					while(j<=high){
						b[n]=a[j];
						j++;
						n++;
					}
				}
				else{
					while(i<=(low+high)/2){
						b[n]=a[i];
						i++;
						n++;
					}
				}
			}
		}
	}
	for(i=low;i<=high;i++)
		a[i]=b[i];
	return ;
}
int main()
{
	long long int q,sum,size,t,cnt,b[100001],a[100001],i;
	char str[100001];
	scanf("%lld\n",&t);
	while(t--)
	{
		i=0;
		size=0;
		sum=0;
		scanf("%s",str);
		size=strlen(str);
		for(i=0;i<size;i++)
		{
			if(str[i]=='J')
				a[i]=sum-100001;
			else if(str[i]=='M')
				a[i]=sum+1;
			else 
				a[i]=sum+100000;
			sum=a[i];
		}
		//printf("\n");
		mergesort(a,b,0,size-1);
//		for(i=0;i<size;i++)
//			printf("%lld ",a[i]);
//		printf("\n");	
		long long int sum=1,ele=a[0];
		long long int ans=0;		
		for(i=0;i<size;i++)
		{
			if(a[i]==a[i+1])
				sum++;
			else{
				ans=ans+(sum*(sum-1))/2;	
				sum=1;
			}
			if(a[i]==0)
				ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
