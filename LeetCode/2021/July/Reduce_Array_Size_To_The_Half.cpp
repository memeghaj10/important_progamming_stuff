class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int> mp;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        
        vector<pair<int,int>> vp;
        
        for(auto x:mp) {
            vp.push_back(make_pair(x.second,x.first));
        }
        
        sort(vp.begin(),vp.end());
        
        int x=n/2;
        int c=0;
        int f=0;
        
        for(int i=vp.size()-1;i>=0;i--) {
            if(c<x) {
                c+=vp[i].first;
                f++;
            }
            else {
                break;
            }
        }
        
        return f;
        
    }
};