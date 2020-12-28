/*
To learn more about Dynamic Programming, I have used it to find the nth Fibonacci Number!
*/

#include<bits/stdc++.h>

using namespace std;

int fib(int n) { //function to find the nth fibonacci number;
	int f[n+2];  //initialsing the th fibonacci number array
	int i;		//initialising the iterator		

	f[0]=0;		// initialising the first number of the fibonacci array
	f[1]=1;    	//initialising the secon number
	for(i=2;i<=n;i++) {
		f[i]=f[i-1]+f[i-2];	//calculation of the the next fibonacci number
	}


	return f[n];		// returning the nth fibonacci number, from the array
}



int main() {

int n;	


cin>>n;		//input the nth fibonacci number

int p=fib(n); 	//calling the fibonacci function and storing the result


cout<<p;	//output the result



	return 0;
}