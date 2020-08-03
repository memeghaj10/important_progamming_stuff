/*

This is an algorithm I thought of while trying to solve a problem during a CodeForces contest,but couldn't implement.

This algorithm uses a searching string and a query string that has to be searched in the searching string, and the minimum length of the window of the searched string has to be found out!

This code is yet to be completed!!!!!!!!!!!!!!!!!

*/


#include<bits/stdc++.h>

using namespace std;

	
int minseacrhwindow(string s,string q) {

	int r=0,l=0;

	int h=q.length();

	vector<int> v;

	while(r<s.length()) {
		int p=r;
		for(int i=0;i<h;i++) {
			if(count(s.begin()+l,s.begin()+r,q[i])>0) {
				continue;
			}

			else {
				r++;
				break;
			}
		}

		if(r==p) {
			v.eb(r-l+1);
		}


		else {
			int a=l+1;
			int f=0;
			
			while(l<r-h) {
				for(int i=0;i<h;i++) {
				if(count(s.begin()+l,s.begin()+r,q[i])>0) {
							continue;
							}
				else {
						v.eb(r-l+1);
						f=1;
						break;					
					}

				}


				if(f==1) {
						break;
					}

				l++;
			}
		}



	}

	sort(v.begin(),v.end());

	return v[0];


}


int main() {


	string s;


	cin>>s;


	string q;


	cin>>q;

	int y=minsearchwindow(s,q);


	cout<<y;

	return 0;

}	