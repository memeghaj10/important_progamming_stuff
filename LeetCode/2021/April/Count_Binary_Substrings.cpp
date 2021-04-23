class Solution {
public:
    int countBinarySubstrings(string s) {
        
        set<int> st_01,st_10;
        
        for(int i=0;i<s.size()-1;i++) {
            if(s[i]=='0'&&s[i+1]=='1') {
                st_01.insert(i);
            }
            else if(s[i]=='1'&&s[i+1]=='0') {
                st_10.insert(i);
            }
        }
        
        int n=s.size();
        
        int c=0;
        
        
        for(auto x:st_01) {
            
            int i=x;
            int j=i+1;
            
            while(i>=0&&j<=n-1&&s[i]=='0'&&s[j]=='1') {
                c++;
                i--;
                j++;
            }
            
        }
        
        for(auto x:st_10) {
            int i=x;
            int j=i+1;
            
            while(i>=0&&j<=n-1&&s[i]=='1'&&s[j]=='0') {
                c++;
                i--;
                j++;
            }
        }
        
        return c;
        
    }
};