#include<stdio.h>
#include<string.h>
void quicksort(int [],int ,int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[100001];
		int n,i,l=1,s=0,k=0,c[100001];
		scanf("%s",a);
		n=strlen(a);
		for(i=0;i<n;i++)
		{
			if(a[i]=='J')
				c[i]=-9989;
			else if(a[i]=='M')
				c[i]=3504;
			else if(a[i]=='R')
				c[i]=6485;
		}

		for(i=1;i<n;i++)
		{
			c[i]=c[i]+c[i-1];
		}


		quicksort(c,0,n-1);
		for(i=1;i<n;i++)
		{
			if(c[i]==c[i-1])
				l++;
			else
			{
				s=s+l*(l-1)/2;
				l=1;
			}
		}
		s=s+l*(l-1)/2;
		for(i=0;i<n;i++)
		{
			if(c[i]==0)
				k++;
		}
		printf("%d\n",s+k);
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

