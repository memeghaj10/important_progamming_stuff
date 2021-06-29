class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
	int ans{}, n = size(nums);
	for(int l{}, r{}; r < n; r++) {
		if(nums[r] == 0)                      // current element is 0 - try to pick it
			if(k == 0)                        // if window already picked k zeros, then pop one from left end & pick current
				while(nums[l++] != 0);       
			else k--;                         // otherwise simply pick it and decrement k
		ans = max(ans, r - l + 1);            // keep updating ans as max window size till now
	}
	return ans;
}
};