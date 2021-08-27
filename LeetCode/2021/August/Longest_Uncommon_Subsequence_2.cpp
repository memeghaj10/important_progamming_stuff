class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int> m;
        for (auto& s: strs) 
        {
            for (int i = 0; i < (1 << s.size()); i++) {
                string t;
                for (int j = 0; j < s.size(); j++) 
                {
                    if ((i >> j) & 1) 
                        t += s[j];
                }
                m[t]++ ;
            }
        }
        int ans = -1 ;
        for (auto& a: m) {
            if (a.second == 1) 
                ans = max(ans , (int)a.first.size()) ;
        }
        return ans ;
    }
};