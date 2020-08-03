/*

For detectting cycle in a directed graph there are many ways, one of which can be by using the concept of
color assignmentto every node.

1. color code - '1' shows that the node is visited but being processed (DFS)

2. color code -'2' shows that the node is visited+processed and no back-track node has been found

3. color code - '0' shows that the node has not been visited and is yet to be traversed

There can be many other ways of detecting a cycle in a graph using DFS(explicitly) as well as BFS

*/


#include<bits/stdc++.h>

using namespace std;

vector<char> color; //declaring a global character vector used for storing the color status of the node

bool dfs(int u,vector<int> adj)  {
	color[u]=1;            // the node has been visited but yet to processed
	for(auto a:adj[u]) {   // checking the adjacency list of the node 
		if(color[a]==0) {  // if the node has not been visited, we 'recurse' the function
			dfs(a,adj);
		}
		else if(color[a]==1) { // if the neighbour node was already traversed, yet appeared again, a cycle is detected
			return true;
		}
	}

	color[u]==2;// the node has been processed+traversed and no cycle has been detected
	return false;
}

bool cycle(int v,vector<int> adj) {
	color.assign(v,0);// initialising all nodes to color code - 0
	for(int i=0;i<v;i++) {
		if(color[i]==0&&dfs(v,adj)) { // if the node is un-traversed, we do its DFS first
			return true;
		}
	}

	return false; //no cycle has been detected for any node 
}

int main() {
	int v,e;

	cin>>v>>e;

	vector<int> adj[v];

	for(int i=0;i<e;i++) { // taking the graph details as input
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b); 
	}

	if(cycle(v,adj)==true) {
		cout<<"Yes the cycle exists, for the graph!"
	}

	else {
		cout<<"No there is no cycle in the graph."
	}

}