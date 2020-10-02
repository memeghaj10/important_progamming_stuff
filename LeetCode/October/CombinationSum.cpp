class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // dp vector holds the combination sum count of numbers from 1 to target
        vector<int>dp(target+1,0);
        dp[0] = 1;

        // combination track 3D vector holds the combination sum vectors of nums from 1 to target
        vector<vector<vector<int>>>result(target+1,vector<vector<int>>(1,vector<int>(0)));

        // Loop through candidates
        for(int c:candidates)
        {
            // calculate the contribution of candidates in the range candidates to target
            for(int i=c;i<=target;i++)
            {
                // combination sum count for number i
                dp[i] += dp[i-c];

                // If combination sum possible for number i and c  
                if(dp[i-c]>=1)
                {
                    // get all combination sum vector from number i-c  and add to number i's combination sum vector 
                    result[i].insert(result[i].end(),result[i-c].end()-dp[i-c],result[i-c].end());

                    // add current candidate in to newly added combination sum vector
                    for(int j=0;j<dp[i-c];j++)
                        result[i][result[i].size()-1-j].push_back(c);
                }
            }
        }
        
        // remove blank vector at front
        result[target].erase(result[target].begin());
        return result[target];
    }
};
