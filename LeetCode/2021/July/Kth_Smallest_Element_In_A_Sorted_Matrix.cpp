class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        
        while(low<high) {
            
            int mid=low+(high-low)/2;
            
            
            int ans=0;
            
            for(int i=0;i<n;i++) {
                ans+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            
            if(ans>=k) {
                high=mid;
            }
            
            else {
                low=mid+1;
            }
            
        }
        
        return high;
        
    }
};