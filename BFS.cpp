#include<bits/stdc++.h>

using namespace std;

void bfs(int s, vector<int> adj[],bool vis[],int n) {

	queue<int> q; //initialising a queue for strong the nodes remaining to be traversed

	int distance[n];// an array for storing the distance of each node from the source node

	vis[s]=true; // giving the 'traversed' status to the traversed node

	distance[s]=0; // giving the distance of the source node to itself

	q.push(s);// pushing the source node to itself

	while(!q.empty()) { // processing till all the nodes have been traversed and queue is not empty
		int s=q.front();// taking out the front node out of the queue
		q.pop();
		cout<<s<<" ";// printting the node as, it's the one having the shortest distance among the remaning others
		for(auto u:adj[s]) {// traversing through the adjacency list of the node
			if(vis[u]) {
				continue;//if the nieghbour node has been processde then no need to process it again
			}
			vis[u]=true;// else we traverse it
			distance[u]=distance[s]+1;// then we update the distance of the node
			q.push(u);// then we push the node back to the queue
		}
	}// the loop continues till the queue has no elements remaining

}

int main() {


int n,e;

cin>>n>>e; //taking the no. of nodes and edges as input

vector<int> adj[n]; // initialsing the array of vectors for storing the neighbours of the nodes


bool vis[n]={false};// boolean array for storing the visited status

for(int i=0;i<e;i++) {
	int u,v;
	cin>>u>>v;
	adj[u].push_back(v); // Being a directed graph we just store the destination node in the list of the origin node

}


bfs(0,adj,vis,n); // calling the bfs function

cout<<endl;



	return 0;
}