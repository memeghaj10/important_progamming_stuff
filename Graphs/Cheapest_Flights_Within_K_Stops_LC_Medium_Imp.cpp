/*

    There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

    You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    Output: 200
    Explanation: The graph is shown.
    The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
    Output: 500
    Explanation: The graph is shown.
    The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

*/





class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        queue<pair<int,int>> q;
        
        int no=flights.size();
        
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<no;i++) {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        q.push({src,0});
        
        vector<int> vis(n,-1);
        
        int steps=0;
        int result=INT_MAX;
        
        while(!q.empty()) {
            
            int h=q.size();
            
            for(int i=0;i<h;i++) {
                
                int node=q.front().first;
                int dist=q.front().second;
                
                q.pop();
                
                if(node==dst) {
                    result=min(result,dist);
                }
                
                for(auto x:adj[node]) {
                    
                    if(dist+x.second<=INT_MAX&&(vis[x.first]==-1||dist+x.second<vis[x.first])) {
                        q.push({x.first,x.second+dist});
                        vis[x.first]=dist+x.second;
                    }
                    
                }
                
            }
            
            if(steps++>k) {
                break;
            }
            
        }
        
        return result==INT_MAX?-1:result;
        
    }
};