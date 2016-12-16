#include<stdio.h>
int main()
{
	int i,t;
	int my_var=0;
	int input=0;
	int p,q,r;
	int j,k;
	scanf("%d",&t);
	if(my_var==0)
	{
		input++;
	}
	else
	{
		input=input+2;
	}
	for(i=0;i<t;i++)
	{
		scanf("%d",&p);
		long int a[p];
		long int answer=0;
		if(my_var==0)
		{
			for(j=0;j<p;j++)
			{
				scanf("%ld",&a[j]);
			}
		}
		else
		{
			input++;
		}
		scanf("%d",&q);
		long int first[q];
		long int second[q];
		long int third[q];
		if(my_var==0)
		{
			for(j=0;j<q;j++)
			{
				scanf("%ld",&first[j]);
				second[j]=0;
				third[j]=0;
			}
		}
		else
		{
			input=input+2;
		}
		scanf("%d  ",&r);
		long int c[r];
		if(my_var==0)
		{
			for(j=0;j<r;j++)
			{
				scanf("%ld",&c[j]);
			}	
		}
		else
		{
			input++;
		}
		int z=r-1;
		for(j=q-1;j>=0;j--)
		{
			if(my_var==0)
			{
				for(k=z;k>=j;k--)
				{
					if(first[j]>c[k])
					{
						second[j]=r-k-1;
						z=k;
						break;
					}
					if(k==j)
					{
						second[j]=r-j;
						z=j;
						break;
					}

				}
			}
			else
			{
				input++;
			}
		}
		third[q-1]=second[q-1];
		if(my_var==0)
		{
			for(j=q-2;j>=0;j--)
			{
				third[j]=second[j]+third[j+1];
			}
		}
		else
		{
			input++;
		}
		z=q-1;
		for(j=p-1;j>=0;j--)
		{
			if(my_var==0)
			{
				for(k=z;k>=j;k--)
				{
					if(my_var==0)
					{
						input++;
					}
					if(a[j]>first[k])
					{
						if(k<q-1)
						{
							if(my_var==0)
							{
								input++;
							}
							answer=answer+third[k+1];
						}
						else
						{
							if(my_var==0)
							{
								input=0;
							}
							answer=answer;
						}
						z=k;
						break;
					}
					if(k==j)
					{
						if(my_var==0)
						{
							input++;
						}
						answer=answer+third[j];
						z=j;
						break;
					}		
				}
			}
			else
			{
				input++;
			}
		}
		printf("%ld\n",answer);
	}
	return 0;
}
