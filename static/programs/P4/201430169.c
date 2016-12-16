#include<stdio.h>
char s[100001];
int A[100001];
void swap(int A[], int x, int y)
{
	int t=A[x];
	A[x]=A[y];
	A[y]=t;
}
void sort(int A[], int f,int l)
{
	if(f<l-1)
	{
		int mid,pivot,p,q;
		mid=(f+l)/2;
		swap(A,mid,l-1);
		pivot=A[l-1];
		p=f;q=l-2;
		while(p<=q)
		{
			while(A[p]<pivot)
				p++;
			while(A[q]>pivot)
				q--;
			if(p<q)
				swap(A,p,q);
			if(A[p]==pivot && A[q]==pivot)	
			{	p++;q--;}
		}
		swap(A,p,l-1);
		sort(A,f,p);
		sort(A,p+1,l);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%s",s);
		int i=1,j=1,n=1,count=0,t=1;
		if(s[0]=='J')
			A[0]=7907;
		else if(s[0]=='M')
			A[0]=7919;
		else
			A[0]=-15826;//printf("%d\n",A[0]);
		while(s[i]!='\0')
		{
			n++;
			if(s[i]=='J')
			{	A[j]=A[j-1]+7907;j++;}
			else if(s[i]=='M')
			{	A[j]=A[j-1]+7919;j++;}
			else
			{	A[j]=A[j-1]-15826;j++;}
			i++;
		}//printf("n=%d\n",n);
		/*for(i=0;i<n;i++)
			printf("%d ",A[i]);
		printf("\n");*/
		sort(A,0,n);
		/*for(i=0;i<n;i++)
			printf("%d ",A[i]);
		printf("\n");*/
		for(i=0;i<n;i++)
		{
			if(A[i]==0)
				count++;

			if(A[i]==A[i+1])	
				t++;
			else if(A[i]==A[i-1] && A[i]!=A[i+1])
			{
				count+=(t*(t-1))/2;
				t=1;
			}

		}
		if(t>1)
			count+=(t*(t-1))/2;
		printf("%d\n",count);	
	}
	return 0;
}
