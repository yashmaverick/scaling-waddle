#include<stdio.h>
long long int b[1000005]={0},a[1000005]={0};
//int cmpfunc (const void * a, const void * b)
//{
//	return ( *(int*)a - *(int*)b );
//}
/*void mergesort(long long int low,long long int mid,long long int high)
  {       long long int l,i,m,k;
  l=low;i=low;m=mid+1;
//        b=(long long int*)malloc(sizeof(long long int)*high);
while((l<=mid) && (m<=high))
{       if(a[l]<=a[m])
{      b[i]=a[l]; 
l++;
}
else
{       b[i]=a[m];
m++;
}
i++;
}
if(l>mid)//when some already sorted elements left
{       for(k=m;k<=high;k++)
{       b[i]=a[k];
i++;
}
}
else
{       for(k=l;k<=mid;k++)
b[i]=a[k];
i++;
}
for(k=low;k<=high;k++)//completely sorted array
a[k]=b[k];
}

void partition(long long int low,long long int high)
{   long long int mid;
if(low<high)
{ mid=(high+low)/2;
partition(low,mid);
partition(mid+1,high);
mergesort(low,mid,high);
}       
}*/

void partition(long long int low,long long int high)
{    long long int mid;
	if(low<high){
		mid=(low+high)/2;
		partition(low,mid);
		partition(mid+1,high);
		mergesort(low,mid,high);
	}
}

void mergesort(long long int low,long long int mid,long long int high)
{    long long int i,m,k,l;

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high)){

		if(a[l]<=a[m]){
			b[i]=a[l];
			l++;
		}
		else{
			b[i]=a[m];
			m++;
		}
		i++;
	}

	if(l>mid){
		for(k=m;k<=high;k++){
			b[i]=a[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			b[i]=a[k];
			i++;
		}
	}

	for(k=low;k<=high;k++){
		a[k]=b[k];
	}
}

int main()
{       long long int t,i=0,n,c,z,m,s;
	scanf("%lld",&t);
	while(t--)
	{      c=0;z=1;m=0; 
		scanf("%lld",&n);
		while(n--)
		{	scanf("%lld",&a[c++]);
			//		printf(".%lld .",a[c++]);
		}
		partition(0,c-1);
		//               qsort(a,c,sizeof(long long int), cmpfunc);
		/*		for(s=0;s<c;s++)
				printf(".%lld .",a[s]);
		 */		for(i=0;i<c;i++)
		{    if(a[i]==a[i+1] && i<c-1)
			z++;
			else
			{       m=m+(z*(z-1))/2;       
				z=1;
			}
			//printf("%lld %lld ",a[i],a[i+1]);

		}
		printf("%lld\n",m);        
	}
	return 0;
}
