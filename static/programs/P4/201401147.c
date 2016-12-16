#include<stdio.h>
#include<string.h>
long long int a[100000];
/*int wall(int start,int pivot)
{
	int wall=start;
	int i;
	int temp;
	int value=a[pivot];
	for(i=start;i<pivot;i++)
	{
		if(a[i] < value)
		{
			temp=a[wall];
			a[wall]=a[i];
			a[i]=temp;
			wall++;
		}
	}
	temp=a[pivot];
	a[pivot]=a[wall];
	a[wall]=temp;
	return wall;
}
void quicksort(int low,int high)
{
	if(low<high)
	{
		int pivot=wall(low,high);
		quicksort(low,pivot-1);
		quicksort(pivot+1,high);
	}
	return ;
}*/
void merge(int low,int mid,int high)
{
        long long int temp[100005];
        int l=low;
        int i=low;
        int m=mid+1;
        while(l<=mid&&m<=high)
        {
                if(a[l]<=a[m])
                {temp[i]=a[l];l++;}
                else
                {temp[i]=a[m];m++;}
                i++;
        }int k;
        if(l>mid)
        {
                for(k=m;k<=high;k++)
                {temp[i]=a[k];i++;}
        }
        else
        {
                for(k=l;k<=mid;k++)
                {temp[i]=a[k];i++;}
        }
        for(k=low;k<=high;k++)
                a[k]=temp[k];
        return ;
}
void sort(int low,int high)
{
        if(low<high)
        {       int mid=(low+high)/2;
                sort(low,mid);
                sort(mid+1,high);
                merge(low,mid,high);
        }
        return ;
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		char str[100005];
		scanf("%s",str);
		int i;
		int c=strlen(str);
	//	for(i=0;i<c;i++)
	//		a[i]=0;
		int count=0;
		if(str[0]=='J')
		{
			a[0]=100000+1;
		}
		else if(str[0]=='M')
		{
			a[0]=100000-1;
		}
		else if(str[0]=='R')
		{
			a[0]=-200000;
		}

		for(i=1;i<c;i++)
		{

			if(str[i]=='J')
			{
				a[i]=a[i-1]+100000+1;
			}
			else if(str[i]=='M')
			{
				a[i]=a[i-1]+100000-1;
			}
			else if(str[i]=='R')
			{
				a[i]=a[i-1]-200000;
			}

			//			printf("%d\n",a[i]);
			if(a[i]==0)
			{
				count++;
			}			
		}
		//		printf("Present count is %d\n",count);
		sort(0,c-1);
		/*		for(i=0;i<c;i++)
				{
				printf("%d\t",a[i]);
				}
				printf("\n");*/
		int temp=a[0];
		int temp2=1;
		//	printf("Intermediate count is %d\n",count);
		//		printf(" value of c is %d\n",c);
		for(i=1;i<c;i++)
		{
			if(a[i]==temp)
				temp2++;
			if(a[i]!=temp || i==c-1)
			{
				//		printf("hello\n");
				temp=a[i];
				//	printf("temp2 is %d\n",temp2);
				count=count + (temp2*(temp2-1))/2;
				temp2=1;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
