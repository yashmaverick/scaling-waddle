#include<stdio.h>
#include<string.h>
 int a[100005],b[100005];
void mergeSort( int low, int mid, int high);
void partition( int low, int high);
void partition( int low, int high){

	 int mid;
	if(low<high){
		//printf("ok\n");
		mid=(low+high)/2;
		partition(low,mid);
		partition(mid+1,high);
		mergeSort(low,mid,high);
	}
}

void mergeSort( int low, int mid, int high){

	 int i,m,k,l;
	 int tempa[100000];
	int tempb[100000];

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high)){

		if(a[l]<a[m]){
			tempa[i]=a[l];
			tempb[i]=b[l];
			l++;
		}
		else if(a[l]==a[m])
		{
			if(b[l]<=b[m])
			{
				tempa[i]=a[l];
				tempb[i]=b[l];
				l++;
			}
			else
			{
				tempa[i]=a[m];
				tempb[i]=b[m];
				m++;
			}
		}
		else{
			tempa[i]=a[m];
			tempb[i]=b[m];
			m++;
		}
		i++;
	}

	if(l>mid){
		for(k=m;k<=high;k++){
			tempa[i]=a[k];
			tempb[i]=b[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			tempa[i]=a[k];
			tempb[i]=b[k];
			i++;
		}
	}

	for(k=low;k<=high;k++){
		a[k]=tempa[k];
		b[k]=tempb[k];
	}
}	
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{

		int n,count,l,c,j,m,r,i,temp;
		char s[100005];
		scanf("%s",s);
		l=strlen(s);
		//printf("l=%d\n",l);
		c=1;
		a[0]=b[0]=0;
		j=0;m=0;r=0;
		for(i=0;i<l;i++)
		{
			if(s[i] == 'J' )
			{
				j++;
				//	printf("j=%d\n",j);
			}
			else if(s[i] == 'M')
			{
				m++;
				//	printf("m=%d\n",m);
			}
			else if(s[i] == 'R')
			{
				r++;
				//	printf("r=%d\n",r);
			}
			a[c]=m-j;
			b[c++]=m-r;
			//	printf("a[%d]=%d b[%d]=%d\n",c-1,a[c-1],c-1,b[c-1]);
		}
		temp=1;
		count=0;
		partition(0,l);
		/*for(i=0;i<=l;i++)
			printf("%lld ",a[i]);
		printf("\n");
		for(i=0;i<=l;i++)
			printf("%lld ",b[i]);
		printf("\n");*/
		for(i=0;i<l;i++)
		{
			if(a[i]==a[i+1] && b[i]==b[i+1])
			{
				temp++;
				//printf("temp=%lld \n",temp);
			}
			else
			{
				count=count+(temp)*(temp-1)/2;
				//printf("count=%lld",count);
				temp=1;
			}
			//count=count+(temp)*(temp-1)/2;
		}
			count=count+(temp)*(temp-1)/2;

		printf("%d\n",count);
	}
	return 0;
}


