class Solution {
public:
    
    bool canWeMake(long long int row, long long int coinsHave){
        long long int coinsNeeded = (row * (row+1))/2; // here int*int can be greater than int
        return coinsNeeded <= coinsHave;
    }
    
    int arrangeCoins(int n) {
        long long int low{}, high = 65536;
        int res{};
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(canWeMake(mid, n)){
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return res;
    }
};