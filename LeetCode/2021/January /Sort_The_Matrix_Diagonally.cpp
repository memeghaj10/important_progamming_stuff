class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
            int n=mat.size();
            int m=mat[0].size();  
        
        
            for(int i=0;i<n;i++) {
                vector<int> v;
                int di=i,dj=0;
                while(di<n&&dj<m) {
                    v.push_back(mat[di][dj]);
                    di++;
                    dj++;
                }
                sort(v.begin(),v.end());                    
                di=i;
                dj=0;
                int it=0;
                while(di<n&&dj<m) {
                    mat[di][dj]=v[it];
                    it++;
                    di++;
                    dj++;
                }
            }
        
        
              for(int j=1;j<m;j++) {
                vector<int> v;
                int di=0,dj=j;
                while(di<n&&dj<m) {
                    v.push_back(mat[di][dj]);
                     di++;
                     dj++;
                }
                sort(v.begin(),v.end());                    
                di=0;
                dj=j;
                int it=0;
                while(di<n&&dj<m) {
                    mat[di][dj]=v[it];
                    it++;
                    di++;
                    dj++;
                }
            }
            
        
            
            return mat;
    }
};