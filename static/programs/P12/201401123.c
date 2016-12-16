#include<stdio.h>
#include<stdlib.h>
typedef long long int L;
#define s(n) scanf("%lld",&n)

typedef struct nn{
	L value;
	L ic;
	struct nn *next;
}nn;
typedef nn* np;

np head;


void push(L x)
{
	np temp;
	temp = (np)malloc(sizeof(nn));
	temp->value = x;
	temp->next = head;
	head = temp;
}
void pop()
{
	if(head!=NULL)
	{
		np temp;
		temp = head->next;
		free(head);
		head = temp;
	}
	else
		return;
}
int peek()
{
	return head->value;
}

int main()
{
	L a[500001];//visited[500001];
	L i,n,j, count;
	L ans, flag,top;
	//L loop;
	while(1)
	{
		s(n);
		if(n==0)
			break;
		else
		{
			while(head!=NULL)
				pop();
			nn q[n];
			for(i=0;i<n;i++)
			{
				s(a[i]);
			}
			ans = ((n * (n-1))/2);

			count = 0;
			L c; 
			top = -1;
			//push(a[0]);
			c=0;
			for(i=0;i<n;i++)
			{
				if(head==NULL && top == -1)
				{
					push(a[i]);
					q[++top].ic=0;
				}
				else
				{
					while(head!=NULL && a[i]>peek())
					{
						pop();
						top-=1;count++;
					}
					top+=1;
					//push(a[i]);
					if(top!=0)
					{
						if(a[i]==peek())
							q[top].ic=q[top-1].ic+1;
						else
							q[top].ic=1;
					}
					else
						q[top].ic = 0;
					count = count + q[top].ic;
					push(a[i]);
				}
			}
			ans = ans - count;
			printf("%lld\n",ans);
		}
	}
	return 0;
}

					


					/*		for(i=1;i<n;i++)
							{
							if(a[i] < peek())
							count = 0;
							if( a[i] <= peek() )
							{
							push(a[i]); 
							count++;
							}
					//printf("%d\n",count);
					if(a[i] > peek())
					{
					loop=0;
					while(head!=NULL && a[i]>peek())
					{
					if(head->next!=NULL && head->next->value >= peek())
					{
					count++;
					pop();
					}
					if(head->next!=NULL && head->next->value < peek())
					{

					}


					}
					push(a[i]);
					}
					c=c+count;
					//printf("count = %d\n c = %d\n ",count,c);
					}
					ans = ans - c;
					printf("%d\n",ans);
					}
					}
					return 0;
					}*/
					/*			
								while(i<n)
								{
								if(a[i] > peek())
								{
								if((i-j)!=1)
								count++;
								pop();
								push(a[i++]);
								j = i-1;
								}
								else if((i-j)!=1)
								{
								count++;
								i++;
								}
								else
								i++;
								}
								ans = ans - count;
								printf("%d\n",ans);
								}
								}
								return 0;
								}
								*/





/*	else
	{
	for(i=0;i<n;i++)
	s(a[i]);
	ans = 0;
	for(i=0;i<n-1;i++)
	{
	push(a[i]);
	j=i+1;
	flag = 0;
	while(j<n)
	{
	if((head == NULL || a[j] > peek()) && flag!=1)

	if(head!=NULL)
	pop();
	push(a[j++]);
	flag=1;
	}
//else if(flag!=1 && a[j] < peek())
//	{
//		ans++;
//		j++;
//	}
else if(flag==1)
{
ans++;
j++;
}
else
j++;
}
while(head!=NULL)
pop();
}
printf("%d\n",ans);
}
}
return 0;
}*/
