class Solution {
public:
    unordered_map<string, unordered_map<string, double> > umap;
    vector<double> res;
    unordered_map<string, bool> visited;
    
    double dfs(vector<string> query) {

        if(visited[query[0]])                       return 0.0;
        if(umap.find(query[0]) == umap.end())       return 0.0;

        if(umap[query[0]].find(query[1]) != umap[query[0]].end())  
            return umap[query[0]][query[1]];

        visited[query[0]] = true;
        double temp = 0.0;
        for(auto it: umap[query[0]]){
            temp = dfs({it.first, query[1]});
            temp *= it.second;
            if(temp != 0.0) break;
        }
        visited[query[0]] = false;
        return temp;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, \
                                vector<double>& values, \
                                vector<vector<string>>& queries) {
        auto it2 = values.begin();
        for(auto it: equations) {
            umap[it[0]].insert({it[1], *it2});
            umap[it[1]].insert({it[0], 1.0/(*it2)});
            it2 ++;
        }
        for(auto it: queries) {
            double val = dfs(it);
            res.push_back(val == 0.0 ? -1.0 : val);
        }
        return res;
    }
};