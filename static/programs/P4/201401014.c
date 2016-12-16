#include<stdio.h>
#include<string.h>
//long long int A[1000000];
void merge(long long int A[],long long int i,long long int j,long long int a,long long int b);
void sort(long long int A[],long long int i,long long int j);
int main()
{
	long long int n,k,t,i,l,m,count,count0,pairs,flag,A[100001];
	char S[100001],c;
	scanf("%lld",&t);
	scanf("%c",&c);
	while(t--)
	{
		flag=0;
		//scanf("%c",&S[0]);
		//i=1;
		scanf("%s[^\n]",S);
		l=strlen(S);
		if(S[0]=='J')
			A[0]=100001;
		if(S[0]=='M')
			A[0]=100002;
		if(S[0]=='R')
			A[0]=-200003;
		//		printf("%lld \n",A[0]);
	//	while((c=getchar())!='\n')
	//	{
	//		S[i]=c;
		//scanf("%[^\n]",S);
		//l=strlen(S);
		for(i=1;i<l;i++)
		{
			if(S[i]=='J')
				m=100001;
			if(S[i]=='M')
				m=100002;
			if(S[i]=='R')
				m=-200003;
			A[i]=A[i-1]+m;
			//			printf("%lld i %lld A[i]\n",i,A[i]);
			//i++;
		}	
		//n=i;
		//for(n=0;n<i;n++)
		//	printf("%lld ",A[n]);
		//printf("\n");
		sort(A,0,l-1);
//			for(k=0;k<n;k++)
//					printf("%lld ",A[k]);
//				printf("\n");
		count=1;
		pairs=0;
		i=0;
		count0=1;
		while(i!=l-1)
		{
			//count=1;
			//count1=1;
			//if(A[i]==0)
			//	flag=1;
			if(A[i+1]==A[i])
			{
				if(A[i]==0)
				{count0++;}
			//	else
//				printf("%lld A[i]\n",A[i]);
				count++;
//				printf("%lld count\n",count);
				i++;
			//	continue;
			}
			else
			{
				if(A[i]==0)
					flag=1;
				pairs+=((count)*(count-1))/2;
//				printf("%lld pairs %lld A[i] %lld i\n",pairs,A[i],i);
				i++;
				count=1;
			}
		}
		if(count>1)
			pairs+=((count)*(count-1))/2;
//		printf("%lld pairs\n",pairs);
		//if(count0==1 && flag=1)
		//	pairs+=1;
		if(flag==1 && count0==1)
			pairs+=count0;
		if(count0>1)
			pairs+=count0;
		printf("%lld\n",pairs);
	}
	return 0;
}
void merge(long long int A[],long long int i,long long int j,long long int a,long long int b)
{
	//	printf("%d i %d j\n",i,j);
	long long int m,count1,count2;
	long long int *p1,*p2;
	long long int q,arb;;
	long long int temp[100001];
	arb=0;
	p1=&A[i];
	p2=&A[((i+j)/2)+1];
	m=(a+b);
	q=i;
	count1=0;
	count2=0;
	int flag=0;
	while(m--)
	{
		flag=0;
		if(count1<a)
		{
			if((*p1)<=(*p2))
			{
				flag=1;
				temp[q]=(*p1);
				count1++;
				if(count1<a)
					p1++;
				else
					(*p1)=1000000000001;
			}
		}
		if(count2<b && flag!=1)
		{
			if(((*p1)>=(*p2)))
			{
				flag=2;
				temp[q]=(*p2);
				count2++;
				if(count2<b)
					p2++;
				else
					(*p2)=1000000000001;
			}
		}
		q++;
	}
	arb++;
	for(q=i;q<j+1;q++)
		A[q]=temp[q];	
	return ;
}
void sort(long long int A[],long long int i,long long int j)
{
	if(i>=j)
		return;
	else
	{
		sort(A,i,(i+j)/2);
		sort(A,((i+j)/2)+1,j);
		merge(A,i,j,(j-i+2)/2,(j-i+1)/2);
		return;
	}
}

