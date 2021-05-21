#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    int inf=100000000;
	    vector<int> dist(n,inf);
	    
	    dist[0]=0;
	    
	    for(int i=0;i<n-1;i++) {
	        for(auto x:edges) {
	            if(dist[x[0]]+x[2]<dist[x[1]]) {
	                dist[x[1]]=dist[x[0]]+x[2];
	            }
	        }
	    }
	    
	    int fl=0;
	    
	    for(auto x:edges) {
	        if(dist[x[0]]+x[2]<dist[x[1]]) {
	            return 1;
	        }
	    }
	    
	    return 0;
 	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends