class Solution {
public:
    
    static bool comp(string a,string b) {
        
        if(a.size()!=b.size()) {
            return a.size()<b.size();
        }
        
        return a<b;
        
    }
   
    
    int longestStrChain(vector<string>& word) {
        
        int n=word.size();
        
        sort(word.begin(),word.end(),comp);
        
        unordered_map<string,int> dp;
        
        int ans=0;
        
        for(int i=0;i<n;i++) {
            
            int m=word[i].size();
            
            int string_ans=1;
            
            for(int j=0;j<m;j++) {
                string h=word[i].substr(0,j)+word[i].substr(j+1,m-j+1);
                if(dp.find(h)!=dp.end()) {
                    string_ans=max(string_ans,1+dp[h]);
                }
            }
            
            dp[word[i]]=string_ans;
            
            ans=max(ans,string_ans);
            
        }
        
        return ans;
        
        
    }
};