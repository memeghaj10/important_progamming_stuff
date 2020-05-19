/*
The problem statement is:-
Given an array of positive integers, find out if the sum of any two fibonacci elemnts is fibonacci or not.
*/



#include<bits/stdc++.h>
#define MAX 100005
#define ll long long int

using namespace std;

set<ll> fibonacci; //declaring a set to store the fiboncacci numbers 

void createhash() {  //function to create the fibonacci series in the set
	int prev=0;  //initialising the 1st fibo.  number
	int curr=1;  //initialising the second fibo. number
	while(curr<=MAX) {  // while the max limit has not been reached
		int temp=curr+prev;  // inserting he sum of the prev. 2 numbers
		fibonacci.insert(temp); 
		prev=curr; // the 2nd number becomes the 1st
		curr=temp; // while the inserted number becomes the 2nd number
	}
}


bool checkArray(int a[],int n) {	//function to check if the array contains the required sum
	ll sum=0;			// initialsing the sum

	for(int i=0;i<n;i++) {
		if(fibonacci.find(a[i])!=fibonacci.end()) {		//checking if the number itself is fibonacci or not
			sum+=a[i];									// if yes then adding it to the sum

			if(fibonacci.find(sum)!=fibonacci.end()) { // checking if the sum is fibonacci or not
				return true;			// if "yes" then true is returned
			}

		}
	}

	return false;  		// else we exit the loop and false is returned

}


int main() {

int n ;		// input the size of the array to be checked

cin>>n;		

int a[n];		//initialising the array

for(int i=0;i<n;i++) {
	cin>>a[i];		// taking the number inputs as array elemnents
}

if(checkArray(a,n)) {		// if the function returns TRUE, then the anwer is "YES"
	cout<<"YES";
}

else {
	cout<<"NO";		// else the output is "NO"
}

	return 0;
}
