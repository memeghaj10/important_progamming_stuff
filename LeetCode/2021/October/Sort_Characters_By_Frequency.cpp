class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int> mp;
        
        vector<pair<int,char>> vp;
        
        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
        }
        
        for(auto x:mp) {
            vp.push_back(make_pair(x.second,x.first));
        }
        
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        
        string ans="";
        
        for(auto x:vp) {
            while(x.first--) {
                ans+=x.second;
            }
        }
        
        return ans;
        
    }
};