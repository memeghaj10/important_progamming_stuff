class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
                
        int n=digits.size();
        
        map<char,string> mp;
        
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        vector<string> v;
        
        for(int i=0;i<n;i++) {
            if(v.size()==0) {
                string h=mp[digits[i]];
                for(int j=0;j<h.size();j++) {
                    string r="";
                    r+=h[j];
                    v.push_back(r);
                }
            }
            
            else {
                
                    string h=mp[digits[i]];
                    vector<string> ans;
                    for(int j=0;j<v.size();j++) {
                        for(int k=0;k<h.size();k++) {
                        ans.push_back(v[j]+h[k]);
                        }
                    }
                v=ans;
                
            }
            
        }
        
        return v;
        
    }
};