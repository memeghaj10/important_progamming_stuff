class Solution {
public:
    
    vector<int> v;
    vector<int> origs;
    
    Solution(vector<int>& nums) {
        v=nums;
        origs=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origs;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n=v.size();
        
        for(int i=0;i<n;i++) {
            int x=rand()%n;
            swap(v[i],v[x]);
        }
        
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */