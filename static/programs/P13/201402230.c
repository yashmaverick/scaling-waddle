#include<stdio.h>
void find(int data,int fi,int la,int depth);
int maxdepth,minvalue;
int left_index[100005],a[100005];
int main()
{ int n,i,j,t;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d",&n);
		//int a[n],left_index[n];
		//for(i=0;i<n;i++)
		//{ scanf("%d",&a[i]);
		//}
		//int min=a[0];
		if(n>0)
		{scanf("%d",&a[0]);
		left_index[0]=-1;
		for(i=1;i<n;i++)
		{  scanf("%d",&a[i]);
			if(a[i]<=a[i-1])
			{
				j=i-1;
				while(left_index[j]!=-1 && a[j]>=a[i])

					j=left_index[j];
				if(a[j]<a[i])
					left_index[i]=j;
				else
					left_index[i]=-1;

			}

			else
				left_index[i]=i-1;
		}
		maxdepth=0;
		minvalue=a[n-1];          
		find(a[n-1],0,n-1,0);
//		for(i=0;i<n;i++)
//			printf("%d ",left_index[i]);
		}
		else 
		{	maxdepth=0;
			minvalue=0;
		}
		printf("%d %d\n",minvalue,maxdepth);
	}  
	return 0;
}
	void find(int data,int fi,int la,int depth)
{ 
//	printf("%d root\n",data);
	if(fi==la)
	{ 
//		printf("%d fi\n",fi);	
		if(maxdepth<depth)
		{
			maxdepth=depth;
			minvalue=a[fi];
		}
		//		if(maxdepth==depth && minvalue>a[fi])
		//		{ //if(minvalue>a[fi])
		//			minvalue=a[fi];
		//		}
//		 printf("%d --depth %d---value\n",maxdepth,minvalue);
		return;
	}
	else
	{ 	
//		printf("%d fi--- %d la----\n",fi ,la);
		if(a[la]>a[la-1] && la>=1)
		{ 
//			printf("only left\n");
//			printf("left_index:%d num:%d\n",left_index[la],a[left_index[la]]);	
//			printf("%d --depth\n\n",depth);
			find(a[left_index[la]],fi,left_index[la],depth+1);
		}
		else if(a[la]<a[la-1] && la>=1 && left_index[la]!=-1 && left_index[la]>=fi)
		{ 	//printf("both\n");
			//printf("left_index:%d num:%d\n",left_index[la],a[left_index[la]]);			
			//printf("%d --depth\n\n",depth);
			find(a[left_index[la]],fi,left_index[la],depth+1);
			find(a[la-1],left_index[la]+1,la-1,depth+1);
		}
		else if(a[la]<a[la-1] && left_index[la]==-1 && la>=1)
		{      
		//	printf("only right\n");
		  //     	printf("left_index:%d num:%d\n",left_index[la],a[left_index[la]]);
		//	printf("%d --depth\n\n",depth);
				find(a[la-1],left_index[la]+1,la-1,depth+1);
		}
		else if(a[la]<a[la-1] && left_index[la]!=-1 && la>=1 && left_index[la]<fi)
			find(a[la-1],fi,la-1,depth+1);
	}
}

