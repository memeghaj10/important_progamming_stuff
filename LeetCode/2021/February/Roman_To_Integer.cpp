class Solution {
public:
    int romanToInt(string s) {
        
        int ans=0;
        
        int n=s.size();
        
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        for(int i=n-1;i>=1;i--) {
            if(mp[s[i]]<=mp[s[i-1]]) {
                ans+=mp[s[i]];
                s[i]='*';
            }
            
            else {
                ans+=mp[s[i]];
                s[i]='*';
                ans-=mp[s[i-1]];
                s[i-1]='*';
                i--;
            }
        }
        
        
        if(s[0]!='*') {
            ans+=mp[s[0]];
        }
        
        
        return ans;
        
    }
};