class NumArray {
    private:
     vector<int> v;
public:
   
    NumArray(vector<int>& nums) {
        v=nums;
    }
    
    int sumRange(int i, int j) {
        int sum=0;
        for(int k=i;k<=j;k++) {
            sum+=v[k];
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */