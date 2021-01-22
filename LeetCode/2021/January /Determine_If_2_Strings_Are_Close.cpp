class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        
        if(n!=m) {
            return 0;
        }
        
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        
        if(word1==word2) {
            return 1;
        }
        
        vector<int> v1(26,0),v2(26,0);
        
        for(char c:word1) {
            v1[c-'a']++;
        }
        
        for(char c:word2) {
            v2[c-'a']++;
        }
     
        for(int i=0;i<26;i++) {
            if((!v1[i]&&v2[i])||(v1[i]&&!v2[i])) {
                return 0;
            }
        }
              
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return v1==v2;
        
    }
};