class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        vector<int> v;
            
        int y=arr.back();
        
        int i;
        
        for(i=1;i<=y;i++) {
            auto it=lower_bound(arr.begin(),arr.end(),i);           
            if(*it==i) {
                continue;
            }
            
            else {
                
                v.push_back(i);
            }
        }
        
        if(v.size()<k) {
            
            for(i=y+1;v.size()<k;i++) {
                v.push_back(i);
            }
            
        }
     
        
    return v[k-1];
        
    }
};