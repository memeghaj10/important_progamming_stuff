/*

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/



class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        int n=s.size();
        
        vector<vector<string>> result;
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        
        vector<string> curr_list;
        
        dfs(result,s,0,curr_list,dp);
        
        return result;        
    }
    
    void dfs(vector<vector<string>> &result,string &s,int start,vector<string> &curr_list,vector<vector<int>> &dp) {
        
        if(start>=s.size()) {
            result.push_back(curr_list);
        }
        
        for(int end=start;end<s.size();end++) {
            if(s[start]==s[end]&&(end-start<=2||dp[start+1][end-1])) {
                dp[start][end]=1;
                curr_list.push_back(s.substr(start,end-start+1));
                dfs(result,s,end+1,curr_list,dp);
                curr_list.pop_back();
            }
        }
        
    }
};