class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {        
        
        vector<pair<int,int>> vp;
        
        int n=boxTypes.size();
        
        
        for(int i=0;i<n;i++) {
            vp.push_back(make_pair(boxTypes[i][1],boxTypes[i][0]));
        }
        
        sort(vp.begin(),vp.end());
        
        int ans=0;
        
        for(int i=n-1;i>=0;i--) {
           
            int x=min(truckSize,vp[i].second);
            
            ans+=x*vp[i].first;
            
            truckSize-=x;
            
            if(truckSize<=0) {
                break;
            }
            
        }
        
        return ans;
        
        
    }
};