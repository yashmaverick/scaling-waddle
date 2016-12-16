#include<stdio.h>
//long long int total[1001];
//long long int index[1001];
//long int temp[1001];
void selection_sort(int total[],int index[],int n);
int main()
{ int n,m,mod,stack[1000000],bottom=0,top=0,i,j;
	scanf("%d %d",&n,&mod);
        int total[n],index[n],index_of_total[n];
	for(i=0;i<n;i++)
	{ total[i]=0;
	}
	for(i=0;i<n;i++)
	{ scanf("%d",&m);
          bottom=top;
	  //stack[bottom]=m;
	  top++;
	  for(j=0;j<m;j++)
	  { scanf("%d",&stack[top]);
		  top++;
	  }
	  for(j=bottom+1;j<top;j++)
	  { 
		stack[bottom]=((stack[j]%mod)+stack[bottom])%mod;
	  }
	  //stack[bottom]=(stack[bottom]%mod);
	  total[i]=stack[bottom];
	  index_of_total[i]=bottom;
	  index[i]=i;
	}
//	for(i=0;i<n;i++)
//		printf("%lld ",index[i]);
/*	for(i=0;i<n;i++)
	{ printf("%lld ",total[i]);
	}
        printf("\n");*/
	selection_sort(total,index,n);
	/*for(i=0;i<n;i++)
		printf("%lld ",index[i]);
	  //for(i=0;i<n;i++)
	  printf("total\n");
          for(i=0;i<n;i++)
	  { printf("%lld ",total[i]);
	  }*/
	/*  printf("\n");
	  printf("index\n");
	  for(i=0;i<n;i++)
	  { printf("%ld ",index[i]);
	  }
	  printf("\n");
	  printf("index of total\n");
	  for(i=0;i<n;i++)
	  { printf("%ld ",index_of_total[i]);
	  }*/
	 /* printf("\n");
	  printf("stack\n");
	  for(i=0;i<top;i++)
	  { printf("%lld ",stack[i]);
	  }
	  printf("\n");
//	  printf("%ld\n",top);*/
	  for(i=0;i<n;i++)
	  { printf("%d\n",total[i]);
		  if(index[i]==n-1)
		  { for(j=index_of_total[index[i]]+1;j<top;j++)
			  { printf("%d\n",stack[j]);
			  }
			  
		    printf("\n");
		  }
		  else if(index[i]!=n-1)
			  { for(j=index_of_total[index[i]]+1;j<index_of_total[index[i]+1];j++)
				  { printf("%d\n",stack[j]);
				  }
			    printf("\n");
			  }
	           //printf("\n");
	  }
			return 0;
}
void selection_sort(int a[],int b[],int n)
{ //printf("sort\n");
	int i,j;
	for(i=0;i<n-1;i++)
	{ for(j=i+1;j<n;j++)
		{ if(a[i]>a[j])
			{ a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
			         a[i]=a[i]-a[j];
				b[i]=b[i]+b[j];
				b[j]=b[i]-b[j];
				b[i]=b[i]-b[j];
			}
		}
               //printf("%ld %ld %ld %ld\n",total[i],total[j],index[i],index[j]);
	}
}

	   
