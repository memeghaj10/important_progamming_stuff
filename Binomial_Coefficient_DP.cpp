/*
This CPP program is used for calculating  C(n,k) or Binomial Coefficient Using Dynamic Programming.

This can also be used to find the no. of k-sized elements sets that can be formed out of a set of size n.

*/


#include<bits/stdc++.h>

using namespace std;


int binocoeff(int n,int k) {	//function to calculate the C(n,k) the binomial coefficient

	int c[n+1][k+1]=0;		//declaring a matrix of size(n+1,m+1)

	for(int i=0;i<=n;i++) {			// traversing all the n(s)
		for(int j=0;j<=min(i,k);i++) {		// traversing all j(s) less than n, or for which C(n,j) can be calculated
			if(j==0||i==j) {		// if the traversal reaches the first column, where the expression looks like C(n,0) => the answer is '1'
				c[i][j]=1;	
			}

			else {
				c[i][j]=c[i-1][j-1]+c[i-1][j];	// else we use the technique, [C(n,k) = C(n-1,k-1)+C(n-1,k)]
			}
		}
	}



	return c[n][k];		// then at the end we return the C(n,k);
}


int main() {

	int n,k;

	cin>>n>>k;		// asking the user to input the n,k (to be calculated).

	cout<<"C(n,k) is "<<binocoeff(n,k);		// calling the function, to calculate C(n,k)


	return 0;
}