/*

Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.

 

Example 1:

Input: stones = [5,3,1,4,2]
Output: 6
Explanation: 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.


*/



class Solution {
public:
    
    int dp[1002][1002][2];
    
    
    int solve(int l,int r,int sum,int x,vector<int>& v) {
        
        if(l==r) {
            return 0;
        }
        
        else if(dp[l][r][x]!=-1) {
            return dp[l][r][x];
        }
        
        else if(x==0) {
            return dp[l][r][x]=max(sum-v[l]+solve(l+1,r,sum-v[l],1,v),sum-v[r]+solve(l,r-1,sum-v[r],1,v));
        }
        
        return dp[l][r][x]=min(-1*(sum-v[l])+solve(l+1,r,sum-v[l],0,v),-1*(sum-v[r])+solve(l,r-1,sum-v[r],0,v));
        
    }
    
    int stoneGameVII(vector<int>& stones) {
        
        int n=stones.size();
        
        memset(dp,-1,sizeof(dp));
        
        int sum=accumulate(stones.begin(),stones.end(),0);
        
        return solve(0,n-1,sum,0,stones);
        
    }
};