#include<stdio.h>
long long int cmp(const void *p,const void *q)
{
		long long int l=*(long long int *)p;
		long long int r=*(long long int *)q;
		return l-r;
}
int main()
{
		long long int t,i,k,c;
		char a[100004];
		scanf("%lld",&t);
		while(t--)
		{
				scanf("%s",a);
				c=i=0;
				long long int j[100004]={};
				long long int r[100004]={};
				long long int c[100004]={};
				long long int ans=0;
				j[0]=r[0]=0;
				while(a[i]!='\0')
				{
						//printf("start	%d j=%d	r=%d\n",i+1,j[i+1],r[i+1]);
						if(a[i]=='M')
						{
								j[i+1]=j[i]+1;
								r[i+1]=r[i]+1;
								//		printf("%d	j=%d	r=%d\n",i+1,j[i+1],r[i+1]);
						}
						else if(a[i]=='R')
						{
								r[i+1]=r[i]-1;
								j[i+1]=j[i];
								//printf("j[%d]=%d	r[%d]=%d\n",i+1,j[i+1],i+1,r[i+1]);
						}
						else
						{
								j[i+1]=j[i]-1;
								r[i+1]=r[i];
								//		printf("r[%d]=%d	j[%d]=%d\n",i+1,r[i+1],i+1,j[i+1]);
						}
						//printf("end	%d j=%d	r=%d\n",i+1,j[i+1],r[i+1]);
						i++;
				}
				for(k=0;k<=i;k++)
						c[k]=1000000*j[k]+r[k];
				/*for(k=0;k<=i;k++)
						printf("%lld ",j[k]);
				printf("\n");
				for(k=0;k<=i;k++)
						printf("%lld ",r[k]);
				printf("\n");
				for(k=0;k<=i;k++)
						printf("%lld ",c[k]);
				printf("\n");
*/
				ans=0;
				qsort(c,i+1,sizeof(long long int),cmp);
			/*	for(k=0;k<=i;k++)
						printf("%lld ",c[k]);
				printf("\n");*/
				long long int count=1;
				for(k=0;k<=i;k++)
				{
						if(c[k]==c[k+1])
								count++;
						else
						{
								ans=ans+((count*(count-1))/2);
								count=1;
						}
				}
				
				printf("%lld\n",ans);



		}
		return 0;
}
