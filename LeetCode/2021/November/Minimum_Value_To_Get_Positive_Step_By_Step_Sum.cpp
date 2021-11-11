class Solution {
public:
    int minStartValue(vector<int>& A) {
        int ans = 0, sum = 0;
        for(auto el : A)
            sum += el, ans = min(ans, sum);
        return -ans+1;
    }
};