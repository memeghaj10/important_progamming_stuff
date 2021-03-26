class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        
        int n=A.size();
        int m=B.size();
        
        vector<int> v(26);
        
        for(int i=0;i<m;i++) {
            for(char c='a';c<='z';c++) {
                v[c-'a']=max(v[c-'a'],(int)count(B[i].begin(),B[i].end(),c));
            }
        }
        
        vector<string> ans;
        
        for(int i=0;i<n;i++) {
            int f=0;
            for(char c='a';c<='z';c++) {
                if(count(A[i].begin(),A[i].end(),c)>=v[c-'a']) {
                    continue;
                }
                
                else {
                    f=1;
                    break;
                }
            }
            
            if(!f) {
                ans.push_back(A[i]);
            }
        }
        
        return ans;
        
        
    }
};