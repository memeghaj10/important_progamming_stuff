class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mp;
        
        
        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
        }
        
        for(int j=0;j<t.size();j++) {
            if(mp[t[j]]!=count(t.begin(),t.end(),t[j])) {
                return t[j];
            }
        }
        
        
        return 'a';
    }
};