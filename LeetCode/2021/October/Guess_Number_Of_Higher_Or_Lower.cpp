class Solution {
public:
    int guessNumber(int n) {
        for (int lo = 1, hi = n; lo <= hi; ) {
            int mid = lo + (hi - lo)/2, val = guess(mid); 
            if (val == -1) hi = mid - 1; 
            else if (val == 0) return mid; 
            else lo = mid + 1; 
        }
        return -1; 
    }
};