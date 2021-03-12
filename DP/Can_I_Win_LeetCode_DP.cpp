
/*

In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise return false. Assume both players play optimally.


*/



class Solution {
public:
    
    unordered_map<string,unordered_map<int,bool>> dp;

    bool solver(string state, int val) {
        
        if(dp.find(state)!=dp.end()) {
            if(dp[state].find(val)!=dp[state].end()) {
                return dp[state][val];
            }
        }
        
        dp[state][val]=0;
        
        for(int i=state.size()-1;i>=0;i--) {
            if(state[i]=='1') {
                if(val-i-1<=0) {
                    return dp[state][val]=1;
                }
                
                else {
                    string tmp=state;
                    tmp[i]='0';
                    dp[state][val]=dp[state][val]||!solver(tmp,val-i-1);
                    if(dp[state][val]) {
                        break;
                    }
                }
            }
        }
        
        
        return dp[state][val];
    }
    
    bool canIWin(int mx, int tot) {
            
        if(tot<=mx) {
            return 1;
        }
        
        if(tot>(mx*(mx+1))/2) {
            return 0;
        }
        
        int i=0;
        string s="";
        
        while(i<mx) {
            s+="1";
            i++;
        }
        
        for(int i=0;i<mx;i++) {
            string tmp=s;
            tmp[i]='0';
            if(!solver(tmp,tot-i-1)) {
                return 1;
            }
        }
        
        return 0;
        
    }
};