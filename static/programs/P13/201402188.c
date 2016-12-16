#include<stdio.h>
#include<stdlib.h>



int binary(int p[],int m,int first,int last)
{
	int middle=(last+first)/2;

	while( first <= last )
	{
		if ( p[middle] < p[m] )                        
			first = middle + 1;
		else if ( p[middle] == p[m] )
		{
			//printf("%lld found at location %lld.\n", post[m], middle+1);
			break;
		}
		else
			last = middle - 1;

		middle = (first + last)/2;
	}
	int j;
	if ( first > last )
		 j=last;
	return j;
}

int a[100000],max=0,no=0;
void aman(int i,int j,int count)
{
	if(i==j)
	{
		if(count>max)
		{
			max=count;
			no=a[i];
		}
		else if(count==max)
		{
			if(a[i]<no)
				no=a[i];
		}
	}
	else
	{
		int v;
		/*while(a[v]>=a[i] && v>=j)
		{
			v--;
		}*/
		v=binary(a,i,j,i-1);
	//	printf("v:%d,i:%d,j:%d\n",v,i,j);
		if(v+1<i)
		{
			//	printf("in 1 - i-1:%d,v+1:%d\n",i-1,v+1);
			aman(i-1,v+1,count+1);
		}
		if(v>=j)
		{
			//	printf("in 2 - v:%d,j:%d\n",v,j);			
			aman(v,j,count+1);
		}


	}

}
/*void inorder(node* root)
  {
  if(root==NULL)
  return ;
  inorder(root->left);
  printf("%d ",root->val);
  inorder(root->right);
  }
 */
int main()
{
	int jaa,test;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		int n,i;
		max=0,no=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int count=0;
		aman(n-1,0,count);
		//inorder(root);
		//printf("max:%d,no:%d\n",max,no);
		printf("%d %d\n",no,max);
	}
	return 0;
}




