#include<stdio.h>
int P[100001],Q[100001],R[100001],N[100001];
int bin(int A[], int key, int le, int ri)
{
	int mid,l=le,r=ri-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(A[mid]==key)
			return mid;
		else if(A[mid]>key)
			r=mid-1;
		else
			l=mid+1;
	}
	//if(l==ri-1)
	//	return -1;
	//else
		
			return l;
}	
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int np,nq,nr,i,j,count=0,a,b;
		scanf("%d",&np);
		for(i=0;i<np;i++)
			scanf("%d",&P[i]);
		scanf("%d",&nq);
		for(i=0;i<nq;i++)
			scanf("%d",&Q[i]);
		scanf("%d",&nr);
		for(i=0;i<nr;i++)
			scanf("%d",&R[i]);
		//printf("%d\n",bin(P,3,0,np));
		//a=bin(Q,P[0],0,np);
			
			//j=a;//printf("i=%d\nptr to Q array:%d\n",i,a);
			//if(M[i]<nq)
		N[nq]=0;
		for(i=nq-1,j=nq-1;i>=0 && j>=0;i--)
		{
			a=bin(R,Q[i],i,nr);//printf("nr-a=%d\n",nr-a);
			N[j]=N[j+1]+nr-a;j--;//printf("%d ",N[j]);
		}//printf("\n");
			
			/*while(j<nq)
			{
				b=bin(R,Q[j],j,nr);//k=b;
				
				//while(Q[j]<R[k] && k<nr)
				//{
					count+=nr-b;
					//printf("i=%d j=%d k=%d\n",i,j,k);
				//	k++;
				//}
				j++;
			}*/
		//for(i=0;i<nq;i++)
		//	printf("%d ",N[i]);
		//printf("\n");	
		for(i=0;i<np;i++)
		{
			b=bin(Q,P[i],i,nq);
			if(b<nq)
				count+=N[b];
		}
		printf("%d\n",count);
	}
	return 0;
}
