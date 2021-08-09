

/*
You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. 

*/










#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

bool comparator(struct val a,struct val b) {
    return a.second<b.second;
}

int maxChainLen(struct val p[],int n)
{
   sort(p,p+n,comparator);

    int l=1;
    
    int s=p[0].second;
    
    for(int i=1;i<n;i++) {
        if(s<p[i].first) {
            l++;
            s=p[i].second;
        }
    }
    
    
    return l;


}