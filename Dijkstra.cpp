#include<bits/stdc++.h>

using namespace std;


#define INF 03x3f3f3f3f //initialising the INF variable 

typedef pair<int,int> iPair;  // This pair will be used for storing the destination node and the edge weight

void addEdge(vector<pair<int,int>> adj[],int u,int v,int w) 
 {		// utility function to add the adjacency listed nodes of the graphs
 		// we will push_back the pair in the list of both the nodes
 	adj[u].push_back(make_pair(v,wt));
 	adj[v].push_back(make_pair(u,wt));
 }


void shortestPath(vector<pair<int,int>> adj[], int v,int src) 
	 {

	 	priority_queue<iPair,vector<iPair>,greater<iPair>> pq; // initialising a priority queue, which uses the greater vector pair to sort and queue the elements

	 	vector<int> dist(v,INF); // initialsing the distance of all the nodes to INF

	 	pq.push(make_pair(0,src)); // pushing the source element
	 	dist[src]=0; // initalising the distance of the source element to itself as 0

	 	while(!pq.empty()) // while the pq is not empty
	 			{
	 				int u=pq.top().second; // will take out the dest node 
	 				pq.pop();  // and pop out the front element

	 				for(auto x:adj[u]) { // we will now traverse the adj list of the dest node
	 						int v=x.first;
	 						int weight=x.second;

	 						if(dist[v]>dist[u]+weight) { // comparing the distance from source to the INF distance
	 							dist[v]=dist[u]+weight;
	 							pq.push(make_pair(dist[v],v)); // after forming the pair of the updated distance and the weight of the edge we push it back into the pq
	 						}

		 				}

	 			}

	 			cout<<"Vertex Distance from Source"<<endl;  // printing out the shortest distance from the source to the nodes
	 			for(int i=0;i<v;i++) {
	 				cout<<i<<" "<<dist[i]<<endl;
	 			}

	 }


int main() {

int v;

cin>>v; // no. of nodes

vector<iPair> adj[v]; // initialising the adjacency matirx

	addEdge(adj,0,1,4);
 	addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7); 


shortestPath(adj,v,0);// calling the function



return 0;
}