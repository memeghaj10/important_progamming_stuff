class Solution {
public:
    string customSortString(string order, string str) {
        
        map<char,int> mp;
        
        int n=str.size();
        
        for(int i=0;i<n;i++) {
            mp[str[i]]++;
        }
        
        
        
        string ans="";
        
        for(int i=0;i<order.size();i++) {
            while(mp[order[i]]>0) {
                ans+=order[i];
                mp[order[i]]--;
            }
        }
        
        for(auto x:mp) {
          
            while(x.second--) {
                ans+=x.first;
            }
            
        }
        
        return ans;
    }
};