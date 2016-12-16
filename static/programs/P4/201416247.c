#include<stdio.h>
#include<string.h>
int cfunc (const void * a, const void * b)
{
	   return ( *(long long*)a - *(long long*)b );
}
int main()
{
	long long  p,t,temp,min,m,d,b[1000100],i,j,k,temp1,count;
	char a[100000];
	scanf("%lld",&m);
	for(t=0;t<m;t++)
	{temp1=0;
		scanf("%s",a);
		d=strlen(a);
		for(i=0;i<d;i++)
		{
			if(a[i]=='J'){
				b[i]=100001;
			//	printf("%lld\n",b[i]);
			}
			else if(a[i]=='M')
			{	b[i]=-100002;
			//	printf("%lld\n",b[i]);
			}
			else if(a[i]=='R')
			{	b[i]=1;
			//	printf("%lld\n",b[i]);
			}

		}
	//	printf("%lld ",b[0]);
		for(j=1;j<d;j++){
			b[j]=b[j]+b[j-1];
	//		printf("%lld ",b[j]);
		}
	//	printf("\n");
		for(j=d;j>0;j--){
                        temp=b[j-1];
			b[j]=temp;
		}
                b[0]=0;
		//for(j=0;j<=d;j++)
	//		printf("%lld ",b[j]);
	/*	for(j=d;j>0;j--)
		{
			b[j]=b[j-1];
			
			printf("%lld ",b[j]);

		}
		b[0]=0;*/
	//	printf("\n");
/*		min=b[0];
		c[0]=0;
		for(j=1;j<=d;j++)
		{
			if(min>b[j])
				min=b[j];
			c[j]=0;
		 }
		printf("%lld \n",min);*/
	/*       for(j=0;j<=d;j++)
			printf("%lld ",b[j]);*/
	       //printf("\n");
  /*		for(j=0;j<=d;j++)
		{       
			b[j]=b[j]-min;
			printf("%lld ",b[j]);
			c[b[j]]++;
			
		}
//		printf("\n");*/
		qsort(b, d+1, sizeof(long long), cfunc);
		/*for(j=0;j<=d;j++)
			printf("%lld ",b[j]);
		printf("\n");*/
		p=0,count=1;
		/*if(b[0]==0)
			count=1;*/
		temp1=b[0];

		for(j=1;j<=d;j++)
		{
			
			if(b[j]==temp1){
				count++;
			}
	//			printf("%lld\n",temp2);
		else
				{
			//		printf("%lld ",count);
			     
			     p=p+(((count)*(count-1))/2);
				count=1;
				temp1=b[j];
		}
		}
		p=p+(((count)*(count-1))/2);

		/*for(k=0;k<200100;k++){
		//	printf("%lld",c[k]);
		//	if(c[k]>0)
			p=p+((c[k]*(c[k]-1))/2);}
*/
		printf("%lld\n",p);
		
	}
	return 0;
}

