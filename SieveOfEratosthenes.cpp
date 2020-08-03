//This is a C++ program to find all prime numbers smaller than or equal to n using the Sieve Of Eratosthenes

#include<bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int n) {

	bool prime[n+1]; // initialising the boolean array to store the primality of the numbers

	memset(prime, true, sizeof(prime));// initialising all the array elements to True

	for(int p=2;p*p<=n;p++) {  
		if(prime[p]==true) { //if the number is prime then only we process it!
			for(int i=p*p;i<=n;i+=p) {   // we will now iterate forward only for those numbers greater than n*n as 
				prime[i]=false;           //the smaller ones will be cancelled out(false) by the numbers smaller than n
			}
		}
	}


	for(int p=2;p<=n;p++) {  
		if(prime[p]) {			// finally if in the boolean array the number has true stored for it, it will be printed.
			cout<<p<<" ";
		}
	}

}


int main() {

int n;

cin>>n; // taking in the number till which all the prime numbers are to printed
 
SieveOfEratosthenes(n); // calling out the function

return 0;
}