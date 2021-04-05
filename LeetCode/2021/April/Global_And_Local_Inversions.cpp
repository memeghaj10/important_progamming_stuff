class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        
        int n=A.size();
        
        set<int> st;
        int local=0;
        int global=0;
        
        for(int i=0;i<n-1;i++) {
            if(A[i]>A[i+1]) {
                local++;
            }
        }
        
        st.insert(A[n-1]);
        
        for(int i=n-2;i>=0;i--) {
            global+=distance(st.begin(),st.lower_bound(A[i]));
            st.insert(A[i]);
        }
        
        
        return global==local;
    }
};