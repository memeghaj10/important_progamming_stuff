class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int n=text.size();
        
        map<char,int> mp;
        
        for(auto c:text) {
            mp[c]++;
        }
        
        int y=INT_MAX;
        
        y=min(y,mp['b']);
        y=min(y,mp['a']);
        y=min(y,mp['l']/2);
        y=min(y,mp['o']/2);
        y=min(y,mp['n']);
        
        
        return y;
        
    }
};