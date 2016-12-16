#include<stdio.h>
int main()
{
	int n,preo[100007],ino[100007],i,t,q,w,s,d,u,y,min,e,r;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&preo[i]);
	for(i=0;i<n;i++)
		scanf("%d",&ino[i]);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{q=w=0;
		scanf("%d%d",&s,&d);
	        while(preo[q]!=s)
			q++;
		while(preo[w]!=d)
			w++;
		
		{u=y=0;
           	        while(ino[u]!=s)
			 u++;
	           	while(ino[y]!=d)
         			y++;
			if(q<w)
				min=q;
			else min=w;
			for(e=0;e<=min;e++)
			 {
				 r=0;
				 while(ino[r]!=preo[e])
					 r++;
				 if(u<=r&&y>=r||u>=r&&y<=r)
				 {
					 break;
				 }
				 			 				 
			 }
			printf("%d\n",ino[r]);
		}
		

	}
	return 0;
}
