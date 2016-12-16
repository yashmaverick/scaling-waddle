#include<stdio.h>
#include<stdlib.h>
#define MAX 1000005

long long int A[MAX];
long long int B[MAX];
int main()
{
long long int node,i,j,k,m;
scanf("%lld",&node);
for(i=0;i<node;i++)
    scanf("%lld",&A[i]);


for(i=0;i<node;i++)
    scanf("%lld",&B[i]);

long long int test;
scanf("%lld",&test);
for(k=0;k<test;k++)
{
    long long int flag=0,flag1=0;
    long long int fdest,sdest,ans,findex,sindex,FINDEX,SINDEX,ans1;
    scanf("%lld %lld",&fdest,&sdest);
    if(fdest==sdest)
	ans=fdest;
    {
    for(m=0;m<node;m++)
    {
	if(B[m]==fdest)
	    findex=m;
	if(A[m]==fdest)
	    FINDEX=m;
	if(A[m]==sdest)
	    SINDEX=m;
	if(B[m]==sdest)
	    sindex=m;
    }

/*    if(FINDEX<SINDEX && findex<sindex )
	ans1=A[FINDEX];
    if(FINDEX>SINDEX && findex>sindex)
	ans1=A[SINDEX];
    if(FINDEX>SINDEX && findex<sindex)
	ans1=A[SINDEX];
    if(FINDEX<SINDEX && findex>sindex)
	ans1=A[FINDEX];          */

//     printf("%d\n",ans1);      
   
    for(i=0;i<node;i++)
    {
	
	if(flag==1) 
	    break;
    
	else
	{
           

          if(findex<sindex)
	    {
		for(j=findex;j<=sindex;j++)
		   if (A[i]==B[j])
		   {
		       ans=A[i];
		       flag=1;
		       flag1=1;
		       break;
		   }
	    }
	    else    if(sindex<findex)
	    {
		for(j=sindex;j<=findex;j++)
		{
		    if(A[i]==B[j])
		    {
			ans=A[i];
			flag=1;
			flag1=1;
			break;
		    }
		}
	    }
	}
    }
    }
/*    if(flag1==0)
	printf("%lld\n",ans1);
     else     */
    printf("%lld\n",ans);
}
 
return 0;
}
