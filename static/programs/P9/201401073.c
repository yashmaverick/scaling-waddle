//a program to dispaly given bags of varying weights in sorted order
//created by dipankar jain
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define endl printf("\n")
#define tab printf("\t")
#define maxbags 1001

int mod;
int n;
int **array;
int modsum[maxbags];
int indexbags[maxbags];
int numbags[maxbags];

void sortweights(int first,int last);

int main()
{
	int i,j,m;
	gi(n);
	gi(mod);
	array = (int **)malloc(n*sizeof(int *));
	for( i=0 ; i<n ; i++ )
	{
		int sum=0;
		indexbags[i] = i;
		gi(m);
		numbags[i] = m;
		array[i] = (int *)malloc(m*sizeof(int));   //dynamically allocating an array
		for( j=0 ; j<m ; j++ )
		{
			gi(array[i][j]);
			sum = (sum%mod + array[i][j]%mod)%mod;
		}
		modsum[i] = sum;
	}
	sortweights(0,n-1);
	for( i=0 ; i<n ; i++ )
	{
		pi(modsum[i]);endl;
		for( j=0 ; j<(numbags[indexbags[i]]) ; j++ )
		{
			printf("%d",array[indexbags[i]][j]);			
			endl;
		}
		endl;
	}
	return 0;
}

void sortweights(int first,int last)
{
	int x,index,start,temp;
	if(first >= last)
		return ;
	x = last;
	start = first-1;
	for(index = first; index<last; index++)
	{
		if((modsum[index])<=(modsum[x]))
		{
			start++;
			temp = (modsum[start]);
			(modsum[start]) = (modsum[index]);
			(modsum[index]) = temp;
			temp = (indexbags[start]);
			(indexbags[start]) = (indexbags[index]);
			(indexbags[index]) = temp;
		}
	}
	temp = modsum[start+1];
	modsum[start+1] = modsum[last];
	modsum[last] = temp;
	temp = indexbags[start+1];
	indexbags[start+1] = indexbags[last];
	indexbags[last] = temp;
	x = start + 1;
	sortweights(first,x-1);
	sortweights(x+1,last);
	return ;
}

