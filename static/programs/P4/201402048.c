#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sort(int b[],int i,int j);
void mergeSort (int b[],int i,int j,int k);
int main()
{	int t;
	scanf("%d",&t);
	while(t--)
	{
	char a[100000];
	int x=0,i,j,k,n,count=0;
	scanf("%s",a);
	n=strlen(a);
	int b[100000];
	for(i=1;i<=n;i++)
	{
		if(a[i-1]=='J')
			b[i]=10;
		else if(a[i-1]=='M')
			b[i]=100000;
		else
			b[i]=-100010;
	}
	b[0]=0;
	for(j=0;j<n;j++)
		b[j+1]=b[j+1]+b[j];	
	sort(b,0,n);
for(k=0;k<n;k++)
	{
		if(b[k]==b[k+1])
		{	count++;

		}
		else
		{
			x=x+((count+1)*(count))/2;
			count=0;
		}

	}
	if(count>0)
		x=x+(count+1)*(count)/2;
	printf("%d\n",x);
	}
	return 0;
}


void sort(int b[],int first,int last)
{

    int mid;

    if(first<last)
    {
         mid=(first+last)/2;
         sort(b,first,mid);
         sort(b,mid+1,last);
         mergeSort(b,first,mid,last);
    }
}

void mergeSort(int b[],int low,int mid,int high)
{

    int i,m,k,l,c[100000];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high))
{

         if(b[l]<=b[m]){
             c[i]=b[l];
             l++;
         }
         else{
             c[i]=b[m];
             m++;
         }
         i++;
    }

    if(l>mid)
{
         for(k=m;k<=high;k++)
	{
             c[i]=b[k];
             i++;
         }
}
    else{
         for(k=l;k<=mid;k++){
             c[i]=b[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++)
    {
         b[k]=c[k];
    }
}
