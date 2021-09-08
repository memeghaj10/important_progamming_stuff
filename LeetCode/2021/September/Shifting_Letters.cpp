class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        int n=shifts.size();
        
        vector<long long int> suffix(n);
        
        suffix[n-1]=shifts[n-1];
        
        for(int i=n-2;i>=0;i--) {
            suffix[i]=suffix[i+1]+shifts[i];
        }
        
        for(int i=0;i<n;i++) {
            long long int x=s[i]-'a'+suffix[i];
            x=x%26;
            s[i]='a'+x;
        }
        
        return s;
        
    }
};