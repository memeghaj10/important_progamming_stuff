class Solution {
public:
    string originalDigits(string s) {
        
        int n=s.size();
        string ans="";
        
        map<char,int> mp;
        for(int i=0;i<n;i++) {
            mp[s[i]]++;
        }
        
        int z=0;
        z=mp['z'];
        
        int p=z;
        mp['z']-=p;
        mp['e']-=p;
        mp['o']-=p;
        mp['r']-=p;
        while(p--) {
            ans+=to_string(0);
        }
        
        int w=mp['w'];
        p=w;
        mp['t']-=p;
        mp['w']-=p;
        mp['o']-=p;
        while(p--) {
            ans+=to_string(2);
        }
        
        
        int g=mp['g'];
        p=g;
        mp['e']-=p;
        mp['i']-=p;
        mp['g']-=p;
        mp['h']-=p;
        mp['t']-=p;
        while(p--) {
            ans+=to_string(8);
        } 
        
        int x=mp['x'];
        p=x;
        mp['s']-=p;
        mp['i']-=p;
        mp['x']-=p;
        while(p--){
            ans+=to_string(6);
        }
        
        int u=mp['u'];
        p=u;
        mp['f']-=p;
        mp['o']-=p;
        mp['u']-=p;
        mp['r']-=p;
        while(p--) {
            ans+=to_string(4);
        }
        
        int o=mp['o'];
        p=o;
        mp['o']-=p;
        mp['n']-=p;
        mp['e']-=p;
        while(p--) {
            ans+=to_string(1);
        }
        
        int h=mp['h'];
        p=h;
        mp['t']-=p;
        mp['h']-=p;
        mp['r']-=p;
        mp['e']-=2*p;
        while(p--) {
            ans+=to_string(3);
        }
        
        int f=mp['f'];
        p=f;
        mp['f']-=p;
        mp['i']-=p;
        mp['v']-=p;
        mp['e']-=p;
        while(p--) {
            ans+=to_string(5);
        }
        
        int v=mp['v'];
        p=v;
        mp['s']-=p;
        mp['e']-=2*p;
        mp['v']-=p;
        mp['n']-=p;
        while(p--) {
            ans+=to_string(7);
        }
        
        int i=mp['i'];
        p=i;
        mp['n']-=2*p;
        mp['i']-=p;
        mp['e']-=p;
        while(p--) {
            ans+=to_string(9);
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};