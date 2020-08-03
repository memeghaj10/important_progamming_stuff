/*
This is a CPP code to determine the longest common subsequence, given two strings, using 
Dynamic Programming 
*/

#include<bits/stdc++.h>

using namespace std;


int lcs(string a,string b,int m,int n) {		//function to calculate the longest common subsequence

int l[m+1][n+1];		//initialsing the DP array

for(int i=0;i<m;i++) {		
	for(int j=0;j<n;j++) {
		if(i==0||j==0) {
			l[i][j]=0;		//intitialsing the base condition for every character of the string = 0
		}

		else if(a[i-1]==b[j-1]) {
			l[i][j]=l[i-1][j-1]+1; 		//if the characters of the string match, we increement the element of the matrix +1 to the sum of the previous diagonal element
		}

		else {
			l[i][j] = max(l[i-1][j],l[i][j-1]);		//else we take the maximum of the two numbers at its top and to its left
		}
	}
}


return l[m][n]; 	//returning the last element of the matrix, denoting the count of the LCS


}

int max(int c,int d) {
	return c>d?c:d;		//function to compare two elements(integers)
} 

int main() {

string a;
string b;

cin>>a>>b;	// taking user input of the two strings

cout<<"Length of the longest common subsequence is "<<lcs(a,b,a.length(),b.length());

	//printing the LCS of the two strings

	return 0;
}