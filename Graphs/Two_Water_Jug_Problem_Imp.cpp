/*

You are at the side of a river. You are given a m litre jug and a n litre jug where 0 < m < n. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d litres of water where d < n. Determine the minimum no of operations to be performed to obtain d litres of water in one of jug.
The operations you can perform are:

Empty a Jug
Fill a Jug
Pour water from one jug to the other until one of the jugs is either empty or full.
 

Example 1:

Input: m = 3, n = 5, d = 4
Output: 6
Explanation: Operations are as follow-
1. Fill up the 5 litre jug.
2. Then fill up the 3 litre jug using 5 litre
   jug. Now 5 litre jug contains 2 litre water.
3. Empty the 3 litre jug.
4. Now pour the 2 litre of water from 5 litre 
   jug to 3 litre jug.
5. Now 3 litre jug contains 2 litre of water 
   and 5 litre jug is empty. Now fill up the 
   5 litre jug.
6. Now fill one litre of water from 5 litre jug 
   to 3 litre jug. Now we have 4 litre water in 
   5 litre jug.
Example 2:

Input: m = 8, n = 56, d = 46
Output: -1
Explanation: Not possible to fill any one of 
the jug with 46 litre of water.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function minSteps() which takes m, n and d ans input parameter and returns the minimum number of operation to fill d litre of water in any of the two jug.


*/




#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	void  takeAction(int x,int y,int m,int n,vector<vector<int>>& visited,queue<pair<int,int>>& q) {
	 if(x>0 && !visited[0][y]) {q.push({0,y});visited[0][y]=1;}
	    if(y>0 && !visited[x][0]) {q.push({x,0});visited[x][0]=1;}
	    if(x<m && !visited[m][y]) {q.push({m, y});visited[m][y]=1;}
	    if(y<n && !visited[x][n]) {q.push({x, n});visited[x][n]=1;}
	    if(m-x>0 && y>0){
	        if(m-x>y && !visited[x+y][0]) {q.push({x+y, 0});visited[x+y][0]=1;}
	        else if(m-x<=y && !visited[m][y-(m-x)]) {q.push({m, y-(m-x)});visited[m][y-(m-x)]=1;}
	    }
	    if(n-y>0 && x>0){
	        if(n-y>x && !visited[0][y+x]) {q.push({0,x+y});visited[0][x+y]=1;}
	        else if(n-y<=x && !visited[x-(n-y)][n]) {q.push({x-(n-y), n});visited[x-(n-y)][n]=1;}
	    }
	    
	}
	
	
	int minSteps(int m, int n, int d)
	{
	    
	    int x,y;
	    vector<vector<int>> visited(m+1,vector<int>(n+1,0));
	    queue<pair<int,int>> q;
	    q.push({0,0});
	    visited[0][0]=1;
	    
	    int cntr=0;
	    
	    while(!q.empty()) {
	        
	        int sz=q.size();
	        
	        while(sz--) {
	            
	            x=q.front().first;
	            y=q.front().second;
	            q.pop();
	            
	            if(y==d||x==d) {
	                return cntr;
	            }
	            
	            this->takeAction(x,y,m,n,visited,q);
	            
	        }
	        
	        cntr++;
	    }
	    
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends