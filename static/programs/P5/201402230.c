#include<stdio.h>
int main()
{ int t;
	scanf("%d",&t);
	while(t--)
	{ int n,k,i,j,l,num,flag=0;
		scanf("%d %d",&n,&k);
		char a[1001];
		int b[1001];
		for(i=0;i<n;i++)
		 //for(j=0;j<2;j++)
                 { scanf("%s %d",a,&b[i]);
                 }
                // b[i]=a[i][1];
		
		for(i=1;i<n;i++)
		{ num=b[i];
			j=i-1;
			while(num<b[j] && j>0)
			{ b[j+1]=b[j];
				j--;
			}
			b[j+1]=num;
		}
		for(i=0;i<n;i++)
		{ j=i+1;
			l=n-1;
                        flag=0;
			while(j<l)
			{ if(b[i]+b[j]+b[l]==k)
				{ printf("YES\n");
					flag=1;
					break;
				}
				if(b[i]+b[j]+b[l]<k)
					j++;
				if(b[i]+b[j]+b[l]>k)
					l--;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

