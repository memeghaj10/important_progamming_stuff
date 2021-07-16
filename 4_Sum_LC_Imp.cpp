/*

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        map<int,vector<pair<int,int>>> mp;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                mp[nums[i]+nums[j]].push_back(make_pair(i,j));
            }
        }
        
        set<vector<int>> st;
        
        for(int i=0;i<n;i++) {
            vector<int> v;
            for(int j=i+1;j<n;j++) {
                int sum=nums[i]+nums[j];
                int x=target-sum;
                
                if(mp.find(x)!=mp.end()) {
                    
                    vector<pair<int,int>> p=mp[x];
                    
                    for(int k=0;k<p.size();k++) {
                        pair<int,int> p1=p[k];
                        
                        if(i!=p1.first&&i!=p1.second&&j!=p1.first&&j!=p1.second) {
                            v={nums[i],nums[j],nums[p1.first],nums[p1.second]};
                        }
                        
                        else {
                            continue;
                        }
                        
                        if(v.empty()) {
                            continue;
                        }
                        
                        sort(v.begin(),v.end());
                        st.insert(v);
                        v.clear();
                        
                    }
                    
                }
                
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto x:st) {
            ans.push_back(x);
        }
        
        return ans;
        
    }
};