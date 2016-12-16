#include <stdio.h>

int main()
{
    int N,T,i,cnt,ans1,x,ans2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        int S[N],A[N],D[N];
        for(i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }       
        cnt=0; ans2=0;
	    S[0]=ans1=A[N-1];
	    D[ans1]=0;
	    for(i=N-2;i>=0;i--)
	    {
	        if(A[i]>S[cnt])
	        {
	            D[A[i]]=D[S[cnt]]+1;
	            S[++cnt]=A[i];
	        }
	        else
	        {
	            while(S[cnt]>A[i]) x=S[cnt--];
	            D[A[i]]=D[x]+1;
	            S[++cnt]=A[i];
	        }
	        if(D[A[i]]>ans2)
	        {
	            ans1=A[i];
	            ans2=D[A[i]];
	        }
	        else if(D[A[i]]==ans2)
	        {
	            if(A[i]<ans1) ans1=A[i];
	        }
	    }
	    printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
