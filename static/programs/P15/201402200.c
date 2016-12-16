#include<stdio.h>
int main()
{
int arr[10001];
int minindex,i,j,test_cases,N,K;
scanf("%d",&test_cases);
while(test_cases--)
{
int min=1000000001;
scanf("%d%d",&N,&K);
for(i=0 ; i<N ; i++)
{
    scanf("%d",&arr[i]);
}
for(i=0 ; i<K ; i++)
{
    if(arr[i]<min)
    {
	min=arr[i];
	minindex=i;
    }
}
if(N!=1&&i!=N )
{
printf("%d ",min);
}
else
{

printf("%d\n",min);
}

for(i=K ; i< N ; i++)
{
    if(minindex<=i && minindex>= i-K+1)
    {
	if(min < arr[i])
	{
	    if(i!=(N-1))
            printf("%d ",min);
	    else
            printf("%d\n",min);
	}
	else
	{
	min=arr[i];
	minindex=i;
        if(i!=N-1)
	printf("%d ",min);
	else
            printf("%d\n",min);
	}
    }
else
{
 min=100000001;

//	printf("hii");
for(j=i-K+1 ; j<=i ; j++)
{
    if(arr[j] < min)
    {
//	printf("hii");
    min=arr[j];
    minindex=j;
    }

}
if(i!=N-1)
    printf("%d ",min);
    else
            printf("%d\n",min);
}


}

}
return 0;

}

