#include<bits/stdc++.h>

using namespace std;


void dfs(int s, vector<int> g[],bool vis[]) {
	vis[s]=true; //node has been traversed, hence initialised to be TRUE
	cout<<s<<" ";// printing the traversed node

	for(int i=0;i<g[s].size();i++) {  // now, traversing the untraversed neighbours of the node
		if(vis[g[s][i]]==false) {
			dfs(g[s][i],g,vis);
		}
	}
}

int main() {

int n,e;

cin>>n>>e;

vector<int> g[n]; //array of vectors for storing the edges and connection details of the nodes

bool vis[n]; // to check if the node has been visited during the traversal or not

memset(vis,false,sizeof(vis)); // initialising all the elements of the boolean array to be false 

for(int i=0;i<e;i++) {  // storing the given connections of nodes and edges in the array of vectors
	int u,v;
	cin>>u>>v;
	g[u].push_back(v);
	g[v].push_back(u);
}

dfs(0,g,vis);  ///DFS fucntion start here

	return 0;
}