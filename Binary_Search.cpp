/*
This is a simple C++ program to demonstrate the working of a Binary Search ALgorithm 

Binary Seacrh Algorithm works in a sorted data structure

*/

#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[],int l,int r,int x) {		//BinarySearch function declared here

	while(l<=r) {			// while the left searching iterator does not crosses the right iterators

		int m=(l+r-1)/2;		//Calculating the middle element for the given l and r

		if(arr[m]==x) { 	//if the element is equal to the calculated mid
			return m;		// then the element is found
 		}

		if(arr[m]<x) {		//otherwise, if found less, we increase the left iterator
			l=m+1;
		}

		else {
			r=m-1;			//else, we decrease the right iterator
		}


	}

return -1; // else the element is not found

}


int main() {


int n;	///no. of elements in the array

cin>>n;


int a[n];//initialising the array


for(int i=0;i<n;i++) {
	cin>>a[i];	//input of the array elements
}

int p;

cin>>p; // element to be searched


int y=binarySearch(a,0,n-1,p); 	//calling the binary search fuction

cout<<y;


	return 0;
}