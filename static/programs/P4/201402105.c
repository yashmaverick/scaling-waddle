#include<stdio.h>
#include<string.h>
void quicksort(int [],int,int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char c[100001];
		scanf("%s",c);
		int n,i,j,a[100001],l=0,k=1,sum=0;
		n=strlen(c);
		for(i=0;i<n;i++)
		{		
			if(c[i]=='J')
				a[i]=594;
			else if(c[i]=='M')
				a[i]=7;
			else if(c[i]=='R')
				a[i]=-601;
		}
		for(i=1;i<n;i++)
		{
			a[i]=a[i]+a[i-1];	
		}
		quicksort(a,0,n-1);
		int flag;	
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			{
				k++;

			}
			else if(a[i]!=a[i-1])
			{
				flag=1;
				sum=sum+k*(k-1)/2;
				k=1;
			}
		}
		sum=sum+k*(k-1)/2;
			k=0;
			for(i=0;i<n;i++)
			{
				if(a[i]==0)
					k++;	
			}
			printf("%d\n",sum+k);



	}	
		return 0;
	}
void quicksort(int x[],int first,int last)
{
        int pivot,j,temp,i;
        if(first>=last)
                return;

        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
                while(x[i]<=x[pivot]&&i<last)
                        i++;
                while(x[j]>x[pivot])
                        j--;
                if(i<j)
                {
                        temp=x[i];
                        x[i]=x[j];
                        x[j]=temp;
                }
        }
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);

}

