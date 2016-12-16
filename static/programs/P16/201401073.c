//a program to find the diameter of a given unweighted binary tree
//coded by dipankar jain

#include<stdio.h>
#include<math.h>

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define endl printf("\n")
#define tab printf("\t")
#define sp printf(" ")

int main()
{
	int t;
	gi(t);
	while(t--)
	{
		int qi,depth1,temp,logarithm=0,minelement,divide;
		gi(qi);
		temp = qi;
		while(temp != 0)
		{
			temp>>=1;
			logarithm+=1;
		}
		depth1 = logarithm - 1;
		minelement = pow(2,depth1);
		divide = minelement/2 + minelement;
		if(qi >= divide)
			pi(2*depth1);
		else
			pi(depth1 + depth1 - 1);
		endl;
	}
	return 0;
}
	
