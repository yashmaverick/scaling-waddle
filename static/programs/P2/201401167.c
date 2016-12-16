#include<stdio.h>
#include<string.h>
#include<limits.h>
#define f(i,a,n) for(i=a;i<n;i++)
/*#define S second
#define q first
#define pb push_back
#define mp make_pair*/
#define Sc(n) scanf("%lld",&n)
#define sc(n) scanf("%d",&n)
//#define It iterator
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; sc(t); while(t--)
//using namespace std;
typedef long long LL;
//typedef pair<int,int> PII;
int main()
{
	int a[3][100004],i,j;LL p[3],q,r;
	LL s,pr[100004];
	DRT(){s=0;
		SET(a[0],INT_MIN);
			SET(a[0],INT_MIN);	
			SET(a[0],INT_MIN);
	SET(pr,0);
			f(i,0,3)
		{	Sc(p[i]);
//			cout<<pr[i];
			f(j,0,p[i])
				sc(a[i][j]);
		}
//			cout<<endl;
		int b=0,e=p[2],m,bi=0;
		for(i=p[1]-1;i>=0;i--)
		{b=i;e=p[2]-1;
			while(b<=e)
			{	m=(b+e)/2;
				if(a[1][i]<=a[2][m] && (a[1][i]>a[2][m-1] || m==i))
				{pr[i]=pr[i+1]+p[2]-m;break;}
				else if(a[1][i]<=a[2][m])
					e=m-1;
				else
					b=m+1;
			}
			bi=m;}
			//if(bi>=p[2])break;}
		f(i,0,p[0])
		{b=i;e=p[1]-1;
	       		while(b<=e)
			{       m=(b+e)/2;
				if(a[0][i]<=a[1][m] && (a[0][i]>a[1][m-1] || m==i))
				{	s+=pr[m];
					break;}
				else if(a[0][i]<=a[1][m])
					e=m-1;
				else
					b=m+1;
			}
			bi=m;
		//	if(bi>=p[1])
		//		break;
		}
//		f(i,0,4)
//			cout<<pr[i]<<" ";
		printf("%lld\n",s);
	}
}
