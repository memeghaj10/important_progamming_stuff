
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
        
        if(dp.find(state)!=dp.end()) {              //finding if the state has already been calculated
            if(dp[state].find(val)!=dp[state].end()) {
                return dp[state][val];
            }
        }
        
        dp[state][val]=0;   //initialising
        
        for(int i=state.size()-1;i>=0;i--) {
            if(state[i]=='1') {     //out of all the remaning numbers, we select one of them.
                if(val-i-1<=0) {    // if simply after removing this number, we are able to achieve the target, we consider it to be possible
                    return dp[state][val]=1;
                }
                
                else {      //if not possible
                    string tmp=state;
                    tmp[i]='0'; //we calculate a temporary result when we have taken both cases, included the number, and not included the number.
                    dp[state][val]=dp[state][val]||!solver(tmp,val-i-1);
                    if(dp[state][val]) {    // if we get the answer, we return if possible or not.
                        break;
                    }
                }
            }
        }
        
        
        return dp[state][val];  //returing the answer.
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
        
        while(i<mx) {       //we will use this to first indicate that all mx integers are available.
            s+="1";
            i++;
        }
        
        for(int i=0;i<mx;i++) {
            string tmp=s;
            tmp[i]='0';             //calculating result when Player-1 has used the ith number
            if(!solver(tmp,tot-i-1)) {      //if it is not feasible for Player-2 to play, Player-1 wins
                return 1;   
            }
        }
        
        return 0;
        
    }
};