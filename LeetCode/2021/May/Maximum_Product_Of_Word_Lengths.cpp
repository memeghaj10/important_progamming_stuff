class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        vector<int> trans;
        
        int n=words.size();
        
        for(int i=0;i<n;i++) {
            vector<int> r(26,0);
            for(int j=0;j<words[i].size();j++) {
                r[words[i][j]-'a']++;
            }
            
            long long int y=0;
            
            for(int j=0;j<26;j++) {
                if(r[j]) {
                    y+=pow(2,j);
                }
            }
            
            trans.push_back(y);
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if((trans[i]&trans[j])==0) {
                    int temp=words[i].size();
                    temp=temp*words[j].size();
                    ans=max(ans,temp);
                }
            }
            }
        
        return ans;
        
    }
};