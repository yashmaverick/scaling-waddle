#include<stdio.h>
int a[1000];
void triplet(int k,int n)
{
	int s,z,c;
	s=0;
	while(s<n-2)
	{
	        z=s+1;
	        c=n-1;
		while(z<c)
		{
		if(a[s]+a[z]+a[c]==k)
		{
			printf("YES\n");
			return;
		}
		else if(a[s]+a[z]+a[c]>k)
			c--;
		else
			z++;
		}
		s++;
	}
	printf("NO\n");
	return;
}
void quick(int l,int h)
{
	int w,q,k,t;
	if(l==h)
		return;
	w=l;
	q=h;
	while(w<=q)
	{
		if(a[q]<a[w])
		{
			t=a[w];
			a[w]=a[q-1];
			a[q-1]=a[q];
			a[q]=t;
			q--;
		}
		else
		{
			w++;
		}

	}
	if(l!=q)
		quick(l,q-1);
	if(q!=h)
		quick(q+1,h);


}
int main()
{
	int i,j,n,m,k;
	char g;
	scanf("%d",&m);
	while(m--)
	{
	scanf("%d%d",&n,&k);
	i=0;
	while(i<n)
	{
		getchar();
		g=getchar();
		while(g!=' ')
			g=getchar();

		scanf("%d",&a[i]);
		i++;
	}
	quick(0,n-1);
	triplet(k,n);
/*	i=0;
	while(i<n)
	{
		printf("%d ",a[i]);
		i++;
	}
	printf("\n");*/
	}
	return 0;

}
  
