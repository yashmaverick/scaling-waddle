#include<stdio.h>

void quicksort(int xorxor_1234[],int last,int lessfirst);

int main(){
	int x[100000],size,i,j,k,l,flag=0,t,m;
	char z[100000];
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d %d",&size,&l);
		flag=0;
		for(i=0;i<size;i++)
			scanf("%s %d",z,&x[i]);
		quicksort(x,0,size-1);
		j=0;
		m=size-1;
		while(j!=size-1)
		{
			k=x[j];
			i=j+1;
			m=size-1;
			while(i<m&&k+x[i]<l)
			{
				if(k+x[i]+x[m]==l)
				{
					flag=1;
					break;
				}
				else if(k+x[m]+x[i]>l)
				{
					m--;			
				}
				else if(k+x[m]+x[i]<l)
				{
					i++;
				}
			}
			if(flag==1)
			{
				break;
			}
			j++;
		}
		if(flag==1)
		{
			printf("YES\n");
		}
		else if(flag==0)
		{
			printf("NO\n");
		}
		t--;
	}
	return 0;
}

void quicksort(int x[],int first,int last){
	int pivot,j,temp,i;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while(x[i]<=x[pivot]&&i<last)
				i++;
			while(x[j]>x[pivot])
				j--;
			if(i<j){
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
}
