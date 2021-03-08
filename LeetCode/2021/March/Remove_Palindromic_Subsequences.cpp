class Solution {
public:
    int removePalindromeSub(string s) {
        
        if(s.size()==0) {
            return 0;
        }
        
        string y=s;
        reverse(y.begin(),y.end());
        
        if(y==s) {
            return 1;
        }
        
        return 2;
        
    }
};