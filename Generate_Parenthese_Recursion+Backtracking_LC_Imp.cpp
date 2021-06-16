/*


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8


*/




class Solution {
public:
    
    vector<string> ans;
    
    void solve(string s,int open,int close) {
        
        if(open==0&&close==0) {
            ans.push_back(s);
        }
        if(open>0) {
            solve(s+'(',open-1,close+1);
        }
        if(close>0) {
            solve(s+')',open,close-1);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        string s="";
        
        solve(s,n,0);
        
        return ans;
        
    }
};