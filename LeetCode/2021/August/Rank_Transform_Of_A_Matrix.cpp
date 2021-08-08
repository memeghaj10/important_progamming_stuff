class Solution {
public:
    int find_set(int x,vector<int>& parent){
        if(parent[x]==x)
            return x;
        return parent[x] = find_set(parent[x],parent);
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        map<int,vector<pair<int,int>>> ele;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                ele[mat[i][j]].push_back({i,j}); // put same value element in same vector
        }
        
        vector<int> rank(n+m,0); // rank of rows and columns
        for(auto itr:ele){
            vector<int> parent(n+m,0); // parent vector
            for(int i=0;i<parent.size();i++)
                parent[i] = i;
            for(auto it:itr.second){
                int i = it.first,j = it.second;
                int xroot = find_set(i,parent),yroot = find_set(j+n,parent); // find parent's
                parent[xroot] = yroot; // union, make row point to same column
                rank[yroot] = max(rank[xroot],rank[yroot]); // find maximum rank over this connected component
            }
            vector<int> curr = rank;
            // assign each cell, correct rank
            for(auto it:itr.second){
                int i = it.first,j = it.second;
                int r = find_set(i,parent);
                ans[i][j] = 1 + rank[r];
                curr[i] = rank[r] + 1;
                curr[j+n] = rank[r] + 1;
            }
            swap(rank,curr);
        }
        return ans;
    }
};