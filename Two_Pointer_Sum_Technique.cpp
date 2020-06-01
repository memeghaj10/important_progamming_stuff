/*
This is a simple CPP program to find out if there exists a pair of numbers in the first N numbers of the array with 
Sum equal to X.

MOTIVE IS TO STUDY ABOUT THE TWO POINTER TECHNIQUE.

The time complexity of the below Algorithm is O(n).

Also, this algorithm is applicable to only sorted arrays.

*/

#include<bits/stdc++.h>

using namespace std;

int isPairSum(int a[],int n,int x) {

		int i=0;

		int j=n-1;

		while(i<j) {

			if(a[i]+a[j]==x) {
				return 1;
			}

			else if(a[i]+a[j]<X) {
				i++;
			}

			else {
				j--;
			}
		}

	return 0;
}


int main() {

	int n;

	cin>>n;

	int a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	sort(a,a+n);

	int x;

	cin>>x;


	if(isPairSum==1) {
		cout<<"YES";
	}

	else {
		cout<<"NO";
	}


	return 0;
}