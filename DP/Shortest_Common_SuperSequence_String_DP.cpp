/*

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
 

Note:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.



*/


class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int x=n;
        int y=m;
        
        string ans="";
        
        while(x!=0&&y!=0) {
            
            if(s1[x-1]==s2[y-1]) {
                ans+=s1[x-1];
                x--;
                y--;
            }
            
            else {
                
                if(dp[x-1][y]>dp[x][y-1]) {
                    ans+=s1[x-1];
                    x--;
                }
                else {
                    ans+=s2[y-1];
                    y--;
                }                
            }            
        }
        
        
        while(x>=1) {
            ans+=s1[x-1];
            x--;
        }
        
        while(y>=1) {
            ans+=s2[y-1];
            y--;
        }
        
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};