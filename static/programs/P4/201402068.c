#include <stdio.h>
typedef long long int ll;
int cmp(const void *p,const void *q)
{
	ll l=*(ll *)p;
	ll r=*(ll *)q;
	return l-r;
}
/*ll cantor(ll a,ll b)
{
	ll A = a >= 0 ? 2 * a : -2 * a - 1;
  
	ll B = b >= 0 ? 2 * b : -2 * b - 1;
	
	ll ans=((a+b)*(a+b+1))/2+b;
	
	return ans;
}*/
void quicksort(ll a[],int f,int l);
int main()
{   char s;
	ll a[100000];
	ll jr,jm;
	int n;
	scanf("%d",&n);getchar();
	while(n--)
	{ jr=jm=0;
		s=getchar();
		int i=1;
		while( s!='\n'&& s!=EOF)
		{  
			if(s=='J')
			{jr++;
				jm++;
			}
			else if(s=='R')
				jr--;
			else if(s=='M')
				jm--;
			a[i]=jr*1000007+jm;
			i++;
			s=getchar();
		}
		a[0]=0;
		qsort(a,i,sizeof(ll),cmp);
		ll sum=0;
		int l=i;
		int p=1,loc=a[0];
		//printf("a %lld\n",a[0]);
		for(i=1;i<l;i++)

		{ 
			//printf("a %lld\n",a[i]);
		   	if(a[i]==loc)
			p++;
			else
			{sum+=(p*(p-1))/2;
				p=1;
				loc=a[i];
			}
		}
		sum += (p*(p-1))/2;
		printf("%lld\n",sum);
	}
	return 0;
}
/*void quicksort(ll a[],int first,int last)
{
	int pivot,i,j,temp;

	if(first<last)
	{    
		pivot=first;
		i=first;
		j=last;

		while(i<j)
		{
			while(a[i]<=a[pivot]&&i<last)
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}

		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,first,j-1);
		quicksort(a,j+1,last);
	}    
}*/
