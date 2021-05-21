#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
    bool isValid(int x,int y,int N) {
        
        return x>=1&&x<=N&&y>=1&&y<=N;
        
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>& K,vector<int>& T,int N)
	{
	    int row[]={2,2,-2,-2,1,1,-1,-1};
	    int col[]={-1,1,-1,1,-2,2,-2,2};
	    
	    int srcX=K[0];
	    int srcY=K[1];
	    int destX=T[0];
	    int destY=T[1];
	    
	    //cout<<srcX<<" "<<srcY<<endl;
	    
	    bool visited[N][N]={false};
	    
	    
	    queue<pair<pair<int,int>,int>> q;
	    q.push(make_pair(make_pair(srcX,srcY),0));
	    
	    while(!q.empty()) {
	        
	        int currX=q.front().first.first;
	        int currY=q.front().first.second;
	        
	        int currD=q.front().second;
	        
	        q.pop();
	        
	        if(currX==destX&&currY==destY) {
	            return currD;
	        }
	        
	        if(!visited[currX-1][currY-1]) {
	            visited[currX-1][currY-1]=true;
	            
	             for(int i=0;i<8;i++) {
	                 int x1=currX+row[i];
	                 int y1=currY+col[i];
	                 
	                 if(isValid(x1,y1,N)) {
	                   
	                         q.push(make_pair(make_pair(x1,y1),currD+1));

	                 }
	             }
	            
	        }
	    }
	    
	    
	    return -1;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends