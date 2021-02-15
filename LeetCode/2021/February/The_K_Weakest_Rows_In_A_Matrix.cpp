class Solution {
public:
    
    static bool sort_by_sec(pair<int,int> a, pair<int,int> b) {
        
            if(a.second==b.second) {
                return a.first<b.first;
            }
        
        return a.second<b.second;
        
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
            
            
            vector<int> ans;
        
            vector<pair<int,int>> vp;
            
            for(int i=0;i<mat.size();i++) {
                int y=count(mat[i].begin(),mat[i].end(),1);
                vp.push_back({i,y});
            }
        
            sort(vp.begin(),vp.end(),sort_by_sec);
        
            
            for(int i=0;i<vp.size();i++) {
                if(k>0) {
                    ans.push_back(vp[i].first);
                    k--;
                }
            }
        
            return ans;
        
    }
};