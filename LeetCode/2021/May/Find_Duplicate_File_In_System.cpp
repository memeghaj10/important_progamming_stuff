class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        map<string,vector<string>> mp;
        vector<vector<string>> ans;
        
        
        for(string s:paths) {
            
            string dir="";
            
            int i=0;
            
            while(s[i]!=' ') {
                dir+=s[i++];
            }
            i++;
            while(i<s.size()) {
                string file="";
                
                while(s[i]!='(') {
                    file+=s[i];
                    i++;
                }
                
                if(s[i]=='(') {
                    i++;
                    string key="";
                    while(s[i]!=')') {
                        key+=s[i];
                        i++;
                    }
                    mp[key].push_back(dir+'/'+file);
                }
                i+=2;
            }
            
        }
        
        for(auto x:mp) {
            if(x.second.size()>1) {
                ans.push_back(x.second);
            }
        }
        
        return ans;
    }
};