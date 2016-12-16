#include<stdio.h>
int main()
{
  int n,a[100100],b[100100],h[100100]={-1};
  scanf("%d",&n);
  int i,t,x1,y1,root,r;
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      h[a[i]]=i;
    }
  root=a[0];
  for(i=0;i<n;i++)
    {
      scanf("%d",&b[i]);
      if(b[i]==root)
	r=i;
    }
  scanf("%d",&t);
  while(t!=0)
    {
      int x=-1,y=-1,f=0,ans;
      scanf("%d",&x1);
      scanf("%d",&y1);
      for(i=0;i<n;i++)
	{
	  if(x1==b[i])
	    x=i;
	  if(y1==b[i])
	    y=i;
	}
      if(x>=0 && y>=0)
	{
	  if((x<r && y>r)||(x>r && y<r)||(x==r || y==r))
	    {
	      ans=root;
	    }
	  else
	    {
	      int st,end,low,j,min=n+1;
	      st=x<y?x:y;
	      end=x>y?x:y;
	      low=h[x1]<h[y1]?h[x1]:h[y1];
	      if(end-st>1)
		{
		  for(i=st+1;i<end;i++)
		    {
		      if(h[b[i]]<low && h[b[i]]>0 && b[i]!=root)
			{
			  if(h[b[i]]<min)
			    min=h[b[i]];
			}
		    }
		  if(min==n+1)
		    ans=a[low];
		  else
		    ans=a[min];
		}
	      else
		{
		  ans=a[low];
		}
	    }
	  printf("%d\n",ans);
	}
      t--;
    }
  return 0;
}
	      
