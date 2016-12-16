#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	char data;
	struct t* p[10];
	int yorn;
}branch;
typedef branch* br;
int flag;
int cmpf(const void* a,const void* b)
{
	return (*(long long int*)a-*(long long int*)b);
}
br ins(char* b2,br root)
{
	br temp;br arb;arb=root;
	int i=0;int j;int k;
	while(b2[i]!='\0')
	{
		if(arb->p[b2[i]-'0']==NULL)
		{
			temp=(br)malloc(sizeof(branch));
			temp->data=b2[i];
			temp->yorn=0;
			for(j=0;j<10;j++)
			{
				temp->p[j]=NULL;
			}
			arb->p[b2[i]-'0']=temp;
			arb=temp;
		}
		else
		{

			arb=arb->p[b2[i]-'0'];
			if(arb->yorn==1)
			{
				printf("NO\n");
				flag=1;
				return root;
			}
		}
		i++;
	}
	arb->yorn=1;
	for(k=0;k<10;k++)
	{
		if(arb->p[k]!=NULL)
		{printf("NO\n");
		flag=1;
		return root;}
	}
	return root;
}
/*void f(long long int e,int b1[],int b2[])
{
	int x,i;int cnt=0;
	while(e>0)
	{
		x=e%10;
		b1[cnt++]=x;
		e=e/10;
	}
	for(i=0;i<cnt;i++)
	{
		b2[i]=b1[cnt-1-i];
	}
	b2[i]=-1;
}*/
int main()
{
	int t,n,i,j,k;
	br root;int l;
	root=(br)malloc(sizeof(branch));
	//int b1[11];
	//int b2[11];
	char* arr[1000000];
	scanf("%d",&t);
	while(t>0)
	{
		l=0;
		for(i=0;i<10;i++)
		{
			root->p[i]=NULL;
		}
		flag=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			arr[i]=(char*)malloc(11*sizeof(char));
			scanf("%s",arr[i]);
		}
//		qsort(arr,n,sizeof(long long int),cmpf);
		/*for(i=0;i<n;i++)
		{
			printf("%lld ",arr[i]);
		}
		printf("\n");*/
		for(i=0;i<n;i++)
		{
			//f(arr[i],b1,b2);
		/*	l=0;
			while(b2[l]!=-1)
			{
				printf("%d ",b2[l]);
				l++;
			}
			printf("\n");*/
			root=ins(arr[i],root);
			if(flag==1)
			{
				break;
			}
		}
		if(flag==0)
		{
			printf("YES\n");
		}
		t--;
	}
	return 0;
}




