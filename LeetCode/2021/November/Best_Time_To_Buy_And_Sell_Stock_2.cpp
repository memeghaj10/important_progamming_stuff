class Solution {
public:
    int maxProfit(vector<int>& P) {
        int n = size(P), i = 1, profit = 0, buy, sell;
        while(i < n) {
            // find lowest price to buy - local valley 📉
            for(buy = P[i-1]; i < n && P[i] < buy; i++) 
                buy = P[i];    
            if(i >= n) break;      // break if no more days remaining
            // find highest price to sell - local peak  📈 
            for(sell = P[i]; i < n && sell < P[i]; i++)
                sell = P[i];    
            profit += sell - buy; // keep adding the 💸
            i++;
        }
        return profit;
    }
};