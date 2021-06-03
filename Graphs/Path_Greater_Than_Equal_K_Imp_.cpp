/*

path, of path length greater than or equal to k,(without any cycle) starting from a given source and ending at any other vertex.
Source vertex should always be  0.

Example 1:

Input:
V = 4 , E = 3 and K = 8
A[] = [0, 1, 5, 1, 2, 1, 2, 3, 1]
Output: 0
Explanation:
There exists no path which has a distance 
of 8. 
 

Example 2:

Input:
V = 9, E = 14 and K = 60
A[] = [0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7, 
11, 2, 3, 7, 2, 5, 4, 2, 8, 2, 3, 4, 9, 
3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1, 6, 
8, 6, 7, 8, 7]
Output: 0


Your Task:  
You don't need to read input or print anything. Your task is to complete the function pathMoreThanK() which takes the integer V, Edges E, an integer K and Array A which is having (Source, Destination, Weight) as input parameters and returns 1 if the path of at least k distance exists, else returns 0.

Expected Time Complexity: O(N!)
Expected Auxiliary Space: O(N)

 

Constraints:
2 ≤ V ≤ 5
1 ≤ E ≤ 20
1 ≤ K ≤ 100



*/
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution {
public:

    bool back_track(int src,int k,vector<pair<int,int>> adj[],vector<int>& path) {
        
        if(k<=0) {
            return true;
        }
        
        //path[src]=1;
        
        for(auto x:adj[src]) {
            int v=x.first;
            int w=x.second;
            
            if(path[v]==1) {
                continue;
            }
            
            if(w>=k) {
                return true;
            }
            
            path[v]=1;
            
            if(back_track(v,k-w,adj,path)) {
                return true;
            }
            
            path[v]=0;
        }
        
        return false;
        
    }


    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       
       vector<pair<int,int>> adj[V];
       
       for(int i=0;i<3*E;i+=3) {
           adj[a[i]].push_back(make_pair(a[i+1],a[i+2]));
           adj[a[i+1]].push_back(make_pair(a[i],a[i+2]));
       }
       
       vector<int> path(V,-1);
       
       path[0]=1;
       
       //return 1;
       
       return back_track(0,k,adj,path);
       
    } 
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends