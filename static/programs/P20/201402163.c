#include<stdio.h>
#include<stdlib.h>
long long int end,start,f,b;
typedef struct abbo
{
	long long int v;
	struct abbo* next;
}abbo;
void insert(abbo** a,long long int k,long long int l)
{
	abbo* tmp;
	tmp=malloc(sizeof(abbo));
	tmp->next=a[k]->next;
	a[k]->next=tmp;
	tmp->v=l;
	abbo* vam;
	vam=malloc(sizeof(abbo));
	vam->next=a[l]->next;
	a[l]->next=vam;
	vam->v=k;

}
void dfs(abbo** a,long long int s[],long long int b[],long long int c[])
{
	if(start==end)
	{
		return;
	}
        long long int i;
	i=1;
	abbo* tmp;
	tmp=a[s[start]];
	b[s[start]]=1;
	i=c[s[start]];
        while(tmp->next!=NULL)
        {
		tmp=tmp->next;
		if(b[tmp->v]==0)
		{
		s[end]=tmp->v;
		c[tmp->v]=i+1;
		end++;
	//	printf("*\n");
		}

        }
	start++;
//	printf("**\n");
	dfs(a,s,b,c);

}
int main()
{
	long long int m,n,i,j,k,l;
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&n);
		long long int b[n+1],c[n+1],s[n];
		i=0;
		while(i<=n)
		{
			b[i]=0;
			c[i]=0;
			i++;
		}
		abbo* a[n+1];
		i=0;
		while(i<=n)
		{
			a[i]=malloc(sizeof(abbo));
			a[i]->next=NULL;
			i++;
		}
		i=0;
		while(i<n-1)
		{
	                scanf("%lld%lld",&k,&l);
		        insert(a,k,l);	
			i++;
		}
		s[0]=1;
		b[1]=1;
		c[1]=0;
		start=0;
		end=1;
		dfs(a,s,b,c);
		i=1;
		l=0;
		k=0;
		while(i<=n)
		{
			if(l<c[i])
			{ 
				k=i;
			l=c[i];

			}
			i++;
		}
		s[0]=k;
		c[k]=0;
		i=0;
		while(i<=n)
		{
			b[i]=0;
			i++;
		}
		b[k]=1;
		start=0;
		end=1;
		dfs(a,s,b,c);
		i=1;
		l=0;
		k=0;
		while(i<=n)
		{
			if(l<c[i])
			{ 
				k=i;
			l=c[i];

			}
			i++;
		}
		printf("%lld\n",l+1);
	
/*		i=1;
		abbo* tmp;
		while(i<=n)
		{
			tmp=a[i]->next;
		         while(tmp->next!=NULL)
			 {
				 printf("%lld",tmp->v);
				 tmp=tmp->next;
			 }
			 printf("%lld",tmp->v);
			 printf("\n");
			i++;
		}*/
/*		i=1;
		while(i<=n)
		{
			printf("%lld*0%lld\n",b[i],c[i]);
			i++;
		}*/
	
	}
	return 0;
}
