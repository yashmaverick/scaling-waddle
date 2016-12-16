#include<stdio.h>
void quicksort(int x[10001],int first,int last){
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
int main()
{
	int n,x,i,s,j,a[10001],l,t,m,k,n1,flag=0;
	char b[1005];
	scanf("%d",&m);
	for(t=0;t<m;t++)
	{
		scanf("%d%d",&n1,&k);
		for(i=0;i<n1;i++)
		{
			scanf(" %s %d",b,&a[i]);
		//printf("%s",b);
		}
		quicksort(a,0,n1-1);
		/*	x=0;
			for(j=x+1;j<n1;j++){
			for(l=x+2;l<n1;l++){
			if(a[x]+a[j]+a[l]==k){
			printf("YES\n");
			flag=1;
			break;
			}
			if(flag==0)
			{printf("s");
			x++;
			continue;

			}}}
			if(flag==0)
			printf("NO\n");*/
		for(x=0;x<n1-2;x++)
		{
			flag=0;
			s=x+1;
			l=n1-1;
			while(s<l)
			{
				if(a[x]+a[l]+a[s]==k)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				else if(a[x]+a[l]+a[s]<k)
				{
					s++;
				}
				else 
					l--;

			}
			if(flag==1)
				break;
			
		}
		if(flag==0)
			printf("NO\n");
//		else
//			printf("YES\n");

	}
	return 0;
}
