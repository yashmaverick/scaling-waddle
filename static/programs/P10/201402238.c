#include<stdio.h>
#include<string.h>
char c,s[10005][105];
int main()
{       int n,a,i=0,j=1,x=0,k;
	scanf("%d",&n);
	n--;
	//i at last element
	//j at latest element
	while(1)
	{ if(x==0)
		{i=0;j=1;} 
		scanf("%c",&c);
		if(c=='A')
		{       scanf("%d",&a);
			while(a-- && n>=0)
			{  i++;x++;
				if(x>n+1)
					x=n+1;
				i=i%(n+1);
				if(j==i&&x!=1)
					j++;
				j=j%(n+1); 

				scanf("%s",s[i]);
				//                                    printf("%s %d %d %d\n",s[i],i,j,x);
			}
		}        
		else if(c=='R'  && n>=0)
		{       scanf("%d",&a);
			x=x-a;
			j+=a;
			//             printf("%d %d\n",x,j);
			j=j%(n+1);       

		}                        
		else if(c=='L'  && n>=0)
		{            if(j>i&&x!=0)
			{       for(k=j;k<=n;k++)
				printf("%s\n",s[k]);
				k=0;
				for(k=0;k<=i;k++)          
					printf("%s\n",s[k]);
			}  
			else if(j<=i&&x!=0)
			{       for(k=j;k<=i;k++)
				printf("%s\n",s[k]);
			}
		}
		else if(c=='Q')
			break;
	}
	return 0;
}
