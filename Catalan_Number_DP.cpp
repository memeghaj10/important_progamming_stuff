/*

A simple CPP program that will show the use of Dynamic Programming in Calculating the nth catalan number.

*/


#include<bits/stdc++.h>

using namespace std;



unsigned long int catalanDP(unsigned int n) {  //function to find hte nth catalan number

	unsigned long int catalan[n+1];		//declaring the catalan array


	catalan[0]=catalan[1]=1;	//initialising the 1st and the 2nd catalan number

	for(int i=2;i<=n;i++) {
		catalan[i]=0;			// initialising the ith catalan number 
		for(int j=0;j<i;j++){ 
			catalan[i]+=catalan[i]*catalan[i-j-1]; //calculating the adding the sum to the catalan number 
			}
	}


	return catalan[n]; 			//returning the nth catalan number 
}




int main() {


int p;

cin>>p;

for(int i=0;i<p;i++) {
	cout<<catalanDP(i)<<" ";	//calling the function of CatalanDP for all numbers in till p.
}

	return 0;
}