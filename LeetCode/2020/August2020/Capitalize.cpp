class Solution {
public:
    bool detectCapitalUse(string word) {
        int c=0,c1=0,c2=0;
    
        if(word[0]>=65&&word[0]<=90) {
            c=1;
        }
        
        int count=0;
        
        for(int i=1;i<word.size();i++) {
            if(word[i]>=65&&word[i]<=90&&c==0) {
                return false;
            }
            
            else if(word[i]>=65&&word[i]<=90) {
                count++;
            }
        }
        
        if(c==1&&count==word.size()-1) {
            return true;
        }
        
        else if(c==1&&count==0) {
            return true;
        }
        
        else if(c==0&&count==0) {
            return true;
        }
        
        else {
            return false;
        }
    }
};