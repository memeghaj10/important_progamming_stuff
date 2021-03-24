class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        int n=A.size();
        int m=B.size();
       
        multiset<int> ms;
        vector<int> ans;
        
        for(int i=0;i<n;i++) {
            ms.insert(A[i]);
        }
        
        vector<int> rem;
        
        for(int i=0;i<m;i++) {
            auto it=ms.upper_bound(B[i]);
            if(it==ms.end()) {
                ans.push_back(-1);
                rem.push_back(i);
                continue;
            }
            ans.push_back(*it);
            ms.erase(it);
        }
        
        int j=0;
        
        while(ms.size()) {
            ans[rem[j]]=*ms.begin();
            j++;
            ms.erase(ms.begin());
        }
        
        return ans;
        
    }
};