class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        string rev="";
        
        for(char c:s) {
            if(c>='a'&&c<='z') {
                rev+=c;
            }
            else if(c>='A'&&c<='Z') {
                rev+=c;
            }
        }
        
        reverse(rev.begin(),rev.end());
        
        int x=0;
        
        for(int i=0;i<s.size();i++) {
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z') {
                s[i]=rev[x];
                x++;
            }
        }
        
        return s;
        
    }
};