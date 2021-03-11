class Solution {
public:
    vector<int> dp;
    
    int func(int amt,vector<int>& coins) {
        if(dp[amt]!=-1) {
            return dp[amt];
        }
        
        int p=INT_MAX-1;
        
        for(int i:coins) {
            if(amt>=i) {
                p=min(p,1+func(amt-i,coins));
            }
        }
        
        return dp[amt]=p;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount==0) {
            return 0;
        }
        
        if((*min_element(coins.begin(),coins.end())>amount)) {
            return -1;
        }
        
        dp=vector<int>(amount+1,-1);
        
        for(int i:coins) {
            if(i<=amount) {
                dp[i]=1;
            }
        }
        
        int x=func(amount,coins);
        
        if(x==INT_MAX-1) {
            return -1;
        }
        
        return x;
    }
};