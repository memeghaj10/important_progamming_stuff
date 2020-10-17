class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
            vector<string> ans;
        

            if(s.size()<10) {
                return ans;
            }
     
              map<string,int> mp;
        
            for(int i=0;i<s.length()-9;i++) {
                string p = s.substr(i,10);
               mp[p]++;
            }
        
        
        for(auto x:mp) {
            if(x.second>1) {
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};