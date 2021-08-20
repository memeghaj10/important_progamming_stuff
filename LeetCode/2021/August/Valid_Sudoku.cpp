class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        
        for(int i=0;i<n;i++) {
            for(char c='1';c<='9';c++) {
                if(count(matrix[i].begin(),matrix[i].end(),c)>1) {
                    return 0;
                }
            }
        }
        
        for(int j=0;j<m;j++) {
            map<char,int> mp;
            
            for(int i=0;i<n;i++) {
                mp[matrix[i][j]]++;
            }
            
            for(char c='1';c<='9';c++) {
                if(mp[c]>1) {
                    return 0;
                }
            }
        }
        
        for(int i=0;i<n;i+=3) {
        int i1=i+2;

        for(int j=0;j<m;j+=3) {
            int j1=j+2;

            map<char,int> mp;

            for(int k=i;k<=i1;k++) {
                for(int k1=j;k1<=j1;k1++) {
                    mp[matrix[k][k1]]++;
                }
            }

            for(char c='1';c<='9';c++) {
                if(mp[c]>1) {
                    return 0;
                }
            }

        }
    }

        
        return 1;
        
    }
};