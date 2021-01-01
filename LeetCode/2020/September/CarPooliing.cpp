class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        map<int,vector<int>> mp;
        
        int start=INT_MAX, end=INT_MIN;
        
        for(int i=0;i<trips.size();i++) {
            start=min(start,trips[i][1]);
            end=max(end,trips[i][2]);
            
            mp[trips[i][1]].push_back(trips[i][0]);
            mp[trips[i][2]].push_back(-1*trips[i][0]);
        }
        
        int f=0;
        
        for(int j=start;j<=end;j++) {
            if(mp[j].size()!=0) {
                int c=0;
                for(int i=0;i<mp[j].size();i++) {
                    c+=mp[j][i];
                }
                
                if(c+f>capacity) {
                    return false;
                }
                
                else {
                    f=f+c;
                }
            }
            
            else {
                continue;
            }
            
        }
        
        return true;
        
        
    }
};