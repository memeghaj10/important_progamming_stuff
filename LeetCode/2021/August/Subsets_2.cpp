class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort elements to get count of same number of elements
        vector<vector<int>> ans = {{}}; // start with empty subset
        for(int i=0;i<nums.size();i++){
            int j = i;
            while(j<nums.size() and nums[i]==nums[j]){
                j++;
            }
            int cnt = j - i;
            int curr_size = ans.size();
            for(int p=0;p<curr_size;p++){
                vector<int> curr = ans[p];
                for(int count=1;count<=cnt;count++){
                    curr.push_back(nums[i]);
                    ans.push_back(curr);
                }
            }
            i = j - 1;
        }
        return ans;
    }
};