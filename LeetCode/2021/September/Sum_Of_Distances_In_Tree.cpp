class Solution {
public:
	vector<vector<int>> tree;
	map<pair<int,int>,int> m;
	map<pair<int,int>,int> under;

	pair<int,int> getDfs(int i,int p) {

		int ans=0,c=1;
		for(int j: tree[i]) {
			if(j==p) continue;
			if(m.find({i,j})==m.end()) {
				auto p= getDfs(j,i);
				m[{i,j}]=p.first;
				under[{i,j}]=p.second;
			}
			ans+= m[{i,j}]+under[{i,j}];
			c+=under[{i,j}];
		}
		return {ans,c};
	}

	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		m.clear();
		under.clear();

		tree.resize(n);
		vector<int> ans;
		for(auto i: edges) {
			tree[i[0]].push_back(i[1]);
			tree[i[1]].push_back(i[0]);
		}

		for(int i=0;i<n;i++) {
			ans.push_back(getDfs(i,-1).first);
		}
		return ans;
	}
};