#include<stdio.h>
#include<stdlib.h>
# define modulus 1000000007
/*struct list
{
	int data;
//	int dist;
	struct list *nxt;
};
typedef struct list element;
typedef element *link; */
long long int spmax=1,endmax=1,endmin=2;
void swap(long long int *a,long long int *b)
{
	long long int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}
void heapifymax(long long int a,long long int max[])
{
	long long int j,k;
	max[endmax]=a;
	endmax++;
	j=endmax-1;
    k=j/2; // hp mei vrtx
    while(k>0&&(max[k])>(max[j]))
    {
       	swap(&max[j],&max[k]);
        j=k;
        k=j/2;
    }  
}
void heapifymin(long long int a,long long int min[])
{
	long long int j,k;
	min[endmin]=a;
	endmin++;
	j=endmin-1;
    k=j/2; // hp mei vrtx
    while(k>0&&(min[k])<(min[j]))
    {
       	swap(&min[j],&min[k]);
        j=k;
        k=j/2;
    }
}
void shuffledownmin(long long int min[],long long int p)
{
     long long int i,j;
     i=2*p;
     while(i<(endmin)&&((min[p])<(min[i])||(min[p])<(min[i+1])))  // pblm when i=endmin i+1 accsess
     {
     	if((min[i])>(min[i+1])){
     		swap(&min[i],&min[p]);
     		p=i;
     		i=2*p;
     	}
     	else{
     		swap(&min[i+1],&min[p]);
     		p=i+1;
     		i=2*p;
     	}
     }
    // if(i==(endmin-1)&&(min[p])<(min[i]))
    // {
     //	swap(&min[i],&min[p]);
     //}

}
void deletemin(long long int min[])
{
//	pos[hp[1]]=9;
	min[1]=min[(endmin-1)];
	(endmin)--;
    shuffledownmin(min,1);
}
void shuffledownmax(long long int max[],long long int p)
{
     int i,j;
     i=2*p;
     while(i<(endmax)&&((max[p])>(max[i])||(max[p])>(max[i+1])))
     {
     	if((max[i])<(max[i+1])){
     		swap(&max[i],&max[p]);
     		p=i;
     		i=2*p;
     	}
     	else{
     		swap(&max[i+1],&max[p]);
     		p=i+1;
     		i=2*p;
     	}
     }
   //  if(i==(endmax-1)&&(max[p])>(max[i]))
     //{
     //	swap(&max[i],&max[p]);
     //}

}
void deletemax(long long int max[])
{
	max[1]=max[(endmax-1)];
	(endmax)--;
    shuffledownmax(max,1);
}
long long int insert(long long int a,long long int min[],long long int max[])
{
	if(a>=min[1])
	{
		heapifymax(a,max);
	}
	else
	{
		heapifymin(a,min);
	}
	//int n_min=endmin-1,n_max=endmax-1;
	if((endmin-endmax)>1)
	{
		heapifymax(min[1],max);
		deletemin(min);
	}
	else if((endmax-endmin)>1)
	{
		heapifymin(max[1],min);
		deletemax(max);
	}
	if(endmin>=endmax)
		return min[1];
	else
		return max[1];
}
int main()
{
	int sw,z;
	scanf("%d",&sw);
	for(z=0;z<sw;z++){
	long long int a,b,c,n,i,j;
	long long int d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
	long long int *f,*min,*max;
	long long int sum=1;
	f=malloc((n+1)*sizeof(long long int));
	min=malloc((n+1)*sizeof(long long int));
	max=malloc((n+1)*sizeof(long long int));
	f[1]=1;
	spmax=1;
	endmax=1;
	endmin=2;
	min[1]=f[1];
	d=f[1];  // d is median
	f[2]=(a*d+b*2+c)%modulus;
	sum=sum+f[2];
	for(i=3;i<=n;i++)
	{
		d=insert(f[i-1],min,max);
	//	printf("median %d\n",d);
	//	for(j=1;j<endmax;j++)
	//		printf("%d ",max[j]);
	//	printf("\n");
		f[i]=(a*d+b*i+c)%modulus;
		sum=sum+f[i];
	}
//	for(i=1;i<=n;i++)
//		printf("%d ",f[i]);
//	printf("\n");
	printf("%lld\n",sum);
	}
	return 0;
}