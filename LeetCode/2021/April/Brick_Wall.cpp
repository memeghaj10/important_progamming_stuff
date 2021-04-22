class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
       int n=wall.size();
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++) {
                
                int c=0;            
               
                for(int j=0;j<wall[i].size()-1;j++) {
                    c+=wall[i][j];
                    mp[c]++;
                }
            
        }
        
        int mx=0;
        
        for(auto x:mp) {
            mx=max(mx,x.second);
        }
        
        return n-mx;
        
    }
};