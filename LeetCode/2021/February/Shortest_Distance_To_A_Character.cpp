class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        vector<int> v;
        
        for(int i=0;i<s.size();i++) {
            if(s[i]==c) {
                v.push_back(i);
            }
        }
        
        int n=s.size();
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++) {
            int y=INT_MAX;
            for(int j=0;j<v.size();j++) {
                y=min(y,abs(i-v[j]));
            }
            ans[i]=y;
        }
        
        
        return ans;      
        
    }
};