#include<stdio.h>
#include<string.h>
void quicksor(int fg[],int fi,int li);
void swap(int *v,int *f);
int main()
{
	int t,i,d,p,sum,e,m,n,temp,v,b[100009],w,c,ans,x;
	char a[100009];
	scanf("%d ",&t);
	for(i=1;i<=t;i++)
	{
		int ans=0;
		scanf("%s",a);
		d=strlen(a);
		for(p=0;p<d;p++)
		{
			if(a[p]=='J')
				b[p]=-100000;
			else if(a[p]=='M')
				b[p]=99999;
			else 
				b[p]=1;
		}
		sum=b[0];
		int z=0;
		for(w=1;w<d;w++)
		{
			b[w]+=b[w-1];
			if(b[w]==0)
				z++;
		}
		quicksor(b,0,d-1);
		/*for(e=1;e<d;e++)
		  {
		  for(m=0;m<d-1;m++)
		  {
		  if(b[m]>b[m+1])
		  {      temp=b[m+1];           
		  b[m+1]=b[m];
		  b[m]=temp;
		  }
		  }
		  }*/

	for(c=0;c<d-1;c++)
	{
		x=1;
		while(b[c]==b[c+1])
		{   
			x++;
			c++;
		}
		ans+=(x*(x-1))/2;
	}
	ans+=z;
	printf("%d\n",ans);
}
return 0;
}
void quicksor(int fg[],int fi,int li)
{int pivin,temp,in1,in2;
if(fi<li)
    { 
	pivin=fi;
	in1=fi;
	in2=li;
	while(in1<in2)
	{
		while(fg[in1]<=fg[pivin])
		{
			in1++;
		}
		while(fg[in2]>fg[pivin])
		{
			in2--;
		}
		if(in1<in2)
		{
			swap(&fg[in1],&fg[in2]);
		}
	}
	swap(&fg[pivin],&fg[in2]);
	quicksor(fg,fi,in2-1);
	quicksor(fg,in2+1,li);
   }
}
void swap(int *v,int *f)
{int t;
	t=*v;
	*v=*f;
	*f=t;
}

