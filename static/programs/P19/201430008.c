#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int val;
	struct node * chldrn[10];
}node;
int main(){
	long long int t,n;
	int q;	

	scanf("%lld",&t);
	for(q=0;q<t;q++)
	{
char a[20];		
int flag=0;
int i,j;
scanf("%lld",&n);
		node *temp1 = (node*)malloc(sizeof(node));
		temp1 -> val= 0;
		long long int num,r,t;
		node* temp = temp1;
	
				int l;
		
for(i=0;i<n;i++)
		{
			scanf("%s",a);			
temp = temp1;
l=0;
while(a[l]!='\0')
l++;	
	
			if(flag == 0)
			{
				j=0;
				while(j < l){
					r = a[j]-'0';

					if(temp->chldrn[r]!=NULL)
					{
						temp = temp->chldrn[r];
						if(j == l-1)
						{
							flag = 1;
									break;
						}
						else if(temp->val == -1){
							flag = 1;
							break;
						}
					}


else
{
  temp->chldrn[r] = (node *)malloc(sizeof(node));
                                                temp->chldrn[r]->val = 0;
                                                temp = temp->chldrn[r];
                                                if(j == l-1)
                                                {
                                                        temp->val = -1;

                                                        break;




}
}
j++;

				}
			}
		}

		if(flag == 1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
}	
	return 0;
}
