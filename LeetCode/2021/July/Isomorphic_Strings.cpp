class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char,char> mp;
        map<char,char> rev_mp;
        
        if(s.size()!=t.size()) {
            return 0;
        }
        
        for(int i=0;i<s.size();i++) {
            if(mp.find(s[i])!=mp.end()||rev_mp.find(t[i])!=rev_mp.end()) {
                if(mp[s[i]]!=t[i]||rev_mp[t[i]]!=s[i]) {
                    return 0;
                }
            }
            else {
                mp[s[i]]=t[i];
                rev_mp[t[i]]=s[i];
            }
        }
        
        return 1;
        
    }
};