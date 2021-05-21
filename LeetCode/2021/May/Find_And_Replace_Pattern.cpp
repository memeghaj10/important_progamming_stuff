class Solution {
public:
    
    bool match(string pattern,string s) {
        
        if(pattern.size()!=s.size()) {
            return 0;
        }
        
        int n=s.size();
        
        map<char,char> mp;
        set<char> st;
        //map<char,char> mp1;
        
        for(int i=0;i<n;i++) {
            if(mp.find(pattern[i])==mp.end()) {
                if(st.find(s[i])==st.end()) {
                    mp[pattern[i]]=s[i];
                    st.insert(s[i]);
                }
                else {
                    return 0;
                }
            }
            
            else {
                if(mp[pattern[i]]!=s[i]) {
                    return 0;
                }
            }
        }
        
        return 1;
    }
    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        int n=words.size();
        
        for(int i=0;i<n;i++) {
            if(match(pattern,words[i])) {
                ans.push_back(words[i]);
            }
        }
        
        return ans;        
    }
};