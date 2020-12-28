/*
This is a CPP program that solves the given probelm using Dynamic Programming :-

Given a non-emnpty set of integers, and a target sum for which it has to be proven if the sum can achieved by the sum of 1 or more elements from the set.

*/


#include<bits/stdc++.h>


using namespace std;


bool isSubsetSum(int set[],int n,int sum) {

	bool subset[n+1][sum+1];	//initialsiing a boolean matrix of size [size(Array)][1...(requiredSum)]

	for(int i=0;i<n;i++) {
		subset[i][0]=true;	//if the sum==0, then its is true for all.
	}

	for(int i=1;i<=sum;i++) {
		subset[0][i]=false;		// if the set is empty, the condition becomes false
	}

	for(int i=1;i<=n;i++) {		//filling the table in bottom-up manner
		for(int j=1;j<=sum;j++) {
			if(j<set[i-1]) {		
				subset[i][j]=subset[i-1][j];	//if the current sum is less than the current element, we copy the previous result
			}
			if(j>=set[i-1]) {		// else, we move (sum-element) columns backs in the previous row and check for the answers at that place, and copy the same.
				subset[i][j]=max(subset[i-1][j-set[i-1]],subset[i-1][j]);
			}
		}
	}


	return subset[n][sum];  //atlast we return the last element of the table....(bottom right corner)


}


int main() {


int n;

cin>>n;	//no. of elements in the table


int a[n];


for(int i=0;i<n;i++) {
	cin>>a[i]; 		// input of the array elements
}


int sum;

cin>>sum;	// initialising the sum

if(isSubsetSum(a,n,sum)==true) {			// calling the isSubsetSum function
	cout<<"YES, there exists such a subset";
}		

else {
	cout<<"NO, could not find such a subset";
}


	return 0;
}