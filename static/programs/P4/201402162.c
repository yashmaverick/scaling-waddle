#include<stdio.h>
#include<string.h>
typedef struct lashit{
	long long int real;
	long long int img;
}lashit;
void merge(lashit arr[],long long int min,long long int mid,long long int max)
{
	lashit tmp[max];
	long long int i,j,k,m; 
	j=min;
	m=mid+1;
	for(i=min; j<=mid && m<=max ; i++)
	{
		if(arr[j].real<arr[m].real)
		{
			tmp[i]=arr[j];
			j++;
		}
		else if(arr[j].real==arr[m].real)
		{
			if(arr[j].img<=arr[m].img)
		{
			tmp[i]=arr[j];
			j++;
		}
		else
		{
			tmp[i]=arr[m];
			m++;
		}
		}
		else
		{
			tmp[i]=arr[m];
			m++;
		}
	}
	if(j>mid)
	{
		for(k=m; k<=max; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=j; k<=mid; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	for(k=min; k<=max; k++)
		arr[k]=tmp[k];
}
void part(lashit arr[],long long int min,long long int max)
{
	int mid;
	if(min<max)
	{
		mid=(min+max)/2;
		part(arr,min,mid);
		part(arr,mid+1,max);
		merge(arr,min,mid,max);
	}
}
char s[10000000];
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int i=0,count=0,cnt=0,ans=0,j=0,m=0,n=0;
		lashit life;
		life.real=0;
		life.img=0;
		scanf("%s",s);
		count=strlen(s);
		lashit l[count];
		for(i=0;i<count;i++)
		{
			if(s[i]=='J')
			{
				life.real+=-2;
			}
			if(s[i]=='M')
			{
				life.real+=1;
				life.img+=-1;
			}
			if(s[i]=='R')
			{
				life.real+=1;
				life.img+=1;
			}
			m=life.real;
			n=life.img;
			l[i].real=m;
			l[i].img=n;
		}
		part(l,0,count-1);
		long long int county=1;
		for(i=1;i<count;i++)
		{
			if(l[i].real==l[i-1].real && l[i].img==l[i-1].img )
				county++;
			else
			{
				ans+=(county*(county-1))/2;
				if(l[i-1].real==0 && l[i-1].img ==0)
				{
					ans+=county;
				}
				county=1;
			}
		}
		ans+=(county*(county-1))/2;
	 	if(l[i-1].real==0 && l[i-1].img ==0)	
			ans+=county;
		printf("%lld\n",ans);
	}
	return 0;
}
