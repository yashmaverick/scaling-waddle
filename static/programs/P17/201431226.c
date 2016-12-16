#include<stdio.h>
int main()
{
	int n,i,t;
	scanf("%d",&n);
	int A[n],B[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<n;i++)
		scanf("%d",&B[i]);
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		int p=-1,q=-1,r=-1,s=-1;
		scanf("%d %d",&a,&b);
		for(i=0;i<n;i++)
		{
			if(a==A[i])
				p=i;
			if(b==A[i])
				q=i;
			if(a==B[i])
				r=i;
			if(b==B[i])
				s=i;
			if(p!=-1 && q!=-1 && r!=-1 && s!=-1)
				break;
		}
		if(p>q)
		{
			int j;
			j=p;
			p=q;
			q=j;
		}
		if(r>s)
		{
			int k;
			k=r;
			r=s;
			s=k;
		}
		int l=(q-p)+1;
		int m=(s-r)+1;
		int C[l],D[m],S[m];
		for(i=0;i<l;i++)
		{
			C[i]=A[p];
			p++;
		}
		for(i=0;i<m;i++)
		{
			D[i]=B[r];
			r++;
		}
		int y=0,x;
		for(i=0;i<m;i++)
		{
			int flag=0;
			for(x=0;x<l;x++)
			{
				if(D[i]==C[x])
				{
					flag==1;
					//		break;
				}
			}
			if(flag==0)
			{
				S[y]=D[i];
				y++;
			}
		}
		int f=0;
		for(i=0;i<n;i++)
		{
			for(x=0;x<y;x++)
			{
				if(A[i]==S[x])
				{
					if(f!=1)
					printf("%d\n",S[x]);
					f=1;
				}
			}


		}

	}
	return 0;
}







