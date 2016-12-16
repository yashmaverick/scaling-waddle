#include<stdio.h>
#include<string.h>
struct tree{
	long long int n[100001];
	long long int top;
	long long int dep[100001];
};
typedef struct tree stack;

//stack s;

/*void push(long long int i)
{   
        s.top++;
        s.n[s.top] = i;   
    return;
}
void pop ()
{
        s.top = s.top - 1;
    return;
}*/

int main()
{
	long long int t,i;
	long long int temp;
		long long int n;
		long long int node[100001];
	scanf("%lld",&t);
	stack s;
	while(t--)
	{	
		
		for(i=0;i<100001;i++)
			s.dep[i]=-1;
		s.top=-1;
		scanf("%lld",&n);
		//printf("ckjdj\n");
		for(i=n-1;i>=0;i--)
			scanf("%lld",&node[i]);
		//printf("cbdfj\n");
		long long int d=0;
		for(i=0;i<n;i++)
		{
			if(s.top==-1||node[i]>s.n[s.top])
				{	
					//push(node[i]);
					s.top++;
        			s.n[s.top] = node[i];  
					//printf("%d\n",s.n[s.top]);
					s.dep[node[i]]=d;
					d++;
					//printf("&&%lld\n",d );
					//printf("%lld\n",s.dep[node[i]]);
				}
			else
			{	
				//printf("dhjbs\n");
				while(s.n[s.top]>node[i]&&s.top!=-1)
				{	
					//printf("bhdf\n");
					s.top--;
				}
				//printf("%lld\n",s.top);
				temp=s.dep[s.n[s.top+1]];
				//printf("%d\n",s.dep[s.n[s.top+1]] );
				//pop();
				//printf("%lld\n", temp);
				s.dep[node[i]]=temp+1;
				s.top++;
				s.n[s.top]=node[i];
				d=temp+2;
			}
		}
		temp=-1;
		long long int ind=-1;
		for(i=0;i<100001;i++)
		{	//printf("%d\n",s.dep[i]);
			if(temp<s.dep[i])
				{	
					//printf("%d\n",s.dep[i] );
					temp=s.dep[i];
					ind=i;
				}
		}
		printf("%lld %lld\n",ind,temp);
		s.top=-1;
	}
	return 0;
}