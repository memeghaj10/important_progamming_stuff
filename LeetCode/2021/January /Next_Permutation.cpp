class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int N = nums.size();
        int pivot = -1;
        for(int i = N - 2; i >=0; i--)
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        
        if(pivot == -1) reverse(nums,0);
        else{
            for(int i = N - 1; i >=0; i--){
                if(nums[i] > nums[pivot]){
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
            reverse(nums, pivot+1);
        }
    }
    
private:
    void reverse(vector<int>& nums, int pivot) {
        int l = pivot, r = nums.size() - 1;
        while(l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};