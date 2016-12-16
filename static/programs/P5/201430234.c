#include<stdio.h>
qsort(int a[],int f,int l)
{
	if(f>=l)
		return;
	int wall,pivot,i,t;
	wall=f;
	pivot=l;

	for(i=f;i<l;i++)
	{
		if(a[i]<a[pivot])
		{
			t=a[wall];
			a[wall]=a[i];
			a[i]=t;
			wall++;
		}
	}
	t=a[wall];
	a[wall]=a[pivot];
	a[pivot]=t;
	qsort(a,f,wall-1);
	qsort(a,wall+1,l);
}
int main()
{
	int w;
	scanf("%d",&w);
	while(w--)
	{
		int n,i,flag=0,l,r,k;
		char s[1007];
		scanf("%d%d",&n,&k);
		int a[1007];
		for(i=0;i<n;i++)
		{
			scanf("%s%d",s,&a[i]);
		}
		qsort(a,0,n-1);
		for(i=0;i<n-2;i++)
		{
			l=i+1;
			r=n-1;
			while(l<r)
			{
				if((a[i]+a[l]+a[r])==k)
				{
					flag=1;
					break;
				}
				else if((a[i]+a[l]+a[r])<k)
					l++;
				else 
					r--;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
