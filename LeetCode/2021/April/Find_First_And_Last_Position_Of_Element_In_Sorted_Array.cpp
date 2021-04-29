class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size()==0) {
            vector<int> v;
            v.push_back(-1);
            v.push_back(-1);
            
            return v;
        }
        
        auto it=lower_bound(nums.begin(),nums.end(),target);
        
         vector<int> v;
        
        if(it==nums.end()||(*it)!=target) {           
            v.push_back(-1);
            v.push_back(-1);
            
            return v;
        }
        
        else {
            v.push_back(it-nums.begin());
        }
        
        it=upper_bound(nums.begin(),nums.end(),target);
        
        it--;
        
        if(*it==target) {
            v.push_back(it-nums.begin());
        }
        
        else {
            v.push_back(-1);
        }
        
        return v;
    }
};