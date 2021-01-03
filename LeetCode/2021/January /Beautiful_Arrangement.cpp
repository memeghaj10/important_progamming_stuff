class Solution {
public:
    int backtrack(vector<bool> &used, int indx, int n) {
        if (indx > n) return 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (i % indx == 0 || indx % i == 0)) {
                used[i] = true;
                cnt += backtrack(used, indx + 1, n);
                used[i] = false;
            }
        }
        return cnt;
    }
    int countArrangement(int n) {
        vector<bool> used(n + 1);
        return backtrack(used, 1, n);
    }
};
