class Solution {
public:
    	int solve(vector<int>&nums,int l,int r){
		if(l==r-1||l==r)
			return min(nums[l],nums[r]);

		int mid = l+(r-l)/2; // finding middle
		
		return min(solve(nums,l,mid),solve(nums,mid,r)); //return min element in both side;
	}
    int findMin(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);   
    }
};