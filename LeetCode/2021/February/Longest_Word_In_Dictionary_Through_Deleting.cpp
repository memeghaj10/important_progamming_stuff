class Solution {
public:
    
   
    bool lcs(string a,string b) {
        
        int n=a.size();
        int m=b.size();
        
        int j=0;
        
        for(int i=0;i<n;i++) {
            if(a[i]==b[j]) {
                j++;
            }
        }
        
        
        return j==m;
    }
    
    
    string findLongestWord(string s, vector<string>& d) {     
        
        vector<string> v;
        int ans=0;
        
        for(int i=0;i<d.size();i++) {
            if(lcs(s,d[i])) {
                cout<<d[i]<<" ";
                ans=max(ans,(int)d[i].size());
                v.push_back(d[i]);
            }
        }
        
        if(v.size()==0)  {
            return "";
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++) {
            if(v[i].size()==ans) {
                    return v[i];
            }
        }
        
        return "";
        
    }
};