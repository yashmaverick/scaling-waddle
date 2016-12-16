#include<stdio.h>
#include<stdlib.h>
typedef struct tri
{
	int val;
	struct tri *arr[10];
}tri;
int main()
{
	int t,i,n;
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
		tri *head= (tri *)malloc(sizeof(tri));head->val=-5;
		tri *itr;itr=head;
		scanf("%d",&n);getchar();
		int j,a,b,d,c,flag;flag=0;
		for(j=0;j<n;j++)
		{
		        a=0;
			itr=head;
			while(1)
			{
				//printf("p%do\n",itr->val);
				c=getchar();
				if(c=='\n')
				{
					itr->val=4;
					break;  
				}
				c=c-'0';
				if(itr->arr[c]==NULL)
				{
					itr->arr[c]=(tri *)malloc(sizeof(tri));
					a=1;
				}
				itr=itr->arr[c];
				if(itr->val==4 && a==0)
				{
					flag=1;
				}
			}
			//printf("p %d p\n",flag);
			if(a==0)
				flag=1;
		}
		if(flag==1)
			printf("NO\n");
		else if(flag==0)
			printf("YES\n");
	}
	return 0;
}


