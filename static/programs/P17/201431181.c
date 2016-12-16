#include<stdio.h>
int a,b,A[1000007],N;
int IP( int I[] , int P[] , int l , int s )
{
	if( (a<=A[l] && b>=A[l]) || (a>=A[l] && b<=A[l]) )
	{
		return l;
	}
	else if( a<=A[l] && b<=A[l] )
	{
		s++;
		l=I[P[s]];
		//printf("s l %d %d\n",s,l); 
		if( l!=I[a] && l!=I[b] )
			IP( I,P,l,s );
		else
			return l;
	}
	else if( a>=A[l] && b>=A[l] )
	{
		if( P[A[l]+1]<=A[l] )
			s=A[l]+2;
		else	
			s=A[l]+1;
		l=I[P[s]];
		//printf("s l ->%d %d\n",s,l); 
		if( l!=I[a] && l!=I[b] )
			IP( I,P,l,s );
		else
			return l;
	}
}
int main()
{
	int i,t,r,l,s;
	scanf("%d",&N);
	int P[N+1],I[N+1];
	for( i=1; i<=N ; i++ )
		scanf("%d",&P[i]);
	s=1;
	for( i=1 ; i<=N ; i++ )
	{
		scanf("%d",&I[i]);
		A[I[i]]=i;
		if( I[i]==P[1] )
			l=I[i];
	}
	for( i=1 ; i<=N ; i++ )
		P[i]=A[P[i]];
	scanf("%d",&t);
	for( i=0 ; i<t ; i++ )
	{
		scanf("%d%d",&a,&b);
		a=A[a];
		b=A[b];
		if( a==b )
			printf("%d\n",I[a]);
		else
			printf("%d\n",IP( I,P,l,s ));	
	}
	return 0;
}

