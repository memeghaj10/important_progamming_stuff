/*

This is an algorithm to perform a tree traversal, which is easier to implement as compared to that off a graph becasue there is not possibilty of cycles, also it is not possible to reach a node from multiple directions

*/


#include<bits/stdc++.h>

using namespace std;
	

void dfs(vector<int> adj[],int s,int e) { //a simple dfs function to traverese the tree starting from the e^th node(parent node)
	//process node s
	cout<<s; //printing the traversed node

	for(auto u:adj[s]) { //traversing all the untraversed nodes in the adjacency list of the input node
		if(u!=e) {  // leaving the parent node as it is already traversed
			dfs(adj,u,s); //calling the dfs function to process each and every node
		}
	}
}


int main() {

int n;

cin>>n; //enter the number of nodes

vector<int> adj[n]; //initalising the adjacency list for every node

int e;

cin>>e; //enter the number of edges

for(int i=0;i<e;i++) {
	int u,v;

	cin>>u>>v;

	adj[v].push_back(u); //adding the connection in the adjacency list
	adj[u].push_back(v);
}

int x;

cin>>x; //enter the starting node

dfs(adj,x,0); //calling the dfs function


	return 0;
}